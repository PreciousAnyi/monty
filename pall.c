#include "monty.h"
/**
 * pall - prints all the values on the stack
 * @stack: the stack
 * @line_number: the current line number
 * on the monty file
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (*stack != NULL)
	{
		stack_t *current;

		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
