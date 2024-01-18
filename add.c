#include "monty.h"
/**
 * add -  adds the top two elements of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: line number on the monty file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int add;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	if (temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	add = (((*stack)->n) + (temp->n));
	temp->n = add;
	*stack = temp;
}
