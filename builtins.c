#include "holberton.h"

/**
 * f_exit - exits the program
 * @member: struct where input args are declared
 * Return: 1 on success, 0 on failure
 */
int f_exit(list_t *member)
{
	int n_args, exit_status;

	n_args = count_args(member->args);

	if (n_args == 1)
	{
		free_members(member);
		exit(0); /*success*/
	}
	else if (n_args > 1)
	{
		exit_status = _atoi(member->args[1]);
		if (exit_status == -1)
		{
			errno = EILLEGAL; /* require num */
			errorHandler(member);
			return (0);
		}
		free_members(member);
		exit(exit_status);
	}
	return (1);
}

/**
 * count_args - count n of args for exit function
 * @args: input array of strings
 * Return: number of args
 */
int count_args(char **args)
{
	int i = 0;

	while (args[i])
		i++;
	return (i);
}

/**
 * _atoi - converts string to an integer
 * @s: input string
 * Return: -1 for invalid number, or converted number
 */
int _atoi(char *s)
{
	int i = 0;
	unsigned long n = 0;

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			n = n * 10 + s[i] - '0';
		else
			return (-1);
		i++;
	}
	if (n > INT_MAX)
	{
		return (-1);
	}
	return (n);
}



/**
 * f_env - prints the environment
 * @member: struct where the environment in a linked list is declared
 * Return: Always 1
 */
int f_env(list_t *member)
{
	int i = 0;

	while (member->env_ll)
	{
		write(STDOUT_FILENO, member->env_ll->string,
		      _strlen(member->env_ll->string));
		displayNewLine();
		member->env_ll = member->env_ll->next;
		i++;
	}
	return (1);
}

