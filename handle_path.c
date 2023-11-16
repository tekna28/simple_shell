#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"

/**
 * _getenv - gets environment variable value.
 *
 *@name: name of environment variable we're looking for.
 * Return: value associated with environment variable (Success)
 */
char *_getenv(const char *name)
{
char *env;
char *name_copy;
unsigned int i = 0;
unsigned int length;

length = _conststrlen(name);
name_copy = malloc((sizeof(char) * length) +1);
if (!name_copy)
return (NULL);

_strncpy(name_copy, name, length);

env = strtok(environ[i], "=");
while (environ[i])
{
if (_strcmp(env, name_copy))
{
env = strtok(NULL, "\n");
free(name_copy);
return (env);
}
++i;
env = strtok(environ[i], "=");
}
free(name_copy);
return (NULL);
}
