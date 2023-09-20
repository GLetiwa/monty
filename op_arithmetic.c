#include "monty.h"

/**
 * opcode_add - adds the top 2 elements fo the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		if (!(*stack)->next)
		{
			str_val = -1;
			fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
			return;
		}
	}
	else
	{
		str_val = -1;
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		return;
	}

	((*stack)->next)->n += (*stack)->n;
	opcode_pop(stack, line_number);
	str_val = 0;
}
/**
 * opcode_sub - subtracts the top 2 elements of the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		if (!(*stack)->next)
		{
			str_val = -1;
			fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
			return;
		}
	}
	else
	{
		str_val = -1;
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		return;
	}
	((*stack)->next)->n -= (*stack)->n;
	opcode_pop(stack, line_number);
	str_val = 0;
}

/**
 * opcode_div - divides the top 2 second elements of the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		if (!(*stack)->next)
		{
			str_val = -1;
			fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
			return;
		}
	}
	else
	{
		str_val = -1;
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		return;
	}
	if ((*stack)->n == 0)
	{
		str_val = -1;
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return;
	}
	((*stack)->next)->n /= (*stack)->n;
	opcode_pop(stack, line_number);
	str_val = 0;
}

/**
 * opcode_mul - divides the top 2 elements of the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		if (!(*stack)->next)
		{
			str_val = -1;
			fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
			return;
		}
	}
	else
	{
		str_val = -1;
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		return;
	}
	(*stack)->next->n *= (*stack)->n;
	opcode_pop(stack, line_number);
	str_val = 0;
}

/**
 * opcode_mod - computes the division of the second top
 * element of the stack by the top element
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		if (!(*stack)->next)
		{
			str_val = -1;
			fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
			return;
		}
	}
	else
	{
		str_val = -1;
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		return;
	}
	if ((*stack)->n == 0)
	{
		str_val = -1;
		fprintf(stderr, "L%u: division by zero\n", line_number);
		return;
	}
	(*stack)->next->n %= (*stack)->n;
	opcode_pop(stack, line_number);
	str_val = 0;
}
