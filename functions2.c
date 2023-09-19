#include "monty.h"

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
