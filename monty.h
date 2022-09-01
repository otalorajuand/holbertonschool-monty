#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *push_value;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define CHECK_ARG(ARGC) \
do { \
	if (ARGC != 2) \
	{ \
		fprintf(stderr, "USAGE: monty file\n"); \
		exit(EXIT_FAILURE); \
	} \
} while (0)

void func_push(stack_t **stack, unsigned int line_number);
void func_pall(stack_t **stack, unsigned int line_number);
void func_nop(stack_t **stack, unsigned int line_number);
void func_swap(stack_t **stack, unsigned int line_number);
void func_add(stack_t **stack, unsigned int line_number);
void func_sub(stack_t **stack, unsigned int line_number);
void func_div(stack_t **stack, unsigned int line_number);
void func_rotr(stack_t **stack, unsigned int line_number);
void func_rotl(stack_t **stack, unsigned int line_number);
void func_mod(stack_t **stack, unsigned int line_number);
void func_pchar(stack_t **stack, unsigned int line_number);
void func_mul(stack_t **stack, unsigned int line_number);
void func_pint(stack_t **stack, unsigned int line_number);
void func_pstr(stack_t **stack, unsigned int line_number);
void func_pop(stack_t **stack, unsigned int line_number);
void (*get_built_in(char *s))(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
int isNumeric(const char *str);
int stack_len(stack_t **stack);

#endif /* _MONTY_H_ */
