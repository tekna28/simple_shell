#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

char *get_line(void);
char **parsing(char *line);
int execute_command(char **command, char **argv);

void free_2D_array(char **array);

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _conststrlen(const char *s);
char *_strncpy(char *dest, const char *src, int n);

#endif
