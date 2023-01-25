#include "get_next_line.h"

char *start_read(int fd, char **remaining_data, char **next_line)
{
	char *old_next_line;
	char *tmp;
	int read_val;

	if (*remaining_data != 0x0 && ft_strlen(*remaining_data) && ft_strchr(*remaining_data, '\n') != -1)
		return (ft_substr(*remaining_data, 0, ft_strchr(*remaining_data, '\n')));

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while (1)
	{
		read_val = read(fd, tmp, BUFFER_SIZE);
		if (read_val < 0)
		{
			free(tmp);
			return (NULL);
		}
		if (read_val == 0)
			break;
		old_next_line = *next_line;
		*next_line = ft_strjoin(*next_line, tmp);
		free(old_next_line);
		// printf("|%s|/n", *next_line);
		if (ft_strchr(*next_line, '\n') != -1)
		{
			// puts("find");
			free(tmp);
			*remaining_data = ft_substr(*next_line, ft_strchr(*next_line, '\n'), ft_strlen(*next_line));
			return (ft_substr(*next_line, 0, ft_strchr(*next_line, '\n')));
		}
	}
	free(tmp);
	// printf("%lu\n", ft_strlen(*next_line));
	if (!ft_strlen(*next_line))
		return (NULL);
	return (*next_line);
}

char *get_next_line(int fd)
{
	static char *remaining;
	char *next_line;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	// if (remaining == 0x0)
	// {
	// 	remaining = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	// 	if (!remaining)
	// 		return (NULL);
	// }
	next_line = (char *)malloc(sizeof(char));
	if (!next_line)
		return (NULL);
	*next_line = '\0';
	next_line = start_read(fd, &remaining, &next_line);
	// printf("|%s|\n", remaining);
	// if (remaining != 0x0 && !ft_strlen(remaining))
	// {
	// 	// puts("hereeee");
	// 	free(remaining);
	// }

	// if (!next_line)
	// {
	// 	puts("freeing");
	// 	free(next_line);
	// 	return (NULL);
	// }
	return (next_line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	// get_next_line(fd);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
