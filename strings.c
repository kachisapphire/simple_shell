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
/**
 *
 *
 *
 */
/*char* stringtok(char *str, const char *delimeter)
{
	int len = strlength(str);
	char *alpha = (char *)malloc((len + 1) * sizeof(char));
	int i, k, j = 0;
	int delim, d;
	int delimlen = strlength(delimeter);

	for (i = 0; i <= len; i++)
	{
		delim = 0;
		for (d = 0; d < delimlen; d++)
		{
			if (str[i] == delimeter[d] || str[i] == '\0')
			{
				delim = 1;
				break
			}
		}
		if (delim)
		{
			alpha[j] = '\0';
			if (j > 0)
			{
				for (k = 0; alpha[k] != '\0'; k++)
				{
					_putchar(alpha[k]);
					_putchar('\n');
					j = 0;
				}
			}
			else
				alpha[j++] = str[i];
		}
	}
	return (alpha);
}*/
