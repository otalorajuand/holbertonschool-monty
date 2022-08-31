#include "monty.h"


/**
 * func_mod - Divides the top two elements of the stack.
 * @stack: The stack
 * @line_number: the line number of the file
* Return: Nothing
 */

void func_mod(stack_t **stack, unsigned int line_number)
{
	int len = 0;

	len = stack_len(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*(stack))->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*(stack))->prev->n = (*(stack))->prev->n % (*(stack))->n;
	func_pop(stack, line_number);
}

