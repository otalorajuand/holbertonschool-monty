#include "monty.h"


void func_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	stack_t *current = NULL;
	int value_cp = value;

	if (value_cp == 0)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (stack == NULL)
		exit(EXIT_FAILURE);

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		free(new);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	new->n = value_cp;
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


void func_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
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

