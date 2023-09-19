#include "monty.h"

/**
 *
 *
 */
void opcode_push(stack_t **stack, int value)
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
 *
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
 *
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
 *
 *
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	       return;
	printf("%d\n", (*stack)->n);
	(void)line_number;
}

/**
 *
 *
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
 *
 *
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
 *
 *
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	
	return;

}

/**
 *
 *
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
 *
 *
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
 *
 *
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
 *
 *
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
