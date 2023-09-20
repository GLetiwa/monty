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
