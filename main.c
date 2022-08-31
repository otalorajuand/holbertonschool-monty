#include "monty.h"

char *push_value = NULL;

/**
 * main - Interpreter for Monty ByteCodes files.
 * @argc: arguments counter
 * @argv: arguments vector
* Return: 0 if success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char str[150], *token = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	int size_len = 0, line_size = 150;

	CHECK_ARG(argc);
	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(str, line_size, file) != NULL)
	{
		size_len = strlen(str);
		str[size_len - 1] = '\0';
		token = strtok(str, " ");
		if (token == NULL)
		{
			line_number++;
			continue;
		}
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
	return (EXIT_SUCCESS);
}
