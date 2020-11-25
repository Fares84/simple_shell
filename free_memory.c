#include "holberton.h"

/**
 * freeMembers - frees member list_t members
 * @member: input member
 */
void free_members(list_t *member)
{
	if (member->env_ll)
		free_list(member->env_ll);
	if (member->args)
		free_args(member->args);
	if (member->line)
		free(member->line);
}

/**
 * freeArgsAndBuffer - frees args and buffer
 * @member: input member
 */
void free_args_line(list_t *member)
{
	free_args(member->args);
	free(member->line);
}

/**
 * freeList - frees a linked list
 * @head: double pointer to head of list
 */
void free_list(linked_l *head)
{
	linked_l *current;
	linked_l *tmp;

	if (!head)
		return;
	current = head;
	while (current)
	{
		tmp = current;
		current = tmp->next;
		free(tmp->string);
		free(tmp);
	}
	head = NULL;
}

/**
 * freeArgs - helper func that frees double pointer arg
 * @args: array of char pointers
 */
void free_args(char **args)
{
	unsigned int i = 0;

	while (args[i])
		free(args[i++]);
	free(args);
}
