#include "shell.h"


/* execute_command -  perform the command given
 * Return - 0
 *
 */

int main execute_command(command);
{
        char *input = NULL;
        size_t len = 0;
        ssize_t read;

while (1)
{
        printf("$ ");
        read = getline(&input, &len, stdin);

        if (read == -1)
{
        perror("getline");
        exit(EXIT_FAILURE);
}

/*Execute commands based on 'input' here*/
/* Remember to fork a new process and use execve*/

}
