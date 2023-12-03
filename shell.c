#include "shell.h"
/**
 *execute - execute the command
 *@array: string of command
 *Return: void
 */
void execute(char *array[])
{
	int status;
	pid_t pid;
	char *cmdpath;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		cmdpath = check_path(array[0]);
		if (cmdpath != NULL)
		{
			execve(cmdpath, array, environ);
			perror("Failed to execute");
			free(array);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
/**
 *get_input - read users input
 *Return: void
 */
void get_input(void)
{
	ssize_t str;
	size_t len = 0;
	char *delim = " \n", *line = NULL;
	char *array[1024], *token;

	while (1)
	{
		write(1, "shell$ ", 7);
		str = getline(&line, &len, stdin);
		if (str == -1)
		{
			perror("Error getting input");
			exit(EXIT_FAILURE);
		}
		else if (str == 1)
			continue;
		else
		{
			int idx = 0;

			token = strtok(line, delim);
			while (token != NULL)
			{
				array[idx] = token;
				token = strtok(NULL, delim);
				idx++;
			}
			array[idx] = NULL;
			if (strcmp(array[0], "cd") == 0)
				builtins_cd(array[1]);
			else if (strcmp(array[0], "exit") == 0)
				builtins_exit();
			else
				execute(array);
		}
	}
	free(line);
}
/**
 *main - entry point
 *Return: 0 or -1
 */
int main(void)
{
	get_input();
	return (0);
}
