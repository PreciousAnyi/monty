#include "monty.h"
/**
 * main - entry point to monty interpreter
 * @argc: argument counter
 * @argv: ponter to an array
 *
 * Return: EXIT_SUCCESS if execution is
 * successful or EXIT_FAILURE if not
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	execute_monty_file(argv[1]);
	return (EXIT_SUCCESS);
}
