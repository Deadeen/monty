#include "monty.h"

stack_t *stack = NULL;

/**
 * push - Pushes an element onto the stack
 * @value: The value to be pushed onto the stack
 *
 * This function creates a new node and adds it to the top of the stack
 * with the provided value.
 */

void push(int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;

	if (stack != NULL)
	{
		new_node->next = stack;
		stack->prev = new_node;
	}
	else
		new_node->next = NULL;

	stack = new_node;
}

/**
 * pall - Prints all elements in the stack
 *
 * This function prints all elements currently present in the stack.
 */

void pall()
{
	stack_t *temp = stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop - Pops an element from the stack
 *
 * This function removes the top element from the stack if it's not empty.
 */

void pop(int line_number)
{
	stack_t *temp = stack;
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	} 

	if (stack->next != NULL)
	{
		stack = stack->next;
		stack->prev = NULL;
	} 

	else
		stack = NULL;

	free(temp);
}

/**
 * pint - Prints the value at the top of the stack
 * @line_number: The line number in the bytecode file
 *
 */

void pint(int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", stack->n);
}

/**
 * swap - Swaps the top two elements of the stack
 * @line_number: The line number in the bytecode file
 *
 */

void swap(int line_number)
{
	int temp;

	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = stack->n;
	stack->n = stack->next->n;
	stack->next->n = temp;
}


/**
 * add - Adds the top two elements of the stack
 * @line_number: The line number in the bytecode file
 */

void add(int line_number)
{
	int sum;

	if (stack == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = stack->n + stack->next->n;
	pop();
	stack->n = sum;
}

/**
 * nop - Does nothing
 * @line_number: The line number in the bytecode file
 *
 */

void nop(int line_number)
{
	(void)line_number;
}


