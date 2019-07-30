#include "buffer.h"

void shiftl_buffer(void *buf, unsigned int elt_size, unsigned int elt_count, unsigned int count)
{
	unsigned char *src;
	unsigned int cdx;
	unsigned int sdx;

	src = buf + elt_size * count;
	cdx = 0;
	while (cdx++ < elt_count - count)
	{
		sdx = 0;
		while (sdx++ < elt_size)
			*(unsigned char*)buf++ = *src++;

	}
}

void shiftr_buffer(void *buf, unsigned int elt_size, unsigned int elt_count, unsigned int count)
{
	unsigned char	*dest;
	unsigned int	cdx;
	unsigned int	sdx;

	dest = buf + elt_size * elt_count;
	buf = buf + elt_size * (elt_count - count);
	cdx = 0;
	while (cdx++ <= elt_count - count)
	{
		sdx = 0;
		while (sdx++ < elt_size)
			*dest--=*(unsigned char*)buf--;
	}
}

void roll_buffer(void *buf, unsigned int elt_size, unsigned int elt_count, unsigned int count)
{
	unsigned char buffer[elt_size * count];

	copy_buffer(buffer, buf, elt_size, count);
	shiftl_buffer(buf, elt_size, elt_count, count);
	copy_buffer(buf + elt_size * (elt_count - count), buffer, elt_size, count); 
}

void rolr_buffer(void *buf, unsigned int elt_size, unsigned int elt_count, unsigned int count)
{
	unsigned char buffer[elt_size * count];

	copy_buffer(buffer, buf + elt_size * (elt_count - count), elt_size, count);
	shiftr_buffer(buf, elt_size, elt_count, count);
	copy_buffer(buf, buffer, elt_size, count);
}

void	insert_buffer(void *buf, unsigned int elt_size, unsigned int elt_count, void *ins, unsigned int ins_count, unsigned int pos)
{
	if (pos > elt_count - ins_count)
		return;
	shiftr_buffer(buf + pos * elt_size, elt_size, elt_count - pos, ins_count);
	copy_buffer(buf+pos * elt_size, ins, elt_size, ins_count);
}

