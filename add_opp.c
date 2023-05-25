#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: given stack
 * @inst_line: line number in the byte code
 */

void add(stack_t **stack, unsigned int inst_line)
{
	stack_t *top, *next;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", inst_line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	next = top->next;
	next->n += top->n;
	*stack = next;
	next->prev = NULL;
	free(top);
}
