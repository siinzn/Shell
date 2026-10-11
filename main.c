#include "include/header.h"

void lsh_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = read_line();
    args = split_line(line);
    status = execute_args(args);

    free(line);
    free(args);
  } while (status);
}

int main(void) 
{
	lsh_loop();
    return EXIT_SUCCESS;
}