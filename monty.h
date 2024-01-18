#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - Doubly linked list representation of a stack
 * @n: Integer data of the node
 * @prev: Pointer to the previous element of the stack
 * @next: Pointer to the next element of the stack
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its corresponding function
 * @opcode: The opcode
 * @f: Function to handle the opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void push_to_stack(stack_t **stack, int value);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
int is_integer(const char *str);
void execute_line(char *line, stack_t **stack, unsigned int line_number);
void execute_monty_file(const char *file_path);
void free_stack(stack_t **stack);
#endif
