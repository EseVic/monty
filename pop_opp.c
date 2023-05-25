#include "monty.h"

/**
 * pop - removes the topmost element of a stack
 * @stack: given stack
 * @inst_line: line number in the bytecode
 */

void pop(stack_t **stack, unsigned int inst_line)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", inst_line);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
