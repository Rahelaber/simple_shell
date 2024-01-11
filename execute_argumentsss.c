#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_ARGS 64


int own_cd(char **args) __attribute__((unused));
int own_env(char **args) __attribute__((unused));
int own_help(char **args) __attribute__((unused));
int own_exit(char **args) __attribute__((unused));

int execute_args(char **args) __attribute__((unused));

int new_process(char **args) __attribute__((unused));

int (*builtin_func[])(char **) = {
	&own_cd,
	&own_env,
	&own_help,
	&own_exit
};
/**
 * execute_args - execute arguments
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int execute_args(char **args __attribute__((unused)))
{
	int i;

	for (i = 0; i < 4; i++)
	{
	if (strcmp(args[0], args[i]) == 0)
	{
	return ((*builtin_func[i])(args));
	}
	}

	return (new_process(args));
}

/**
 * own_cd - execute arguments
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int own_cd(char **args __attribute__((unused)))
{
write(STDOUT_FILENO, "Executing own_cd function\n",
		strlen("Executing own_cd function\n"));
	return (1);
}

/**
 * own_env - execute arguments
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */

int own_env(char **args __attribute__((unused)))
{
write(STDOUT_FILENO, "Executing own_env function\n",
		strlen("Executing own_env function\n"));
	return (1);
}

/**
 * own_help - execute arguments
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */

int own_help(char **args __attribute__((unused)))
{
write(STDOUT_FILENO, "Executing own_help function\n",
		strlen("Executing own_help function\n"));
	return (1);
}

/**
 * own_exit - execute arguments
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */

int own_exit(char **args __attribute__((unused)))
{
write(STDOUT_FILENO, "Executing own_exit function\n",
		strlen("Executing own_exit function\n"));
	return (0);
}

/**
 * new_process - execute arguments
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */

int new_process(char **args __attribute__((unused)))
{
write(STDOUT_FILENO, "Executing new_process function\n",
		strlen("Executing new_process function\n"));
	return (1);
}

/**
 * main - execute arguments
 *
 * Return: 1 if success, 0 otherwise.
 */

int main(void)
{
	char *command[] = {"cd", "env", "help", "exit"};

	execute_args(command);
	return (0);
}

