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
int execute_command(char **command, char **argv, int number);
char *_getenv(const char *name);
char *get_path(char *command);
void free_2D_array(char **array);
void error_msg(char *name, char *command, int number);
char *_itoa(int n);
void reverse(char str[], int length);
void _env(char **command);
void exit_sh(char **command, int status);
void handling_exit_env(char **command, char **argv, int status, int number);
int is_built_in(char *command);

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _conststrlen(const char *s);
char *_strncpy(char *dest, const char *src, int n);

#endif
