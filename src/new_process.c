#include "include/header.h"

int new_process(char **args) {
    pid_t pid;
    int status;

    pid = fork(); // duplicate current process, on failure return -1, child returns 0, parent returns positve
    if(pid == 0) 
    {
        if (execvp(args[0], args) == -1)
        {
            perror("error in new process: child process"); 
            exit(EXIT_FAILURE);
        }
        else if(pid < 0)  
        {
            perror("error in new_process: forking");
            return -1;
        }
        else
        {
            do
            {
                if (waitpid(pid, &status, WUNTRACED) == -1) 
                {
                    perror("waitpid");
                    return 1;
                }
            } 
            while(!WIFEXITED(status) && !WIFSIGNALED(status)); // wait while the child has exited ot killed by a signal
        }
    }
    return (-1);
}