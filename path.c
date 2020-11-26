#include "holberton.h"

/**
 * check_path - searches $PATH for directory of command
 * @member: struct where variables are declared
 *Return: 0 on success
 */
int check_path(list_t *member)
{
	int len;
	static char buffer[BUFSIZE];
	struct stat st;
	char *token_path, *copy, *delim = ":";

	copy = _strdup(member->full_path); /* =full path */
	if (!copy)
	{
		member->path = member->args[0];
		free(copy);
		exit(errno);
		return (-1);
	}
	token_path = strtok(copy, delim); /* = /usr/local/sbin */
	while (token_path)
	{
		if (stat(member->args[0], &st) == 0)
		{
			member->path = member->args[0];
			free(copy);
			return (0);
		}
		len = _strlen(token_path) + _strlen(member->args[0]) + 2;
		_strcat(buffer, token_path);
		_strcat(buffer, "/");
		_strcat(buffer, member->args[0]);
		insertNullByte(buffer, len - 1);
		if (stat(buffer, &st) == 0)
		{
			free(copy);
			member->path = buffer;
			return (0);
		}
		insertNullByte(buffer, 0);
		token_path = strtok(NULL, delim);
	}
	member->path = member->args[0];
	free(copy);
	return (0);
}
