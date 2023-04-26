#include "shell.h"
#include <sys/wait.h>

#define MaxVAlue 10

/**
 * prompt - read input from the user and execute the command
 * @arg_vector: array of strings containing the command-line arguments
 * @env_variable: array of strings containing the environment variables
 *
 * Return: None.
 */
void prompt(char **arg_vector, char **env_variable)
{

    char *Data = NULL;
    int Checker, Progress_Status, Counter;
    size_t Num = 0;
    ssize_t Char_Counter;
    char *Arg_vector[MaxVAlue];
    pid_t Child_Process;

    while (1)
    {
        
        if (isatty(STDIN_FILENO))
            printf("#cisfun$");

        
        Char_Counter = getline(&Data, &Num, stdin);

        
        if (Char_Counter == -1)
        {
            free(Data);
            exit(EXIT_FAILURE);
        }

        
        Checker = 0;
        while (Data[Checker])
        {
            if (Data[Checker] == '\n')
                Data[Checker] = 0;
            Checker++;
        }

        Counter = 0;

        
        Arg_vector[Counter] = strtoq(Data, " ");

        
        while (Arg_vector[Counter] != NULL)
        {
            Arg_vector[++Counter] = strtoq(NULL, " ");
        }

        
        Child_Process = fork();

        
        if (Child_Process == -1)
        {
            free(Data);
            exit(EXIT_FAILURE);
        }

        
        if (Child_Process == 0)
        {
            if (execve(Arg_vector[0], Arg_vector, env_variable) == -1)
            {
                
                printf("%s :Operation failed\n", arg_vector[0]);
            }
        }
        
        else
        {
            wait(&Progress_Status);
        }
    }
}

