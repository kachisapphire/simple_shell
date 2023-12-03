#include "shell.h"
/**
 *builtins_exit - command to execute 
 *Return: void
 */
void builtins_exit(void)
{
	exit(0);
}
/**
 *builtins_cd - command to execute
 *@arg: string to implement
 *Return: void
 */
void builtins_cd(char *arg)
{
	char *home;

	if (arg == NULL)
	{
		home = getenv("HOME");
		if (home == NULL)
			perror("Home variable not set");
		else if (chdir(home) != 0)
			perror("directory could not change");
	}
	else if (chdir(arg) != 0)
		perror("Directory could not change");
}
