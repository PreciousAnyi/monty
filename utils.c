#include "monty.h"
#define _POSIX_C_SOURCE 200809L
/**
 * is_number - checks if a str is in number equivalent
 * @str: string
 *
 * Return: 0 if false or 1 if true
 */
int is_integer(const char *str)
{
	int i;

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
		(*stack)->prev = new_node;
		new_node->next = *stack;
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
	ssize_t read;

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
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		execute_line(line, &stack, line_number);
	}
	free(line);
	fclose(file);
}
/**
 * execute_line - executes the opcode in the line
 * @line: string to tokenize
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the monty file
 */
void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	int i;
	instruction_t instructions[3];

	opcode = strtok(line, " \t\n");
	if (opcode == NULL)
		return;
	instructions[0].opcode = "push";
	instructions[0].f = push;
	instructions[1].opcode = "pall";
	instructions[1].f = pall;
	instructions[2].opcode = NULL;
	instructions[2].f = NULL;
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
