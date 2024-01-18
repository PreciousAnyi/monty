#include "monty.h"
/**
 * divide - divides the second top element of the
 * stack by the top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: current line number being executed in the monty file
 */
void divide(stack_t **stack, unsigned int line_number)
{
	 stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	temp = (*stack)->next;
	pop(stack, line_number);
	free(temp);
}
