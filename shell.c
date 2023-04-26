#include "shell.h"

/**
 * main - entry point for the shell program
 * @arg_count: number of command-line arguments passed to the program
 * @env_variable: array of strings containing the environment variables
 *
 * Return: Always 0.
 */
int main(int arg_count, char **env_variable)
{
	if (arg_count == 1)
	{
		prompt(env_variable);
	}

	return (0);
}

