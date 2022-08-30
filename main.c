#include "monty.h"

char *push_value = NULL;

int main(int argc, char *argv[])
{
	FILE *file;
	char str[50], *token = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(str, 50, file) != NULL)
	{
		if (str[0] == '\n')
		{
			line_number++;
			continue;
		}
		token = strtok(str, " ");
		func = get_built_in(token);
		if (func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}

		push_value = strtok(NULL, " ");
		func(&stack, line_number);
		line_number++;
	}
	fclose(file);
	free_stack(&stack);
	return (0);
}
