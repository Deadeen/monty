#include "monty.h"

/** 
 * push - pushes an element to the stack
 * @stack: double pointer to head node
 * @value: value to be pushed
 */

void push(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (*stack == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;  
		*stack = new_node;
	}

	else
	{
		new_node->n = value;
		new_node->prev = NULL;
		new_node->next = *stack;
		*stack = new_node;
	}

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
