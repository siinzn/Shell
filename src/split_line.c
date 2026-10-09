#include "../include/header.h"

char **split_line(char *line){
    int bufsize = LSH_SL_BUFSIZE;
    int position = 0;
    char **tokens = malloc(sizeof(char*) * bufsize);
    char *token;

    if(!tokens) {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line,LSH_TOK_DELIM);
    while(token != NULL) {
        tokens[position] = token;
        position++;

        if(position >= bufsize) {
            bufsize += LSH_SL_BUFSIZE;
            tokens = realloc(tokens, sizeof(char*) * bufsize);

            if(!tokens) {
                fprintf(stderr,  "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, LSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}