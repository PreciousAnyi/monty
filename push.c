#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int value;

	token = strtok(NULL, " \t\n");
	if (token == NULL || !is_integer(token))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(token);
	push_to_stack(stack, value);
}
