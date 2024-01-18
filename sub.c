#include "monty.h"
/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: line number being executed on the monty file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	temp = (*stack)->next;
	pop(stack, line_number);
	free(temp);
}
