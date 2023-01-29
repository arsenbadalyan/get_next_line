/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:10:35 by arsbadal          #+#    #+#             */
/*   Updated: 2023/01/29 15:07:03 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// C Libraries that using in this project
# include <unistd.h>
# include <stdlib.h>

// TODO: Delete in end
# include <sys/stat.h> 
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// Function Prototypes

// Main
char	*get_next_line(int fd);
void	free_me(char **addr);
char	*free_substr(char *str, unsigned int start, size_t len);
char	*alloc_space(char **cache);
char	*get_next_line(int fd);

// Utils
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif