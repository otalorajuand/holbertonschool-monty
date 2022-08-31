#include "monty.h"


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
