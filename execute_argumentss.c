#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int own_cd(char **args);
int own_env(char **args);
int own_help(char **args);
int own_exit(char **args);

int execute_args(char **args);

int new_process(char **args);

int (*builtin_func[])(char **) = {
	&own_cd,
	&own_env,
	&own_help,
	&own_exit
};

int execute_args(char **args)
{
	int i;

	int own_cd = 0;
	int own_env = 1;
	int own_help = 2;
	int own_exit = 3;

	for (i = 0; i < 4; i++)
	{
	if (strcmp(args[0], args[i]) == 0)
	{
	return ((*builtin_func[i])(args));
	}
		}

	return (new_process(args));
}

int own_cd(char **args)
{
	write(STDOUT_FILENO, "Executing own_cd function\n", strlen("Executing own_cd function\n"));
	return (1);
}

int own_env(char **args)
{
	write(STDOUT_FILENO, "Executing own_env function\n", strlen("Executing own_env function\n"));
	return (1);
}

int own_help(char **args)
{
	write(STDOUT_FILENO, "Executing own_help function\n", strlen("Executing own_help function\n"));
	return (1);
}

int own_exit(char **args)
{
	write(STDOUT_FILENO, "Executing own_exit function\n", strlen("Executing own_exit function\n"));
	return (0);
}

int new_process(char **args)
{
	write(STDOUT_FILENO, "Executing new_process function\n", strlen("Executing new_process function\n"));
    return (1);
}

int main(void)
{
	char *command[] = {"cd", "env", "help", "exit"};
	execute_args(command);
	return (0);
}

