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

	if (stack != NULL)
	{
		if (*stack == NULL)
		{
			str_val = -1;
			fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
			return;
		}
	}
	else
	{
		str_val = -1;
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		return;
	}
	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		return;
	}
	character = (char)value;
	printf("%c\n", character);
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
}
/**
 * opcode_pstr - prints n in ascii form
 * @stack: linked list
 * @line_number: unused variable
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	if (stack)
		if (*stack)
		{
			for (; (*stack)->next; *stack = (*stack)->next)
				if ((*stack)->n > 0 && (*stack)->n <= 127)
					printf("%c", (*stack)->n);
				else
					break;

		}
	(void)line_number;
	printf("\n");
}
/**
 * opcode_rotl - puts the top struct at the bottom
 * @stack: linked list
 * @line_number: uninitialized value
 */
void opcode_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *start, *end, *tmp;

	if (!stack)
		return;
	else if (!(*stack))
		return;

	end = start = *stack;
	tmp = start->next;

	while (end->next)
		end = end->next;
	tmp->prev = NULL;
	end->next = start;
	start->prev = end;
	start->next = NULL;
	*stack = tmp;

	(void)line_number;
}
/**
 * opcode_rotr - puts the bottom struct at the top
 * @stack: linked list
 * @line_number: uninitialized value
 */
void opcode_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *start, *end, *tmp;

	if (!stack)
		return;
	else if (!(*stack))
		return;
	if (!(*stack)->next)
		return;


	end = start = *stack;

	while (end->next)
		end = end->next;
	tmp = end->prev;
	end->prev = NULL;

	end->next = start;
	start->prev = end;
	tmp->next = NULL;
	*stack = end;

	(void)line_number;
}
