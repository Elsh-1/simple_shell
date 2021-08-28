#ifndef INC_H
#define INC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
char *_getenv(const char *var);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, const char *src);
char *search(char *bin, char **path_arr);
char **split_path(char *str);
char *_path(char *bin_name);
char *_strcat(char *dest, const char *src);


#endif
