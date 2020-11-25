#include "holberton.h"

/**
 * execute - fork current member and execute processes
 * @member: input member
 */
void execute(list_t *member)
{
	int status;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("error\n");
		free_members(member);
		exit(status);
	}
	if (child_pid == 0)
	{
		if (execve(member->path, member->args, environ) == -1)
		{
			errorHandler(member);
			free_members(member);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			member->error_stat = WEXITSTATUS(status);
		free_args_line(member);
	}
}
