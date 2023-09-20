#include "monty.h"

/**
 * opcode_push - pushes an element to the stack
 * @stack: pointer to a stack or queue
 * @value: value of the stack or queue
 *
 */
void opcode_push(stack_t **stack, unsigned int value)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		return;
	}
	new->n = value;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * opcode _pop - removes top element of the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line number being evaluated
 *
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
		return;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
	(void)line_number;
}

/**
 * opcode_pall - prints all the values of the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
 *
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	current = (*stack);
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}

/**
 * opcode _pint -prints the value at the top of the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	       return;
	printf("%d\n", (*stack)->n);
	(void)line_number;
}

/**
 * opcode_swap - swaps the top 2 elements of the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if (*stack)
	{
	       if (!(*stack)->next)
			return;
	}
	else
		return;
	temp = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = temp;
	(void)line_number;
}

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
                        return;
	}
        else
                return;
	((*stack)->next)->n += (*stack)->n;
	opcode_pop(stack, line_number);
	(void)line_number;
}

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
                        return;
	}
        else
                return;
	((*stack)->next)->n -= (*stack)->n;
	opcode_pop(stack, line_number);
	(void)line_number;
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
			return;
	}
	else
		return;
	if ((*stack)->n == 0)
		return;
	((*stack)->next)->n /= (*stack)->n;
	 opcode_pop(stack, line_number);
	 (void)line_number;
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
			return;
	}
	else
		return;
	(*stack)->next->n *= (*stack)->n;
	opcode_pop(stack, line_number);
	(void)line_number;
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
                        return;
	}
        else
                return;
	if ((*stack)->n == 0)
		return;
        (*stack)->next->n %= (*stack)->n;
        opcode_pop(stack, line_number);
	(void)line_number;
}
