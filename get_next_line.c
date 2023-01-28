/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:10:29 by arsbadal          #+#    #+#             */
/*   Updated: 2023/01/28 17:12:04 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *free_substr(char *str, unsigned int start, size_t len)
{
	char *tmp;

	tmp = str;
	str = ft_substr(str, start, len);
	if(tmp)
	{
		free(tmp);
		tmp = 0;
	}
	return (str);
}

char *start_read(int fd, char **remaining_data)
{
	char	tmp[BUFFER_SIZE + 1];
	int		readed_res;
	char	*next_line;

	next_line = (char *)malloc(sizeof(char));
	if (!next_line)
		return (NULL);
	if (*remaining_data && ft_strlen(*remaining_data))
	{
		if (ft_strchr(*remaining_data, '\n') != -1)
		{
			free(next_line);
			next_line = ft_substr(*remaining_data, 0, ft_strchr(*remaining_data, '\n') + 1);
			*remaining_data = free_substr(*remaining_data, ft_strchr(*remaining_data, '\n') + 1, ft_strlen(*remaining_data) + 1);
			return (next_line);
		}
		next_line = ft_strjoin(next_line, *remaining_data);
		free(*remaining_data);
	}
	while (1)
	{
		readed_res = read(fd, tmp, BUFFER_SIZE);
		if(readed_res <= 0)
			break;
		tmp[readed_res] = '\0';
		next_line = ft_strjoin(next_line, tmp);
		if (ft_strchr(next_line, '\n') != -1)
		{
			*remaining_data = ft_substr(next_line, ft_strchr(next_line, '\n') + 1, ft_strlen(next_line) + 1);
			next_line = free_substr(next_line, 0, ft_strchr(next_line, '\n') + 1);
			return (next_line);
		}
	}
	return (next_line);
}

char *get_next_line(int fd)
{
	static char *remaining;
	char *next_line;
	
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (NULL);
	
	next_line = start_read(fd, &remaining);
	if (remaining && *remaining == '\0')
	{
		free(remaining);
		remaining = 0;
	}
	if (next_line && *next_line == '\0')
	{
		free(next_line);
		next_line = 0;
		return (0);
	}
	return (next_line);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
