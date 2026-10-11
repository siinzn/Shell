#include "include/header.h"

int own_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "expected argument: \"cd\"\n");
        return 1;
    }

    if (chdir(args[1]) == -1)
    {
        perror("cd");
    }

    return 1;
}

int own_exit(char **args) 
{
    (void)args;
    return 0;
}

int own_env(char **args) 
{
    size_t i = 0;
    (void)args;
    while(__environ[i]){
        write(STDOUT_FILENO, __environ[i], strlen(__environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
    return(-1);
}

int own_help(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	long unsigned int i = 0;
	(void)(**args);

	printf("\n---help simple_shell---\n");
	printf("Type a command and its arguments, then hit enter\n");
	printf("Built-in commands:\n");
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		printf("  -> %s\n", builtin_func_list[i]);
	}
	printf("Use the man command for information on other programs.\n\n");
	return (-1);
}