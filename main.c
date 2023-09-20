#include "monty.h"
/**
 *
 */
int main(int argc, char **argv)
{
	FILE *fd_stat = NULL;
	char *f_name = NULL;

	if (argc != 2)
		exit_fn(1);

	f_name = argv[1];

	fd_stat = fopen(f_name, "r");
	if (fd_stat == NULL)
		exit_fn(2);

	funct_select(fd_stat);
	return (0);
}
/**
 * exit_fn - exit functions (main didn't have space for write funct)
 * @exit_val: exit code for different values
 * Return: exit state (whether the program should exit or not) 
 */
int exit_fn(int exit_val)
{
	if (exit_val == 1)/* argc exit val */
		write(2, "USAGE: monty file\n", 18);
	else if (exit_val == 2)/* fd_stat exit */
	{
		write(2, "Error: Can't open file ", 23);
		write(2, argv[1], strlen(argv[1]));
		write(2, "\n", 1);
	}
	/* might add more depending on how we handle formatting and space */
	if (exit_val != 0)
		exit(EXIT_FAILURE);
}
/**
 * funct_select - selects the function to be used from struct array
 * @fd_stat: opened file from file descriptor
 * Return: not sure what to do with it (exit status most likely)
 */
int funct_select(FILE *fd_stat)
{
	stack_t *stack_l= NULL;
	int i = 0, ch_count = 0;
	char *buffer = NULL, buffercpy = NULL;
	/* format : {opcode_name , opcode_function} */
	instruction_t op_functs[] = {
	{"push", opcode_push}, {"pop", opcode_pop}, {"pall", opcode_pall},
	{"pint", opcode_pint}, {"swap", opcode_swap}, {"add", opcode_add},
	{"nop", opcode_nop}, {"sub", opcode_sub}, {"div", opcode_div},
	{"mul", opcode_mul}, {"mod", opcode_mod}, {"pchar", opcode_pchar}
	};
	/* ignore the chaos above its just a struct array */

	while (getline(&buffer, &ch_count, fd_stat) != -1)
	{
		buffercpy = malloc(ch_count + 1); /* copy to check entire sentence */
		/* current idea is to chek for more than 1 strtok items if the command is not push then free the sentence if its clear*/
		if (!buffercpy)
			free(buffer);/* also include a free for fd */
		/* opcode checking the entire line is where I'm currently stuck */
		for (; op_functs[i]; i++)
		{
			/* strcmp between strtok(buffer) & opcode condition*/
				/* op_functs.f if condition is true */

		}

	}
}
