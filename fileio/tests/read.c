#include "fileo.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
		int fd;
		t_fileo_info info;

		fd = open(argv[1], O_RDONLY);
		init_fileo_info(&info, fd);
		while(get_next_char(&info) != EOF)
				;
		return (0);
}
