#include "monty.h"

/**
 * func_add - adds the top two elements of the stack.
 * @stack: The stack
 * @line_number: the line number of the file
* Return: Nothing
 */

void func_add(stack_t **stack, unsigned int line_number)
{
	int len = 0;

	len = stack_len(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*(stack))->prev->n = (*(stack))->prev->n + (*(stack))->n;
	func_pop(stack, line_number);
}

/**
 * func_nop - Does not do anything
 * @stack: the stack
 * @line_number: the number of the line
* Return: anything
 */

void func_nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	return;
}

