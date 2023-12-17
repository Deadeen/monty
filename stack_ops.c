#include "monty.h"

/** 
 * push - pushes an element to the stack
 * @stack: double pointer to head node
 * @line_number: current working line number
 */

void push(stack_t **stack, int value) {
    stack_t *new_node = malloc(sizeof(stack_t));
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

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
