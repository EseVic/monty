/**
 * get_op_func - test an opcode with its aligning function.
 * @opcode: The opcode to test.
 *
 * Return: None
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", match_push},
		{"pall", match_pall},
		{"pint", match_pint},
		{"pop", match_pop},
		{"swap", match_swap},
		{"add", match_add},
		{"nop", match_nop},
		{"sub", match_sub},
		{"div", match_div},
		{"mul", match_mul},
		{"mod", match_mod},
		{"pchar", match_pchar},
		{"pstr", match_pstr},
		{"rotl", match_rotl},
		{"rotr", match_rotr},
		{"stack", match_stack},
		{"queue", match_queue},
		{NULL, NULL}
	};
	int x;

	for (x = 0; op_func[x].opcode; x++)
	{
		if (strcmp(opcode, op_funcs[x].opcode) == 0)
			return (op_funcs[x].f);
	}

	return (NULL);
}
