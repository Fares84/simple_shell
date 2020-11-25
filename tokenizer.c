#include "holberton.h"
#define OUT 0
#define IN 1
/**
 * tokenizer - parses input line into tokens
 * @member: struct where input line is declared
 * Return: -1 if not parsed, 1 if parsed
 */
int tokenizer(list_t *member)
{
	unsigned int n_words_line, i = 0;
	char *token, *line_copy;

	n_words_line = count_words(member->line) + 1; /* +1 for l l l */
	if (n_words_line == 0)
	{
		member->args = NULL;
		free(member->line);
		free_members(member);
		return (-1);
	}
	member->args = malloc((n_words_line + 1) * sizeof(char *));
	line_copy = _strdup(member->line);
	token = strtok(line_copy, " ");

	while (token)
	{
		member->args[i] = _strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	member->args[i] = NULL;
	free(line_copy);
	return (1);
}


/**
 * count_words - counts words in a line string (separator excluded)
 * @s: input string
 * Return: number of words
 */
unsigned int count_words(char *s)
{
	unsigned int wc = 0;
	int state = OUT;

	while (*s)
	{
		if (s[wc] == ' ' && state)
			state = OUT;
		else if (s[wc] != ' ' && !state)
		{
			state = IN;
			wc++;
		}
		s++;
	}
	return (wc);
}
