/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:10:29 by arsbadal          #+#    #+#             */
/*   Updated: 2023/01/27 20:50:04 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *start_read(int fd, char **remaining_data, char **next_line, char **tmp)
{
	char *old_next_line;
	char	*temp_data;
	int read_val;

	if (*remaining_data && ft_strlen(*remaining_data))
	{
		if(ft_strchr(*remaining_data, '\n') != -1)
		{
			old_next_line = ft_substr(*remaining_data, 0, ft_strchr(*remaining_data, '\n'));
			temp_data = *remaining_data;
			*remaining_data = ft_substr(*remaining_data, ft_strchr(*remaining_data, '\n') + 1, ft_strlen(*remaining_data));
			free(temp_data);
			temp_data = 0;
			return (old_next_line);
		}
		*next_line = ft_strjoin(*next_line, *remaining_data);
		free(*remaining_data);
		*remaining_data = 0;
	}
	
	while (1)
	{
		read_val = read(fd, *tmp, BUFFER_SIZE);
		if (read_val < 0)
			return (NULL);
		if (read_val == 0)
			break;
		old_next_line = *next_line;
		*next_line = ft_strjoin(*next_line, *tmp);
		free(old_next_line);
		if (ft_strchr(*next_line, '\n') != -1)
		{
			temp_data = *remaining_data;
			*remaining_data = ft_substr(*next_line, ft_strchr(*next_line, '\n') + 1, ft_strlen(*next_line) + 1);
			printf("WATCH ___ |%s|\n", *remaining_data);
			free(temp_data);
			temp_data = 0;
			return (ft_substr(*next_line, 0, ft_strchr(*next_line, '\n')));
		}
	}
	
	return (*next_line);
}

char *get_next_line(int fd)
{
	static char *remaining;
	char *tmp;
	char *next_line;
	
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (NULL);
	next_line = (char *)malloc(sizeof(char));
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!next_line || !tmp)
		return (NULL);
	*next_line = '\0';
	next_line = start_read(fd, &remaining, &next_line, &tmp);

	// if(tmp)
		free(tmp);
	if (remaining && *remaining == '\0')
	{
		free(remaining);
		remaining = 0;
	}
	if (next_line && *next_line == '\0')
	{
		free(next_line);
		return (NULL);
	}
	return (next_line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	// get_next_line(fd);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
