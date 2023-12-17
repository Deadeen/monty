#include "monty.h"

void process_file(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    FILE *file = fopen(argv[1], "r");

    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        char *opcode, *argument;
        opcode = strtok(line, " \n\t");
        if (opcode == NULL || opcode[0] == '#')
            continue;

        argument = strtok(NULL, " \n\t");

        if (strcmp(opcode, "push") == 0)
        {
            if (argument == NULL || !isdigit(*argument))
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                free(line);
                exit(EXIT_FAILURE);
            }
            int value = atoi(argument);
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

/**
 * main - entry point for monty interpreter
 * @argc: argument count
 * @argv: argument vector (array of args)
 *
 * Return: exit status
 */

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    process_file(file);

    fclose(file);
    return (0);
}

void free_stack(stack_t *head)
{
    stack_t *tmp;

    if(!head)
        return;

    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
