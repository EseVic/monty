#include "monty.h"

/**
 * is_integer - checks if a string represents a valid integer
 * @str: given string
 *
 * Return: true if true, false otherwise
 */

bool is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (false);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

