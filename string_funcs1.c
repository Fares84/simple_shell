#include "holberton.h"
/**
 * _strchr - locates a character in a string
 * @s: string to be searched
 * @c: target char
 * Return: pointer to first occurrence of c or NULL if char not found
 */
char *_strchr(char *s, char c)
{
	char y;

	while (1)
	{
		y = *s++;
		if (y == c)
			return (s - 1);
		if (!y)
			return (NULL);
	}
}
/**
 * _strlen - returns the length of a string
 * @s: string s
 * Return: length of string
 */
int _strlen(char *s)
{
	char *p = s;

	while (*s)
		s++;
	return (s - p);
}

/**
 * _strcat - concatenates two strings
 * @dest: copy destination
 * @src: copy source
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src)
		*ptr++ = *src++;
	*ptr = 0;
	return (dest);
}
