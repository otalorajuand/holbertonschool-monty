#include "monty.h"

/**
 * get_built_in - Selects the correct function to perform
 * the opcode in the monty file.
 * @s: The opcode passed as argument.
 * Return: A pointer to the function corresponding
 * to the opcode given as a parameter.
 */

void (*get_built_in(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t func[] = {
		{"push", func_push},
		{"pall", func_pall},
		{"pint", func_pint},
		{"pop", func_pop},
		{"swap", func_swap},
		{"add", func_add},
		{"nop", func_nop},
		{"sub", func_sub},
		{"div", func_div},
		{"mul", func_mul},
		{"mod", func_mod},
		{"pchar", func_pchar},
		{"pstr", func_pstr},
		{"rotl", func_rotl},
		{NULL, NULL},
	};

	int i = 0;

	while (func[i].opcode != NULL && strcmp(func[i].opcode, s) != 0)
		i++;

	return (func[i].f);  /* returns a function */
}
