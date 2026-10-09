
#ifndef SHELL_H
#define SHELL_H

// libraries
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define LSH_RL_BUFSIZE 1024
#define LSH_SL_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

char *read_line(void);
char **split_line(char *line);

#endif
