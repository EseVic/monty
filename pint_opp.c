#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: given stack
 * @inst_line: line number in the byte code
 */

void pint(stack_t **stack, unsigned int inst_line)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", inst_line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
