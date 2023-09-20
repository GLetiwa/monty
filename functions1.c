#include "monty.h"

/**
 * opcode_push - pushes an element to the stack
 * @stack: pointer to a stack or queue
 * @value: value of the stack or queue
 */
void opcode_push(stack_t **stack, unsigned int value)
{
	stack_t *new;

	(void)value;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		str_val = -1;
		return;
	}
	new->n = str_val;
	new->prev = NULL;
	new->next = *stack;
	str_val = 0;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * opcode_pop - removes top element of the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line number being evaluated
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
	{
		str_val = -1;
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
	str_val = 0;
}

/**
 * opcode_pall - prints all the values of the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
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
 * opcode_pint -prints the value at the top of the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		str_val = -1;
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		return;
	}
	printf("%d\n", (*stack)->n);
	str_val = 0;
}

/**
 * opcode_swap - swaps the top 2 elements of the stack
 * @stack: pointer to a stack or queue
 * @line_number: current line being evaluated
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if ((*stack))
	{
		if (!(*stack)->next)
		{
			str_val = -1;
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
			return;
		}
	}
	else
	{
		str_val = -1;
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		return;
	}
	temp = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = temp;
	str_val = 0;
}

