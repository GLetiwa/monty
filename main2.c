#include "monty.h"
int str_val = 0;
/**
 * opcode_execute - executes the opcode function
 * @opcode: The opcode to execute
 * @stack: Pointer to the stack
 * @line_number: Current line number
 * Return: error status
 */
int opcode_execute(const char *opcode, stack_t **stack,
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
		if (opcode[0] == '#')
		{
			op_functs[6].f(stack, line_number);
			return (0);
		}
		if (strcmp(opcode, op_functs[i].opcode) == 0)
		{
			op_functs[i].f(stack, line_number);
			if (str_val == -1)
				return (-1);
			return (0);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (-1);
}

/**
 * bytecode_execute - executes monty bytecode from a file
 * @file: The bytecode file
 * @stack: Pointer to the stack
 * Return: error status
 */
int bytecode_execute(FILE *file, stack_t **stack)
{
	char *opcode, *opcode_cpy, *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	int rtn_v = 0;

	(void)opcode_cpy;
	while (getline(&line, &len, file) != -1)
	{
		if (is_push(line, line_number) == -1)
		{
			rtn_v = -1;
			break;
		}
		line_number++;
		opcode = strtok(line, " \n");
		if (!opcode)
			continue;
		else
		{
			/**
			* opcode_cpy = malloc(strlen(opcode) + 1);
			* strcpy(opcode_cpy, opcode);
			* strtok(opcode_cpy, " ");
			*/

			rtn_v = opcode_execute(opcode, stack, line_number);
			opcode = strtok(NULL, " \n");
			if (rtn_v != 0)
				break;

		}
	}
	if (line)
		free(line);
	return (rtn_v);
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
	int rtn = 0;

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
	rtn = bytecode_execute(file, &stack);
	free_list(&stack);
	fclose(file);
	return (rtn == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
/**
 * is_push - checks if opcode is push
 * @line: string to be copied and checked
 * @line_number: self explanatory
 * Return: -1 on malloc fail 0 on success
 */
int is_push(char *line, unsigned int line_number)
{
	char *line_cpy, *op_c;
	int l_n = line_number;

	line_cpy = malloc(strlen(line) + 1);

	if (!line_cpy)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		return (-1);
	}

	strcpy(line_cpy, line);
	op_c = strtok(line_cpy, " \n");
	if (strcmp(op_c, "push") == 0)
	{
		op_c = strtok(NULL, " \n");
		if (op_c != NULL)
			str_val = atoi(op_c);
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", (l_n == 0 ? 1 : l_n));
			free(line_cpy);
			return (-1);
		}
	}
	free(line_cpy);
	return (0);
}
/**
 * free_list - frees the linked list
 * @stack: linked list to be freed
 */
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
