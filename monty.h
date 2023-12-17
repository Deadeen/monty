#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 */

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function Prototypes stack operations file*/
void push(stack_t **stack, const char *argument, unsigned int line_number);
void pall(stack_t **stack);

/* Function Prototypes main file*/
void process_file(FILE *file);
void free_stack(stack_t *head);
size_t getline(char **lineptr, size_t *n, FILE *stream);


#endif /* MONTY_H */
