#include "monty.h"

/**
 * pall - prints all values of a stack
 * @stack: given stack
 */

void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
