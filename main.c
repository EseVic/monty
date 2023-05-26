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
	if (!file)
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
			if (exec_insts(op, &stack, inst_line) == EXIT_FAILURE)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", inst_line, op);
				free_stack(&stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			if (!line_is_empty(op))
				inst_line++;
		}
	}
	free_stack(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
