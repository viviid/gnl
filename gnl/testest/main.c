#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*line;

	if (argc < 1)
		return (0);
	line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
			printf("%s\n", line);
	return (0);
}
