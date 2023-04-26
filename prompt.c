#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

/**
 * prompt - read input from the user and execute the command
 * @env_variable: array of strings containing the environment variables
 *
 * Return: None.
 */
void prompt(char **env_variable)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t input_lenght;
	pid_t child_process;
	int child_status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");

		input_lenght = getline(&input, &input_size, stdin);

		if (input_lenght == -1)
		{
			free(input);
			exit(EXIT_FAILURE);
		}

		if (input_lenght > 0 && input[input_lenght - 1] == '\n')
			input[input_lenght - 1] = '\0';

		child_process = fork();

		if (child_process == -1)
		{
			perror("fork");
			free(input);
			exit(EXIT_FAILURE);
		}

		if (child_process == 0)
		{
			char *command = strtok(input, " ");

			if (execve(command, &command, env_variable) == -1)
			{
				perror("operation failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(child_process, &child_status, 0);
		}
	}
}
