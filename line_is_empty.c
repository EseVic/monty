#include "monty.h"

/**
 * line_is_empty - checks for an empty string
 * @str: given string
 * Return: 1 if @str is empty, 0 otherwise
 */
int line_is_empty(const char *str)
{
	while (*str)
	{
		if (!isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}
