#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* Function declarations */
void prompt_$(void);
void error_check(void);
void exit_shell(void);
char **parse_input(char *input);
void execute_command(char **args);

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
	prompt_$();

	read = getline(&input, &len, stdin);

	if (read == -1)
	{
	perror("getline");
	exit(EXIT_FAILURE);
	}

		/* Parse the input into arguments*/
	char **args = parse_input(input);

	/* Execute the command*/
	execute_command(args);

	/* Free the allocated memory*/
	free(args);
	}

	free(input);
	return 0;
}

void prompt_$(void)
{
	printf("$ ");
}

void error_check(void)
{
	/* Implement error checking logic here */
}

void exit_shell(void)
{
	/* Implement shell exit logic here */
}

char **parse_input(char *input)
{
	/* Allocate memory for an initial array of arguments*/
	char **args = malloc(64 * sizeof(char *));

	if (args == NULL)

	{
	perror("malloc");
	exit(EXIT_FAILURE);
	}

	/* Tokenize the input string by spaces*/
	char *token = strtok(input, " \t\n");

	int i = 0;

	while (token != NULL)
	{
	args[i] = token;
	i++;

	/* Reallocate more memory if needed*/
	if (i >= 64)
	{
	args = realloc(args, (i + 64) * sizeof(char *))
	if (args == NULL)
	{
	perror("realloc");
	exit(EXIT_FAILURE);
	}
	}

	token = strtok(NULL, " \t\n");
	}
	args[i] = NULL; /* Set the last argument to NULL*/
	{
	return args;
	}
}

void execute_command(char **args)
{
	pid_t pid = fork();
if (pid == -1)

	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	/* Child process*/
	if (execvp(args[0], args) == -1)
{
	perror("execvp");
	exit(EXIT_FAILURE);
	}
	}
	else
	{
	/* Parent process*/
	int status;

	waitpid(pid, &status, 0);
	}
}
