#include "monty.h"

/**
 * free_stack - Delets the stack
 * @stack: The stack
* Return: Nothing.
 */

void free_stack(stack_t **stack)
{
	stack_t *current = NULL;

	while (*stack != NULL)
	{
		current = (*(stack))->prev;
		free(*stack);
		*stack = current;
	}
}

/**
 * isNumeric - Checks if a string have only numeric digits
 * @str: The string
* Return: 1 if true, 0 if false
 */

int isNumeric(const char *str)
{
	while (*str != '\0')
	{
		if ((*str < '0' || *str > '9') && *str != '\n' &&
			*str != '-')
			return (0);
		str++;
	}

	return (1);
}

/**
 * stack_len - Calculates the length of a stack
 * @stack: The stack
* Return: The length of the stack
 */

int stack_len(stack_t **stack)
{
	int len = 0;
	stack_t *tmp = NULL;

	tmp = *stack;
	while (tmp != NULL)
	{
		tmp = tmp->prev;
		len++;
	}
	return (len);
}
