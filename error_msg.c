#include "holberton.h"

/**
 * errorHandler - prints error message for shell
 * @member: the member list_t
 */
void errorHandler(list_t *member)
{
	register int len;
	static char error[BUFSIZE];
	char *ptr, *num;

	num = itoa(member->line_counter);
	_strcat(error, member->shell_name);
	_strcat(error, ": ");
	_strcat(error, num);
	_strcat(error, ": ");
	_strcat(error, member->args[0]);
	_strcat(error, getErrorMessage());
	_strcat(error, "\n");
	ptr = _strchr(error, '\n');
	len = ptr - error;
	write(STDERR_FILENO, error, len + 1);
	free(num);
	insertNullByte(error, 0);
}

/**
 * getErrorMessage - matches errno to corresponding string
 * Return: string of error message
 */
char *getErrorMessage(void)
{
	char *str;

	switch (errno)
	{
	case ENOENT:
		str = ": not found";
		break;
	case EILLEGAL:
		str = ": numeric argument required";
		break;
	default:
		str = ": error errno";
	}
	return (str);
}

/**
 * countDigits - count number of digits in a number
 * @num: input number
 * Return: number of digits
 */
unsigned int countDigits(int num)
{
	register int digits = 0;

	while (num > 0)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

/**
 * itoa - converts integer to string
 * @num: input integer
 * Return: string type of number
 */
char *itoa(unsigned int num)
{
	register int digits = 0;
	char *str;

	digits += countDigits(num);
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
	{
		perror("Malloc: failed\n");
		exit(errno);
	}
	insertNullByte(str, digits);
	while (num > 0)
	{
		str[digits - 1] = num % 10 + '0';
		num = num / 10;
		digits--;
	}
	return (str);
}
