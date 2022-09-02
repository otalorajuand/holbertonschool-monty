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
 * func_sub - substract the top two elements of the stack.
 * @stack: The stack
 * @line_number: the line number of the file
* Return: Nothing
 */

void func_sub(stack_t **stack, unsigned int line_number)
{
	int len = 0;

	len = stack_len(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*(stack))->prev->n = (*(stack))->prev->n - (*(stack))->n;
	func_pop(stack, line_number);
}

/**
 * func_div - Divides the top two elements of the stack.
 * @stack: The stack
 * @line_number: the line number of the file
* Return: Nothing
 */

void func_div(stack_t **stack, unsigned int line_number)
{
	int len = 0;

	len = stack_len(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*(stack))->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*(stack))->prev->n = (*(stack))->prev->n / (*(stack))->n;
	func_pop(stack, line_number);
}

/**
 * func_mul - Multiplies the top two elements of the stack.
 * @stack: The stack
 * @line_number: the line number of the file
* Return: Nothing
 */

void func_mul(stack_t **stack, unsigned int line_number)
{
	int len = 0;

	len = stack_len(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*(stack))->prev->n = (*(stack))->prev->n * (*(stack))->n;
	func_pop(stack, line_number);
}
