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
 *input_builtins - function to implement builtins
 *@line: string to read
 *Return: void
 */
void input_builtins(char *line)
{
	char *delim = " \n";
	char *array[1024], *token;
	int idx;

	idx = 0;
	token = strtok(line, delim);
	while (token != NULL)
	{
		array[idx] = token;
		token = strtok(NULL, delim);
		idx++;
	}
	array[idx] = NULL;
	if (strcomp(array[0], "cd") == 0)
		builtins_cd(array[1]);
	else if (strcomp(array[0], "exit") == 0)
		builtins_exit();
/*	else if (strcomp(array[0], "printenv") == 0 || strcomp(array[0], "env") == 0)
	{
		printenv(env);
		continue;
	}*/

	else
		execute(array);
}
/**
 *get_input - read users input
 *Return: void
 */
void get_input(void)
{
	ssize_t str;
	size_t len = 0;
	char *line = NULL;

	while (1)
	{
		write(1, "shell$ ", 7);
		str = getline(&line, &len, stdin);
		if (str == -1)
		{
			if (feof(stdin))
				exit(EXIT_SUCCESS);
			else
			{
				perror("Error getting input");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		else if (str == 1)
			continue;
		else
			input_builtins(line);
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
/**
 *stringdup - funtion that duplicates
 *@str: string to duplicate
 *Return: copy
 */
char *stringdup(char *str)
{
	char *copy;
	int len = 0;
	int i;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		len++;
	copy = malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		copy[i] = str[i];
	return (copy);
}
