Project description:
This project is a simple shell program which is written in C language under
the Linux operating system and in Betty coding style.
This Shell works in 3 steps:
1. read the commands entered by the user
2. parse the line (to let the machine understand the commands)
3. execute the commands
This simple shell contains and supports a number of basic functions and commands
from various shell programs, that can be found in the PATH environment variable.

example:

int main()
{

	char *line;
	char **args;
	int status;

	do
	{
		printf("%s", "overwatch@root >");
		line = read();
		args = parse (line); /* args is an array of strings */
		status = execute(args);
		free(line);
		free(args);

		} while (status);

1- clone the reporsitory to your local directory:
https://github.com/Fares84/simple_shell.git

2- compile all c files:
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

3- execute the simple_shell:
$ ./hsh

COMMANDS
 Commands	   Description
 ls		   List directory contents
 pwd               Print the path of the current working directory
 printenv  	   Prints the name and values of the variables in environement
 help		   Displays information about shell built-in commands
 cd		   Change the current working directory
 echo		   Write arguments to the standard output
 rm		   Remove files or directories
 exit		   Exit the shell program

FILES
 File Name	   Description
 shell.h	   Header file
 main.c		   File that contains the main function
 READM.md          Readme file filled with informations about the program
 AUTHORS	   File indicating the authors of this program
 manual            Manual page for the simple_shell program
 builtins.c	   File where the code source of built_ins is located
 get_builtins.c    File that contains the get_builtins fucntion
 error_msg.c       File that contains the error messages
 prompt.c          File that contains the prompt fucntion
 path.c		   File that contains the PATH fucntion
 execute.c	   File that contains the execution fucntion
 environ.c	   File that contains the environment fucntion
 tokenizer.c	   File that contains a function to tokenize commands
 string_funcs1.c   File containing helper functions like "_strdup and _strlen.."
 string_funcs2.c   File containing helper functions like "_strdup and _strlen.."
 free_memory.c     File containing function that frees memory

We tried to recreate in this project shell() function and fill in with
the majority of its options and arguments in order to display them.

Authors:
Tsetseg Yondongombo
Fares SASSI
