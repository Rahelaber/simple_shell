#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/execute_arguments.h"


/**
 * execute_args - execute arguments
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int execute_args(char **args)
{
	int i;
	char *builtin_str[] = {
	"cd",
	"env",
	"help",
	"exit"
	};

	int (*builtin_func[]) (char **) = {
	&own_cd,
	&own_env,
	&own_help,
	&own_exit
	};

	if (args[0] == NULL)
	{
	/* An empty command was entered. */
	return (1);
	}

	for (i = 0; i < 4; i++)
	{
	if (strcmp(args[0], builtin_str[i]) == 0)
	{
	return ((*builtin_func[i]));
	}
	}

	return (new_process(args));
}
