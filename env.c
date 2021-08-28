#include "inc.h"

/**
 * _getenv - Gets an environmental variable.
 * @var: environ to get
 *
 * Return: char* to env var or NULL if not found
 */
char *_getenv(const char *var)
{
	int i, len;
	char *env;

	len = _strlen(var);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var, environ[i], len) == 0)
		{
			env = malloc(246 * sizeof(char));
			_strcpy(env, environ[i]);
			return (env);
		}
	}

	return (NULL);
}
