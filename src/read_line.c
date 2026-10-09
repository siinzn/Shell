#include "../include/header.h"

char *read_line(void) 
{
        /*
    this is a way to do it easily with getline, but lets do it without to learn about it
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
    */

    int c; //characters can be represented as ints
    int bufsize = LSH_RL_BUFSIZE;
    char *buffer = malloc(sizeof(char) * bufsize);
    int position = 0;

    if(!buffer) {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        c = getchar();
        if(c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } 
        else 
        {
            buffer[position] = c;
        }
        position++;

        if(position >= bufsize) {
            bufsize += LSH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if(!buffer) {
                fprintf(stderr, "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}