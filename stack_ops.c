#include "monty.h"

stack_t *stack;

stack = NULL;

/**
 * push - Pushes an element onto the stack
 * @value: The value to be pushed onto the stack
 *
 * This function creates a new node and adds it to the top of the stack
 * with the provided value.
 */

void push(int value)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
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
    stack_t *temp;

    temp = stack;
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

void pop()
{
	stack_t *temp;

    if (stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = stack;
    stack = stack->next;

    if (stack != NULL)
    	stack->prev = NULL;

    free(temp);
}