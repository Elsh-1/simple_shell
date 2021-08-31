#include "inc.h"
/**
 * handle_piped - handle piped commands
 * Return: nothing , exits if something is wrong
 */

void handle_piped(void)
{
	char *cmnd;
	size_t cmndsize = 128;
	int siz;
	char **args;

	cmnd = (char *)malloc(128 * sizeof(char));
	while (1)
	{
		siz = getline(&cmnd, &cmndsize, stdin);
		if (siz == -1)
			exit(0);
		args = split(cmnd);
		execute(args);
	}

	exit(0);
}
