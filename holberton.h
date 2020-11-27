#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>

/* ERRORS */
#define BUFSIZE 256
#define EILLEGAL 227


extern char **environ;

/**
 * struct linkedList - linked list data structure
 * @string: environ variable path name
 * @next: pointer to next node
 */
typedef struct linkedList
{
	char *string;
	struct linkedList *next;
} linked_l;

/**
 * struct list_s - configuration of member settings
 * @env_ll: linked list of local environ variables
 * @args: array of argument strings
 * @line: string line of user input
 * @full_path: array of $PATH locations
 * @path: string of path with correct prepended $PATH
 * @shell_name: name of shell (argv[0])
 * @line_counter: counter of lines users have entered
 * @error_stat: error status of last child process
 */
typedef struct list_s
{
	linked_l *env_ll;
	char **args;
	char *line;
	unsigned int line_counter;
	char *full_path;
	char *path;
	char *shell_name;
	int error_stat;
} list_t;

/**
 * struct builtins - commands and functions associated with it
 * @command: input command
 * @f: output function
 */
typedef struct builtins
{
	char *command;
	int (*f)(list_t *);
} built_t;


int get_builtins(list_t *member);
int f_exit(list_t *member);
int f_env(list_t *member);
int count_args(char **args);
int _atoi(char *s);
void execute(list_t *member);
char *_getenv(char *input, char **environ);
void errorHandler(list_t *member);
unsigned int countDigits(int num);
char *itoa(unsigned int num);
char *getErrorMessage();
void insertNullByte(char *str, unsigned int index);
void displayPrompt(void);
void displayNewLine(void);
void sigintHandler(int sigint);
int check_path(list_t *);
int tokenizer(list_t *member);
unsigned int count_words(char *s);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
linked_l *addNodeEnd(linked_l **head, char *str);
linked_l *generateLinkedList(char **array);
void free_members(list_t *member);
void free_args_line(list_t *member);
void free_args(char **args);
void free_list(linked_l *head);

#endif
