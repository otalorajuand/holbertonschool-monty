#include "monty.h"

/**
 * get_built_in - Selects the correct function to perform
 * the format asked by the user.
 * @s: The format passed as argument.
 * Return: A pointer to the function corresponding
 * to the format given as a parameter.
 */

void (*get_built_in(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t func[] = {
		{"push", func_push},
		{"pall\n", func_pall},
		{NULL, NULL},
	};

	int i = 0;

	while (func[i].opcode != NULL && strcmp(func[i].opcode, s) != 0)
		i++;

	return (func[i].f);  /* returns a function */
}
