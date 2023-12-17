#include "monty.h"
#include <stdio.h>

/**
 * main - entry point for monty interpreter
 * @argc: argument count
 * @argv: argument vector (array of args)
 *
 * Return: exit status
 */

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    process_file(argv[1]);

    return (EXIT_SUCCESS);
}

/**
 * process_file - Processes the Monty bytecode file
 * @file_path: Path to the Monty bytecode file
 *
 */

void process_file(const char* file_path)
{
    FILE* file;
    char buffer[MAX_BUFFER_SIZE];
    int line_number;
    char* token;

    line_number = 1;

    file = fopen(file_path, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        token = strtok(buffer, " \n");
        if (token != NULL && token[0] != '#')
        {
            handle_instruction(token, NULL, line_number);
        }
        line_number++;
    }

    fclose(file);
}

/**
 * handle_instruction - Handles Monty bytecode instructions
 * @instruction: The instruction to be handled
 * @argument: The argument associated with the instruction (if any)
 * @line_number: The line number in the bytecode file
 *
 */

void handle_instruction(const char* instruction, const char* argument, int line_number)
{
    int value;

    if (strcmp(instruction, "push") == 0)
    {
        if (argument == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        value = atoi(argument);
        push(value);
    }
    else if (strcmp(instruction, "pall") == 0)
        pall();
    else if (strcmp(instruction, "pop") == 0)
        pop();
    else if (strcmp(instruction, "pint") == 0)
        pint(line_number);
    else if (strcmp(instruction, "swap") == 0)
        swap(line_number);
    else if (strcmp(instruction, "add") == 0)
        add(line_number);
    else if (strcmp(instruction, "nop") == 0)
        nop(line_number);
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
        exit(EXIT_FAILURE);
    }
}

