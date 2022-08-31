#include "monty.h"

/**
 * func_push - Pushes and node to the stack
 * @stack: the stack
 * @line_number: The line number of the monty file
* Return: Nothing.
 */

void func_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	stack_t *current = NULL;
	int push_value_int;

	if (push_value == NULL || isNumeric(push_value) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	push_value_int = atoi(push_value);

	if (stack == NULL)
		exit(EXIT_FAILURE);

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		free(new);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	new->n = push_value_int;
	new->next = NULL;

	if (*stack == NULL)
	{
		*stack = new;
		(*(stack))->prev = current;
		return;
	}

	new->prev = current;
	current->next = new;
	*stack = new;
}

/**
 * func_pall - Prints all the elements of the stack
 * @stack: The stack
 * @line_number: The line number of the monty file
* Return: Nothing.
 */

void func_pall(stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *current = NULL;

	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current  = current->prev;
	}
}

/**
 * func_pint - Prints the top element of the stack
 * @stack: The stack
 * @line_number: The line number of the monty file
* Return: Nothing.
 */

void func_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*(stack))->n);
}

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

/**
 * func_swap - Swaps the two top element of the stack.
 * @stack: The stack
 * @line_number: The line number of the monty file
* Return: Nothing.
 */

void func_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int len = 0;

	len = stack_len(stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*(stack))->prev;
	tmp->next = *stack;
	tmp->prev = (*(stack))->prev;
	(*(stack))->prev = tmp;
	(*(stack))->next = NULL;
}

