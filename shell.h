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
int strlength(char *s);
char *strcopy(char *dest, char *src);
int strcomp(char *s1, char *s2);
char *stringcat(char *dest, char *src);
char *stringdup(char *str);

#endif
