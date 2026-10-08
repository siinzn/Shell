#include "../include/header.h"

char *read_line(void) 
{
    char *line = NULL;
    size_t buffer = 0;
    if(getline(&line, &buffer, stdin) == -1) {
        if(feof(stdin)) {
            free(line);
            exit(EXIT_SUCCESS);
        } 
        else {
            free(line);
            perror("error reading the line");
            exit(EXIT_FAILURE);
        }
    }
    return(line);
}