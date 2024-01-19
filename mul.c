#include "monty.h"
/**
 * multiply - multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: current line number being
 * executed in the monty file
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
