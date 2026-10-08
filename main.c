#include "include/header.h"

int main(void) {
    char *line = read_line();
    if(line != NULL) printf("%s\n", line);
    free(line);
    return 0;
}