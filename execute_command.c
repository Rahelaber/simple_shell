#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - function that checks if our shell is called
 *
 * Return: 0 on success
 */


/* Function declarations */
void error_check(void);
void exit_shell(void);

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

	/* Execute commands based on 'input' here */
	/* Remember to fork a new process and use execve */
	}

	free(input);
	return (0);
}

void prompt_$(void)
{
	printf("$ ");
}

/**
 * error_check - function that checks if our shell is called
 *
 * Return: 0 on success
 */

void error_check(void)

{
	/* Implement error checking logic here */
}

/**
 * exit_shell - function that checks if our shell is called
 *
 * Return: 0 on success
 */

void exit_shell(void)
{
	/* Implement shell exit logic here */
}
