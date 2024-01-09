#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - prototype
 * Return: 0
 */
int main(void)
{
  char *buffer = malloc(1024);
  size_t len = 1024;
  char *token;

  while (1)
  {
    puts("$ ");
    getline(&buffer, &len, stdin);
    puts("buffer getline: ");
    puts(buffer);
  
    token = strtok(buffer, " ");
    while (token)
    {
      puts("buffer strtok: ");
      puts(token);
      token = strtok(NULL, " ");
    }
  }
  return (0);
}
