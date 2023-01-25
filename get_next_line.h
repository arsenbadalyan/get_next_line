#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// C Libraries that using in this project
#include <unistd.h>
#include <stdlib.h>

// TODO: Delete in end
#include <sys/stat.h> 
#include <fcntl.h>
#include <stdio.h>

// Function Prototypes
char *get_next_line(int fd);
char *ft_strjoin(const char *s1, const char *s2);
size_t ft_strlen(const char *s);
int ft_strchr(const char *str, int ch);
char *ft_strdup(const char *s1);
char *ft_substr(char const *s, unsigned int start, size_t len);

#endif