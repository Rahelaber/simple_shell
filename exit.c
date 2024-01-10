#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * exit_shell - Exit the shell
 *
 *
 * Return: 1 if success, 0 otherwise.
 */
void exit_shell(void);

int main(void)
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

    exit_shell();

    return 0;
}
