#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * exit_shell - function that checks if our shell should exit
 *
 * Return: 0 on success
 */

void exit_shell(void)

{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
	puts("$ ");
	read = getline(&input, &len, stdin);

	if (read == -1)
	{
	perror("getline");
	exit(EXIT_FAILURE);
	}
	/*Handle 'exit' command here*/
	if (strcmp(input, "exit\n") == 0)
	{
	free(input);
	exit(EXIT_SUCCESS);
	}
	}
}

int main(void)
{
	exit_shell();

	return (0);
}
