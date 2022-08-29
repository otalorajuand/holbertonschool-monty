#include "monty.h"


void func_push(stack_t **stack)
{
	stack_t *new = NULL;
	stack_t *current = NULL;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		free(new);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	new->n = 5;
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


void func_pall(stack_t **stack)
{
	stack_t *current = NULL;

	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", (*(stack))->n);
		current  = current->prev;
	}
}

