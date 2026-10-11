#include "include/header.h"

int execute_args(char **args) {

    char *bultin_func_list[] = {
        "cd",
        "env",
        "help",
        "exit"
    };

    int (*bultin_func[])(char **) = {
        &own_cd,
        &own_env,
        &own_help,
        &own_exit
    };

    if(args[0] == NULL) return (-1);

    for(size_t i=0; i < sizeof(bultin_func_list) / sizeof(char *); i++) {
        if(strcmp(args[0], bultin_func_list[i]) == 0) return ((*bultin_func[i])(args));
    }
    return (new_process(args));
}

