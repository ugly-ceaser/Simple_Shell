#include "shell.h"

/**
 * main - entry point for the shell program
 * @arg_count: number of command-line arguments passed to the program
 * @arg_vector: array of strings containing the command-line arguments
 * @env_variable: array of strings containing the environment variables
 *
 * Return: Always 0.
 */
int main(int arg_count, char **arg_vector, char **env_variable)
{
    /* If no command-line arguments were passed except for the program name */
    if (arg_count == 1)
    {
        /* Call the fetch function with the arg_vector and env_variable arguments */
        fetch(arg_vector, env_variable);
    }

    /* Return 0 to indicate successful execution */
    return (0);
}

