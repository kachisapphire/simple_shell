#include "shell.h"
/**
 *check_path - command to execute
 *@command: string to check
 *Return: command path
 */
char *check_path(char *command)
{
	char *path = getenv("PATH");
	char *path_cpy = strdup(path);
	char *delim = ":";
	char buffer[1024];
	char *token = strtok(path_cpy, delim);

	while (token != NULL)
	{
		strcopy(buffer, token);
		if (buffer[strlength(buffer) - 1] != '/')
		{
			strcat(buffer, "/");
		}
		strcat(buffer, command);
		if (access(buffer, F_OK) == 0 && access(buffer, X_OK) == 0)
		{
			free(path_cpy);
			return (strdup(buffer));
		}
		token = strtok(NULL, delim);
	}
	free(path_cpy);
	return (NULL);
}
