#include "shell.h"
#include <sys/wait.h>

#define MAX_VALUE 10

/**
 * prompt - read input from the user and execute the command
 * @arg_vector: array of strings containing the command-line arguments
 * @env_variable: array of strings containing the environment variables
 *
 * Return: None.
 */
void prompt(char **arg_vector, char **env_variable)
{
	char *data = NULL;
	int checker, progress_status, counter;
	size_t num = 0;
	ssize_t char_counter;
	pid_t child_process;

	while (1)
	{
		/* If standard input is a terminal, display a prompt */
		if (isatty(STDIN_FILENO))
			printf("#cisfun$");

		/* Read input from the user */
		char_counter = getline(&data, &num, stdin);

		/* If getline fails, exit with a failure status */
		if (char_counter == -1)
		{
			free(data);
			exit(EXIT_FAILURE);
		}

		/* Replace the newline character with a null character */
		checker = 0;
		while (data[checker])
		{
			if (data[checker] == '\n')
				data[checker] = 0;
			checker++;
		}

		counter = 0;

		/* Set the command to be executed */
		arg_vector[counter] = strtok(data, " ");

		/* Parse the input string into an array of arguments */
		while (arg_vector[counter] != NULL)
		{
			arg_vector[++counter] = strtok(NULL, " ");
		}

		/* Create a child process to execute the command */
		child_process = fork();

		/* If fork fails, exit with a failure status */
		if (child_process == -1)
			exit(EXIT_FAILURE);

		/* If this is the child process, execute the command */
		if (child_process == 0)
		{
			if (execve(arg_vector[0], arg_vector, env_variable) == -1)
			{
				/* If execve fails, print an error message to the console */
				printf("%s :Operation failed\n", arg_vector[0]);
				exit(EXIT_FAILURE);
			}
		}
		/* If this is the parent process, wait for the child to finish */
		else
		{
			wait(&progress_status);
		}
	}
}

