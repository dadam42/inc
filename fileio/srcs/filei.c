#include "filei.h"

inline char get_next_char(t_filei_info *info)
{
		int count;

		info->reader++;
		if (*(info->reader) == EOF)
		{
				if (info->reader - info->buffer == FILEI_FILE_BUFFER_SIZE - 1)
				{
						count = read(info->fd, info->buffer, FILEI_FILE_BUFFER_SIZE - 1);
						*(info->buffer + count) = EOF;
						info->reader = info->buffer - 1;
						return get_next_char(info);	
				}
				info->reader--;
				return (EOF);
		}
		return (*(info->reader));
}

int		init_filei_info(t_filei_info *info, int fd)
{
		if (!(info->buffer = malloc(FILEI_FILE_BUFFER_SIZE * sizeof(char))))
				return FILEI_ERR_NOMORE_BUFFER;
		info->fd = fd;
		info->reader = info->buffer + FILEI_FILE_BUFFER_SIZE - 2;
		*(info->reader + 1) = EOF;
		return (FILEI_OK);
}

void	destroy_filei_info(t_filei_info *info)
{
		free(info->buffer);
}
