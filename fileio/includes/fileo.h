#ifndef FILEO_H
# define FILEO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "buffer.h"

# define FILEO_ERR_OK				0
# define FILEO_ERR_NOMORE_BUFFER	2

# define FILEO_BUFFER_SIZE			4096 + 1

typedef struct s_fileo_info
{
		int fd;
		char *buffer;
		char *writer;
}				t_fileo_info;

int		init_fileo_info(t_fileo_info *info, int fd);
void	destroy_fileo_info(t_fileo_info *info);
void	flush_fileo_info(t_fileo_info *info);
void	write_char(char c, t_fileo_info *info);
#endif
