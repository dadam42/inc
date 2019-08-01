#ifndef FILEI_H
# define FILEI_H
# include "buffer.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define FILEI_OK			0
# define FILEI_ERR_NOMORE_RECORD	1
# define FILEI_ERR_NOMORE_BUFFER	2

# define FILEI_RECORD_SIZE		16
# define FILEI_FILE_BUFFER_SIZE		4096 + 1

typedef struct	s_filei_info 
{
	int	fd;
	char	*buffer;
	char	*reader;
}		t_filei_info;

char	get_next_char(t_filei_info *info);
int	init_filei_info(t_filei_info *info, int fd);
void	destroy_filei_info(t_filei_info *info);
#endif
