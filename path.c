#include "inc.h"

#define del ":"

/**
 * search - gets path from binary name
 * @bin:the name of the binary in question
 * @path_arr: all the paths avilible
 * Return: char* to the full path name if found and NULL if not
 */
char *search(char *bin, char **path_arr)
{
	char *full_path;
	char *temp_path;

	full_path = NULL;

	for (; *path_arr; path_arr++)
	{
		temp_path = malloc(_strlen(*path_arr) + _strlen(bin) + 2);
		_strcpy(temp_path, *path_arr);
		_strcat(temp_path, "/");
		_strcat(temp_path, bin);
		if (!access(temp_path, X_OK))
		{
			full_path = temp_path;
		}
	}
	return (full_path);
}
/**
 * split_path - splits path in to directoreis
 * @str: the whole path
 * Return: char* to the full path name if found and NULL if not
 */
char **split_path(char *str)
{
	char *token;
	char **total;
	int i;

	token = strtok(str, del);
	total = malloc(64 * sizeof(char *));
	i = 0;
	while (token != NULL)
	{
		total[i] = token;
		i++;
		token = strtok(NULL, del);
	}
	total[i] = NULL;
	return (total);
}
/**
 * _path - gets path from binary name
 * @bin_name:the name of the binary in question
 * Return: char* to the full path name if found and NULL if not
 */

char *_path(char *bin_name)
{
	char *path;
	char *bin_path;
	char **dirs;

	path = _getenv("PATH");
	dirs = split_path(path + 5);
	bin_path = search(bin_name, dirs);
	return (bin_path);
}
