#include "monty.h"
/**
 * pop - removes the top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: line number in the monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
}
