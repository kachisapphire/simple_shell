#ifndef ESTHER_H
#define ESTHER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
extern char **environ;

char *check_path(char *command);
void get_input();
void execute(char *array[]);
void builtins_exit(void);
void builtins_cd(char *arg);

#endif