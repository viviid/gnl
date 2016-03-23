#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		ret;
	int		git;
	char	*line;

	git = 6;
	if (argc < 1)
		return (0);
	line = (char *)malloc(sizeof(char) * BUFF_SIZE);
	fd =  open(argv[1], O_RDONLY);
//	fd2 = open(argv[2], O_RDONLY);
//	while (git > 0)
//	{
//		if (git % 2 == 0)
//			ret = get_next_line(fd2, &line);
//		else
		while ((ret = get_next_line(fd, &line)) > 0)
			printf("%d %s\n",ret, line);
//		git = git - 1;
//	}
	return (0);
}
