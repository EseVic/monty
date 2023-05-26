#include "monty.h"

/**
 * exec_insts - executes the corresponding instruction based on op
 * @op: instruction to be executed
 * @stack: given stack
 * @inst_line: line number in the bytecode
 *
 * Return: exit status depending on validity of instruction
 */
int exec_insts(char *op, stack_t **stack, unsigned int inst_line)
{
	if (strcmp(op, "push") == 0)
		push(stack, inst_line);
	else if (strcmp(op, "pall") == 0)
		pall(stack);
	else if (strcmp(op, "pint") == 0)
		pint(stack, inst_line);
	else if (strcmp(op, "pop") == 0)
		pop(stack, inst_line);
	else if (strcmp(op, "add") == 0)
		add(stack, inst_line);
	else if (strcmp(op, "nop") == 0)
		nop(stack, inst_line);
	else if (strcmp(op, "sub") == 0)
		sub(stack, inst_line);
	else if (strcmp(op, "mul") == 0)
		mul(stack, inst_line);
	else if (strcmp(op, "mod") == 0)
		mod(stack, inst_line);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", inst_line, op);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
