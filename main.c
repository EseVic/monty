#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: arguments array
 *
 * Return: exit code of the running session
 */

int main(int argc, char *argv[])
{
	char *op;
	char line[MAX_LINE_LENGTH];
	FILE *file;
	stack_t *stack = NULL;
	unsigned int inst_line = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line[strcspn(line, "\n")] = '\0';
		op = strtok(line, " \t\r");
		if (op && op[0] != '#')
		{
			if (strcmp(op, "push") == 0)
				push(&stack, inst_line);
			else if (strcmp(op, "pall") == 0)
				pall(&stack);
			else if (strcmp(op, "pint") == 0)
				pint(&stack, inst_line);
			else if (strcmp(op, "pop") == 0)
				pop(&stack, inst_line);
			else if (strcmp(op, "add") == 0)
				add(&stack, inst_line);
			else if (strcmp(op, "nop") == 0)
				nop(&stack, inst_line);
			else if (strcmp(op, "sub") == 0)
				sub(&stack, inst_line);
			else if (strcmp(op, "mul") == 0)
				mul(&stack, inst_line);
			else if (strcmp(op, "mod") == 0)
				mod(&stack, inst_line);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", inst_line, op);
				free_stack(&stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
		inst_line++;
	}
	free_stack(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}

