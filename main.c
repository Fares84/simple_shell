#include "holberton.h"

/**
 * main - entry point
 * @ac: n of arguments
 * @av: arguments
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int get_line_len;
	list_t member;
	(void)ac;

	member.shell_name = av[0];
	member.env_ll = generateLinkedList(environ);
	member.full_path = _getenv("PATH", environ);
	member.path = NULL;
	member.line = NULL;
	member.line_counter = 0;
	member.error_stat = 0;
	signal(SIGINT, sigintHandler);


	while (1)
	{
		size_t line_size = 0;

		member.args = NULL;
		member.line_counter++;
		if (isatty(STDIN_FILENO))
			displayPrompt();
		get_line_len = getline(&member.line, &line_size, stdin);
		if (get_line_len == EOF)
		{
			free_members(&member);
			break;
		}
		if (_strchr(member.line, '\n'))
			insertNullByte(member.line, get_line_len - 1);
		if (tokenizer(&member) == -1)
			continue;
		if (get_builtins(&member) == 1)
			continue;
		check_path(&member);
		execute(&member);
	}
	return (0);
}
