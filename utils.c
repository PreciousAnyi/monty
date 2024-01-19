#include "monty.h"
#define _POSIX_C_SOURCE 200809L
/**
 * is_integer - checks if a str is in number equivalent
 * @str: string
 *
 * Return: 0 if false or 1 if true
 */
int is_integer(const char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		i = 1;
	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * push_to_stack - adds a value to the stack
 * @stack: the stack
 * @value: data to be added to the stack
 */
void push_to_stack(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
/**
 * execute_monty_file - reads the monty file
 * @file_path: path to the file
 */
void execute_monty_file(const char *file_path)
{
	FILE *file;
	char *line;
	size_t len;
	stack_t *stack;
	unsigned int line_number;

	len = 0;
	line_number = 0;
	line = NULL;
	stack = NULL;
	file = fopen(file_path, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		execute_line(line, &stack, line_number);
	}
	free(line);
	free_stack(&stack);
	fclose(file);
}
/**
 * execute_line - executes the opcode in the line
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the monty file
 * @line: pointer to line where string is stored
 */
void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	int i;
	instruction_t instructions[15];

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;
	instructions[0].opcode = "push";
	instructions[0].f = push;
	instructions[1].opcode = "pall";
	instructions[1].f = pall;
	instructions[2].opcode = "pint";
	instructions[2].f = pint;
	instructions[3].opcode = "pop";
	instructions[3].f = pop;
	instructions[4].opcode = "swap";
	instructions[4].f = swap;
	instructions[5].opcode = "add";
	instructions[5].f = add;
	instructions[6].opcode = "nop";
	instructions[6].f = nop;
	instructions[7].opcode = "sub";
	instructions[7].f = sub;
	instructions[8].opcode = "div";
	instructions[8].f = divide;
	instructions[9].opcode = "mul";
	instructions[9].f = multiply;
	instructions[10].opcode = "mod";
	instructions[10].f = modulo;
	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
/**
 * free_stack - frees all allocated memory
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
