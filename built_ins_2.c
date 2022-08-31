#include "monty.h"

/**
 * func_pop - Removes the top element of the stack.
 * @stack: The stack
 * @line_number: The line number of the monty file
* Return: Nothing.
 */

void func_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*(stack))->prev;
	free(tmp);
}


