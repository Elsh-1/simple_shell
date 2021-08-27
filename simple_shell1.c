#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define delim " \n"

/**
 * main -
 * @prompt: to write a command
 * @split: splits the command into argument
 * @check: checks if the command is excutable
 * @execute: executes the command
 * @loop: loops
 * Return: 0
 */

char *prompt()
{
	char *cmnd;
	size_t cmndsize = 128;
	cmnd = (char *)malloc(128 * sizeof(char));
	printf("$ ");
	getline(&cmnd, &cmndsize, stdin);
	if (feof(stdin))
	{
		exit(-1);
	}
	
	return (cmnd);
}


char **split(char *str)
{
	char *token;
	char **total;
	int i;
	token = strtok(str, delim);
	total = malloc(64 * sizeof(char *));
	i = 0;
	
	while (token != NULL)
	{
		total[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	total[i] = NULL;
	return (total);
}


int execute(char **argu)
{
	pid_t pid;
	if (access(argu[0], X_OK))
	{
		perror("file not found");
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		execve(argu[0], argu, NULL);
		return (-1);
	}
	else
	{
		waitpid(pid, NULL, WUNTRACED);
	}
	return (0);
}

void loop(void)
{
	int status;
	char *cmd;
	char **args;
	do {
		cmd = prompt();
		args = split(cmd);
		status = execute(args);
       	} while (status != -1);
	return;
}
int main(void)
{
	loop();
	return (0);
}
