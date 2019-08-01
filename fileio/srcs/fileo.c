#include "fileo.h"

inline int		init_fileo_info(t_fileo_info *info, int fd)
{
	if (!(info->buffer = malloc(FILEO_BUFFER_SIZE * sizeof(char))))
			return (FILEO_ERR_NOMORE_BUFFER);
	info->fd = fd;
	*(info->buffer + FILEO_BUFFER_SIZE - 1) = EOF;
	info->writer = info->buffer - 1;
	return (FILEO_ERR_OK);
}

void			write_char(char c, t_fileo_info *info)
{
		info->writer++;
		if (*(info->writer) == EOF || c == EOF)
		{
			write(info->fd, info->buffer, info->writer - info->buffer);
			info->writer = info->buffer;
		}
		*(info->writer) = c;
}

void flush_fileo_info(t_fileo_info *info)
{
		write(info->fd, info->buffer, info->writer - info->buffer);
		info->writer = info->buffer - 1;
}

void	destroy_fileo_info(t_fileo_info *info)
{
		free(info->buffer);
}
