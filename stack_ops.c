#include "monty.h"

/** 
 * push - pushes an element to the stack
 * @stack: double pointer to head node
 * @value: value to be pushed
 */

void push(stack_t **stack, char *argument, unsigned int line_number)
{
	int value;
	stack_t *new_node;

	if (argument == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);
	if (value == 0 && *argument != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}


/**
 * pall - print values in stack from top down
 * @stack: double pointer to head node
 * @line_number: unused
 */

void pall(stack_t **stack)
{
	stack_t *current;

	if (*stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
