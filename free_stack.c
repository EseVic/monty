#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: double pointer to the stack
 *
 * Description: This function frees all the nodes in the stack.
 * It sets the stack pointer to NULL.
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
