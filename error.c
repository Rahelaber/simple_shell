#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int error_check(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
	write(STDOUT_FILENO, "$ ", 2);
	read = getline(&input, &len, stdin);

	if (read == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}

	/* Execute commands based on 'input' here */
	/* Handle command not found error */

	/* Example command execution */
	int ret = system(input);

	if (ret == -1)
		{
		fprintf(stderr, "Command not found: %s\n", input);
		}
	}

	free(input);

		return 0;
}

int main(void)
{
	error_check();
		return (0);
}

