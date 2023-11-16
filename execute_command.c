#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * execute_command - executes command read from stdin.
 *
 *@command: 2D array containing the command.
 *@argv: contains arguments (will be used to print name of the shell: argv[0]).
 *@number: number of times the prompt is used.
 * Return: exit status (Success)
 */
int execute_command(char **command, char **argv, int number)
{
char *full_cmd = NULL;
pid_t pid;
int status = 0;

full_cmd = get_path(command[0]);
if (!full_cmd)
{
error_msg(argv[0], command[0], number);
free_2D_array(command);
return (127);
}
pid = fork();

if (pid == -1)
{
perror("Error:");
exit(EXIT_FAILURE);
}
/*child process case*/
if (pid == 0)
{
if (execve(full_cmd, command, environ) == -1)
{
perror(argv[0]);
free(full_cmd), full_cmd = NULL;
free_2D_array(command);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
free_2D_array(command);
free(full_cmd), full_cmd = NULL;
}
return (WEXITSTATUS(status));
}
