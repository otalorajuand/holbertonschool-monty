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
	CHECK_FILE(file, argv);

	while (fgets(str, line_size, file) != NULL) /* Read line */
	{
		/* Remove last element of line (\n) */
		size_len = strlen(str);
		str[size_len - 1] = '\0';

		/* Interpret line */
		token = strtok(str, " ");
		if (token == NULL || token[0] == '#' || strcmp(token, "nop"))
		{
			line_number++;
			continue;
		}
		push_value = strtok(NULL, " ");

		/* Choose the function */
		func = get_built_in(token);
		CHECK_FUNC(func, line_number, token);

		/* Exectute the function */
		func(&stack, line_number);

		line_number++;
	}
	fclose(file);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
