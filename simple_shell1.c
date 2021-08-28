#include "inc.h"

#define delim " \n"

/**
 * prompt - prints prompt and gets user input
 * Return: char* to user input
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
/**
 * split - splits string using space char
 * @str: string to be splitted
 * Return: char ** or char* array of splitted string
 */


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

/**
 * execute - executes command after spliting has been done
 * @argu: arguments array for execution
 * Return: int status of the executed command
 */

int execute(char **argu)
{
	pid_t pid;
	char *bin_path;

	bin_path = malloc(246 * sizeof(char));
	if (_strncmp("/", argu[0], 1))
	{
		bin_path = _path(argu[0]);
		argu[0] = bin_path;
	} else if (access(argu[0], X_OK))
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
/**
 * loop - main loop for shell
 * Return: void so nothing
 */

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
}
/**
 * main - entry to program
 * Return: int
 */

int main(void)
{
	loop();
	return (0);
}
