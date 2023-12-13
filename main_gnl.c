// #include "get_next_line.h"

// int	main(void)
// {
// 	int		fd;
// 	char	*tab;

// 	// fd = 0;
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 		return 1;
// 	tab = get_next_line(fd);
// 	while (tab)
// 	{
// 		printf("--->%s", tab);
// 		free(tab);
// 		tab = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }

// // // ----------BONUS------------------
// #include "get_next_line_bonus.h"


// int	main(void)
// {
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;
// 	int		i;

// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	fd3 = open("test3.txt", O_RDONLY);
// 	i = 1;
// 	while (line1 || line2 || line3)
// 	{
// 		line1 = get_next_line(fd1);
// 		printf("line [%d]: %s", i, line1);
// 		free(line1);
// 		line2 = get_next_line(fd2);
// 		printf("line [%d]: %s", i, line2);
// 		free(line2);
// 		line3 = get_next_line(fd3);
// 		printf("line [%d]: %s", i, line3);
// 		free(line3);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;

// 	int		i;

// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	fd3 = open("test3.txt", O_RDONLY);
// 	i = 1;
	
// 	line1 = get_next_line(fd1);
// 	line2 = get_next_line(fd2);
// 	line3 = get_next_line(fd3);

// 	while (line1 || line2 || line3)
// 	{
// 		printf("file 1: %s", line1);
// 		free(line1);
// 		line1 = get_next_line(fd1);

// 		printf("file 2: %s", line2);
// 		free(line2);
// 		line2 = get_next_line(fd2);

// 		printf("file 3: %s", line3);
// 		free(line3);
// 		line3 = get_next_line(fd3);
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }
