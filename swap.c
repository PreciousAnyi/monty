#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: points to the top of the stack
 * @line_number: current line number in monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int swap;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	swap = temp->n;
	temp->n = (*stack)->n;
	(*stack)->n = swap;
}
