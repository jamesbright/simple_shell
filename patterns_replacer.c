#include "general.h"
#include "text.h"
#include "commands.h"

/**
 * replacement - replaces paterns with strings
 * @info: info
 * @index: index replacememt will start from
 * @string: string to use for replacement
 * Return: replaced string
 */

char *replacement(general_t *info, int *index, char *string)
{
	char *tmp;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		tmp = replace_env(info, string);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmp);
}

/**
 * replace_env - replaces environmental variable
 * @info: info
 * @environment: environment varaiable to use for replacement
 * Return: replaced env
 */

char *replace_env(general_t *info, char *environment)
{
	char *env;

	(void) info;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}

