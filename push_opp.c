#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: given stack
 * @inst_line: line number in the bytecode
 */

void push(stack_t **stack, unsigned int inst_line)
{
	char *arg = strtok(NULL, " \n\t\r");
	int value;
	stack_t *new;

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", inst_line);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = value;
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}

