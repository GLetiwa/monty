#include "monty.h"

/*int is_stack_mode = 1;

void opcode_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	is_stack_mode = 1;
}

void opcode_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	is_stack_mode = 0;
} */


/**
 *
 *
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	int value;
	char character;
	
	if (*stack == NULL)
		return;
	value = (*stack)->n;
	if (value < 0 || value > 127)
		return;
	character = (char)value;
	printf("%c\n", character);
}
