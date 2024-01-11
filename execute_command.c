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
        char *buffer = malloc(1024);
        size_t len = 1024;

        while (1)
        {
        puts("$ ");
        getline(&buffer, &len, stdin);
        puts(buffer);
        }

        return (0);
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
