#include "holberton.h"

/**
 * get_builtins - checks for builtin and gets the corresponding function
 * @member: struct where args are declares
 * Return: 1 if builtin found, 0 if else
 */
int get_builtins(list_t *member)
{
	int i = 0;
	built_t getBuiltIns[] = {
		{"exit", f_exit},
		{"env", f_env},
		{NULL, NULL}
	};

	while (getBuiltIns[i].command)
	{
		if (_strcmp(member->args[0], getBuiltIns[i].command) == 0)
		{
			getBuiltIns[i].f(member);
			free_args_line(member);
			return (1);
		}
		i++;
	}
	return (0);
}
