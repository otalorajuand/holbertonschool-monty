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
	while (tmp != NULL && c > 0 && c < 127)
	{
		printf("%c", c);
		tmp = tmp->prev;
		if (tmp != NULL)
			c = tmp->n;
	}
	printf("\n");
}


/**
 * func_rotl - rotates the stack to the top.
 * @stack: The stack
 * @line_number: the line number of the file
* Return: Nothing
 */

void func_rotl(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{

	int len = 0;
	stack_t *tmp_top = NULL, *current = NULL, *top_prev = NULL;

	len = stack_len(stack);
	if (len <= 1)
	{
		return;
	}


	tmp_top = *stack;
	current = *stack;
	top_prev = (*(stack))->prev;

	while (current->prev != NULL)
		current = current->prev;

	tmp_top->next = current;
	current->prev = tmp_top;
	tmp_top->prev = NULL;
	*stack = top_prev;
	(*(stack))->next = NULL;
}

/**
 * func_rotr - rotates the stack to the bottom.
 * @stack: The stack
 * @line_number: the line number of the file
* Return: Nothing
 */

void func_rotr(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{

	int len = 0;
	stack_t *first_node = NULL;

	len = stack_len(stack);
	if (len <= 1)
	{
		return;
	}

	first_node = *stack;

	while (first_node->prev != NULL)
		first_node = first_node->prev;

	first_node->next->prev = NULL;
	first_node->next = NULL;
	first_node->prev = *stack;
	*stack = first_node;
}
