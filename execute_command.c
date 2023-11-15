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
 * Return: exit status (Success)
 */
int execute_command(char **command, char **argv)
{
pid_t pid;
int status = 0;

pid = fork();

if (pid == -1)
{
perror("Error:");
exit(EXIT_FAILURE);
}
/*child process case*/
if (pid == 0)
{
if (execve(command[0], command, environ) == -1)
{
perror(argv[0]);
free_2D_array(command);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
free_2D_array(command);
}
return (WEXITSTATUS(status));
}
