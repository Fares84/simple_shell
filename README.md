<p align="center">
  <img width="409" height="128" src="https://www.holbertonschool.com/holberton-logo.png">
</p>

# Simple Shell Project


## Project description:

This repository contains C program for **Simple Shell** written as part of the **Low-level programming and Algorithm** project at **Holberton School**. The program is the implementation of a command-line interpreter (Shell) that provides user interface for operating systems.

### Betty coding style:

All files are written in C and follows the Betty coding style for Holberton School. For more detail, check this page:

[Betty style documentation](https://github.com/holbertonschool/Betty/wiki)


### Compilation:

All files will be compiled with gcc 4.8.4 using the flags:  -Wall -Werror -Wextra -pedantic

    gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

### Run the program

#### Interactively

./hsh and enter commands with or without arguments after the prompt **Shellock_Holmes$**.

#### Non-Interactively

Send the command though pipe
**echo "ls -la" | ./hsh**

## Files Description
- **shell.h**	   Contains protypes
- **main.c**	      Contains the main function
- **README.md**	          Descitpion of the repo
- **AUTHORS**			  	         Contributors of the program
- **Manual**					 	          Manual page
- **builtins.c**						     Contains built-ins
- **get_builtins.c**						        Contains get_builtins function
- **error_msg.c**							   Contains the function handling errors
- **prompt.c**								   	       Contains helper functions
- **path.c**									       		   Contains functions handlint path
- **execute.c**												      Contains functions handling execution
- **environ.c**													         Contains functions related to environment
- **tokenizer.c**														    Contains functions handling command-line argument parsing
- **string_funcs.c**														       Contains functions handling strings
- **free_memory.c**														       		   Contains functions handling memory

## Examples:
```c
./hsh
Shellock_holmes$ pwd
/home/vagrant/simple_shell
```
```c
Shellock_holmes$ /bin/ls
AUTHORS      free_memory.c   manual	  string_funcs1.c
builtins.c   get_builtins.c  path.c	      string_funcs2.c
environ.c    holberton.h     prompt.c	            tokenizer.c
error_msg.c  hsh
execute.c    main.c			       README.md
```
```c
Shellock_holmes$ exit
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$
```
```c
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
```

## Authors
Tsetseg Yondongombo
Fares SASSI