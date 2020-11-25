#include "holberton.h"

/**
 * _getenv - retrieves env variable that matches input string
 * @input: input string
 * @environ: local environmental variables
 * Return: string of env variable
 */
char *_getenv(char *input, char **environ)
{
	register int i = 0;
	char *tok, *right;

	while (environ[i])
	{
		tok = strtok(environ[i], "=");
		if (_strcmp(tok, input) == 0)
		{
			right = strtok(NULL, "=");
			return (right);
		}
		i++;
	}
	return (NULL);
}
/**
 * generateLinkedList - generates a linked list of environ
 * variables
 * @array: input array of strings
 * Return: head of linked list
 */
linked_l *generateLinkedList(char **array)
{
	register int i = 0;
	linked_l *head;

	head = NULL;
	while (array[i])
	{
		addNodeEnd(&head, array[i]);
		i++;
	}
	return (head);
}


/**
 * addNodeEnd - adds a new node at the end of a linked_l list;
 * @head: reference to head of list
 * @str: string to be added to linked list
 * Return: address of new node
 */
linked_l *addNodeEnd(linked_l **head, char *str)
{
	linked_l *newNode;
	linked_l *last = *head;
	char *newStr;

	if (!str)
		return (NULL);
	newNode = malloc(sizeof(linked_l));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
		free(newNode);
		perror("Malloc failed\n");
		exit(errno);
	}
	newNode->string = newStr;
	newNode->next = NULL;
	if (!*head)
	{
		*head = newNode;
		return (newNode);
	}
	while (last->next)
		last = last->next;
	last->next = newNode;
	return (last);
}
