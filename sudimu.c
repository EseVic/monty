#include "monty.h"

/**
 * sub - sub the top two elements of the stack.
 * @stack: given stack
 * @inst_line: line number in the byte code
 */

void sub(stack_t **stack, unsigned int inst_line)
{
	stack_t *top, *next;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", inst_line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	next = top->next;
	next->n -= top->n;
	*stack = next;
	next->prev = NULL;
	free(top);
}


/**
 * mul - mul the top two elements of the stack.
 * @stack: given stack
 * @inst_line: line number in the byte code
 */

void mul(stack_t **stack, unsigned int inst_line)
{
	stack_t *top, *next;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", inst_line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	next = top->next;
	next->n *= top->n;
	*stack = next;
	next->prev = NULL;
	free(top);
}


/**
 * mod - mod the top two elements of the stack.
 * @stack: given stack
 * @inst_line: line number in the byte code
 */

void mod(stack_t **stack, unsigned int inst_line)
{
	stack_t *top, *next;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", inst_line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	next = top->next;
	next->n %= top->n;
	*stack = next;
	next->prev = NULL;
	free(top);
}
