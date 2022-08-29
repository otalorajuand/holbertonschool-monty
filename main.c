#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char str[50], *token;
	void (*func)(stack_t **stack);
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(str, 50, file) != NULL)
	{
		token = strtok(str, " ");
		func = get_built_in(token);
		if (func == NULL)
		{
			printf("L<line_number>: unknown instruction %s\n", token);
			exit(EXIT_FAILURE);
		}
		func(&stack);
	}

	fclose(file);
	return (0);
}
