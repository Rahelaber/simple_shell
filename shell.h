#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/*---Macros---*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/*---PROTOTYPES---*/

/* main.c */
void shell_interactive(void);
void shell_no_interactive(void);

/* shell_interactive.c */

char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);
void error_check(void);
void execute_command(char *command);
void exit_shell(void);
void user_input(char *command, size_t size);

/* execute_args */
int new_process(char **args);

/* shell_no_interactive */
char *read_stream(void);

/*---Builtin func---*/
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);

#endif
