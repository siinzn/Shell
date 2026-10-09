#include "include/header.h"

int main(void) {
    char *line = read_line();
    char **parsed_line = split_line(line);

    if(line != NULL) printf("%s\n", line);
    for(size_t i = 0; i < sizeof(parsed_line); i++) {
        if(parsed_line[i] != NULL) {
            printf("%s\n", parsed_line[i]);
        } else {
            exit(EXIT_FAILURE);
        }
    }
    free(line);
    free(parsed_line);
    return 0;
}