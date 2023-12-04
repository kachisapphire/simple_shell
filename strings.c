#include "shell.h"
/**
 *strlength - checks the length of s string
 *@s: string to check
 *Return: length
 */
int strlength(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
/**
 *strcopy - copies a string
 *@dest: destination string
 *@src: source string
 *Return: dest
 */
char *strcopy(char *dest, char *src)
{
	char *origin_dest;

	origin_dest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (origin_dest);
}
/**
 *strcomp - compare two strings
 *@s1: first input
 *@s2: second input
 *Return: 0 or -1
 */
int strcomp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
/**
 *stringcat - function to concatenate
 *@dest: first input
 *@src: second input
 *Return: new length
 */
char *stringcat(char *dest, char *src)
{
	int lendest = 0;
	int lensrc= 0;
	int i;

	for (i = 0; dest[i] != '\0'; i++)
		lendest++;
	for (i = 0; src[i] != '\0'; i++)
		lensrc++;
	for (i = 0; i < lensrc; i++)
		dest[lendest + i] = src[i];
	dest[lendest + lensrc] = '\0';
	return (dest);
}
