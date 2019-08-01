#include "filei.h"
#include "fileo.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
		int fd;
		char c;
		t_filei_info infoi;
		t_fileo_info infoo;

		fd = open(argv[1], O_RDONLY);
		init_filei_info(&infoi, fd);
		init_fileo_info(&infoo, 1);
		while((c = get_next_char(&infoi)) != EOF)
				write_char(c, &infoo);
		write_char(c,&infoo);
		flush_fileo_info(&infoo);
		destroy_filei_info(&infoi);
		destroy_fileo_info(&infoo);	
		close (fd);
		return (0);
}
