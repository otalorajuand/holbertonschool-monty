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

/**
 * func_pchar - Prints the char at the top of the stack.
 * @stack: The stack
 * @line_number: the line number of the file
* Return: Nothing
 */

void func_pchar(stack_t **stack, unsigned int line_number)
{
	int c;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	c = (*(stack))->n;

	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", c);
}

/**
 * func_pstr - prints the string starting at the top of the stack.
 * @stack: The stack
 * @line_number: the line number of the file
* Return: Nothing
 */

void func_pstr(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	int c;
	stack_t *tmp = NULL;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = (*(stack));
	c = tmp->n;
	while (c != 0 || tmp == NULL || c < 0 || c > 127)
	{
		printf("%c", c);
		tmp = tmp->prev;
		c = tmp->n;
	}
	printf("\n");
}

