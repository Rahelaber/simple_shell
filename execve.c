#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{

	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	puts("Before execve");
	if (execve(argv[0], argv, NULL) == -1)
	{
	perror("Error:");
	}
	puts("After execve");
	return (0);
}
