#include "monty.h"

/**
 * opcode_pchar - changes the n value to a char
 * @stack: linked list
 * @line_number: line number
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
	(void)line_number;
}
#include "monty.h"
/**
 * opcode_nop - does nothing
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	return;

}

