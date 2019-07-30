#include "buffer.h"

void fill_buffer_with(void *buf, void *model, unsigned int elt_size, unsigned int elt_count)
{
	unsigned int sdx;
	unsigned int cdx;
	unsigned char *mod_cur;
	unsigned char *buf_cur;

	buf_cur = buf;
	cdx = 0;
	while (cdx++ < elt_count)
	{
		mod_cur = model;
		sdx = 0;
		while (sdx++ < elt_size)
			*buf_cur++ = *mod_cur++;
	}
}

void clear_buffer(void *buf, unsigned int elt_size, unsigned int elt_count)
{
	unsigned int model[elt_size];
	unsigned int idx;

	idx = 0;
	while (idx < elt_size)
		model[idx++] = 0;
	fill_buffer_with(buf, &model, elt_size, elt_count);
}

void copy_buffer(void *dest, void *src, unsigned int elt_size, unsigned int elt_count)
{
	unsigned int sdx;
	unsigned int cdx;
	unsigned char *dest_cur;

	cdx = 0;
	dest_cur = dest;
	while (cdx++ < elt_count)
	{
		sdx = 0;
		while (sdx++ < elt_size)
			*dest_cur++ = *(unsigned char*)src++;
	}
}

void *build_larger_buffer(void *buf, unsigned int elt_size, unsigned int ocount,unsigned int ncount)
{
	void *ret;
	
	if (!buf && ocount > 0)
		return (NULL);
	if (!(ret = malloc(elt_size * ncount * sizeof(char))))
		return (NULL);
	copy_buffer(ret, buf, elt_size, ocount);
	return (ret);
}

