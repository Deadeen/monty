#include "monty.h"

/**
 * main - entry point for monty interpreter
 * @argc: argument count
 * @argv: argument vector (array of args)
 *
 * Return: exit status
 */

int main(int argc, char *argv[])
{
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    process_file(file);

    fclose(file);
    return (EXIT_SUCCESS);
}

/**
 * process_file - file handling function
 * @file: file to be handled 
 *
 * Return: NULL
 */

void process_file(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number;
    stack_t *stack = NULL;
    int value;
    char *opcode, *argument;

    line_number = 0;
    
    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        opcode = strtok(line, " \n\t");
        if (opcode == NULL || opcode[0] == '#')
            continue;

        argument = strtok(NULL, " \n\t");

        if (strcmp(opcode, "push") == 0)
        {
            if (argument == NULL)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free(line);
                exit(EXIT_FAILURE);
            }
            value = atoi(argument);
            push(&stack, value);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            free(line);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    free_stack(stack);
}

void free_stack(stack_t *head)
{
    stack_t *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
