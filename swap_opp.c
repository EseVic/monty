#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: given stack
 * @inst_line: line number in the bytecode
 */

void swap(stack_t **stack, unsigned int inst_line)
{
	stack_t *top, *next;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", inst_line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	next = top->next;
	top->next = next->next;
	if (next->next != NULL)
		next->next->prev = top;
	next->prev = NULL;
	next->next = top;
	top->prev = next;
	*stack = next;
}
