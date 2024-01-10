#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Function declarations */
void prompt_$(void);
void error_check(void);
void exit_shell(void);

int main() {
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        prompt_$();

        read = getline(&input, &len, stdin);

        if (read == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }

        /* Execute commands based on 'input' here */
        /* Remember to fork a new process and use execve */
    }

    free(input);
    return 0;
}

void prompt_$() {
    printf("$ ");
}

void error_check() {
    /* Implement error checking logic here */
}

void exit_shell() {
    /* Implement shell exit logic here */
}
