#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * new_process - create a new process
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int new_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
	/* child process */
	if (execvp(args[0], args) == -1)
	{
	perror("error in new_process: child process");
	}
	exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
	/* error forking */
	perror("error in new_process: forking");
	}
	else
	{
	/* parent process */
	do {
		waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}
