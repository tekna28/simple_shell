#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "main.h"

/**
 * get_path - handles the path.
 *
 *@command: command from stdin.
 * Return: address of pointer (Success)
 */
char *get_path(char *command)
{
char *env_path = NULL, *full_cmd = NULL, *dir;
int i;
struct stat st;

for (i = 0; command[i]; i++)
{
if (command[i] == '/')
{
if (stat(command, &st) == 0)
return (_strdup(command));
return (NULL);
}
}
env_path = _getenv("PATH");
if (!env_path)
return (NULL);

dir = strtok(env_path, ":");
while (dir != NULL)
{
/* 2 means for: '/' and '\0' */
full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
if (full_cmd != NULL)
{
_strcpy(full_cmd, dir);
_strcat(full_cmd, "/");
_strcat(full_cmd, command);
if (stat(full_cmd, &st) == 0)
{
free(env_path);
return (full_cmd);
}

free(full_cmd), full_cmd = NULL;
dir = strtok(NULL, ":");
}
}
/*free(env_path);*/
return (NULL);
}
