#include "monty.h"
int str_val = 0;
/**
 * opcode_execute - executes the opcode function
 * @opcode: The opcode to execute
 * @stack: Pointer to the stack
 * @line_number: Current line number
 */
void opcode_execute(const char *opcode, stack_t **stack,
		unsigned int line_number)
{
	size_t i = 0;

	instruction_t op_functs[] = {
	{"push", opcode_push},
	{"pop", opcode_pop},
	{"pall", opcode_pall},
	{"pint", opcode_pint},
	{"swap", opcode_swap},
	{"add", opcode_add},
	{"nop", opcode_nop},
	{"sub", opcode_sub},
	{"div", opcode_div},
	{"mul", opcode_mul},
	{"mod", opcode_mod},
	{"pchar", opcode_pchar},
	{NULL, NULL}
	};
	for (i = 0; op_functs[i].opcode; i++)
	{
		if (strcmp(opcode, op_functs[i].opcode) == 0)
		{
			op_functs[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * bytecode_execute - executes monty bytecode from a file
 * @file: The bytecode file
 * @stack: Pointer to the stack
 */
void bytecode_execute(FILE *file, stack_t **stack)
{
	char *opcode, *opcode_cpy, *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	(void)opcode_cpy;
	while (getline(&line, &len, file) != -1)
	{
		is_push(line);
		line_number++;
		opcode = strtok(line, " \n");
		if (!opcode)
			continue;
		else
		{
			/*opcode_cpy = malloc(strlen(opcode) + 1);
			strcpy(opcode_cpy, opcode);
			strtok(opcode_cpy, " "); */

			opcode_execute(opcode, stack, line_number);
			opcode = strtok(NULL, " \n");

		}
	}
	if (line)
		free(line);
}
/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: exit status
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	bytecode_execute(file, &stack);
	free_list(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
void is_push(char *line)
{
	char *line_cpy, *op_c;

	line_cpy = malloc(strlen(line) + 1);

	if (!line_cpy)
		return;

	strcpy(line_cpy, line);
	op_c = strtok(line_cpy, " ");
	if (strcmp(op_c, "push") == 0)
	{
		op_c = strtok(NULL, " \n");
		str_val = atoi(op_c);
	}
	free(line_cpy);
}
void free_list(stack_t **stack)
{
	stack_t *tmp, *head;

	if (!stack)
		return;
	head = *stack;

	if (!head)
		return;
	while (head->prev)
		head = head->prev;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}


}
