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
	if (arg_count == 1)
	{
		prompt(arg_vector, env_variable);
	}

	return (0);
}

