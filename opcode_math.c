#include "monty.h"
#include <ctype.h>  // Include the ctype.h header

/**
 * pchar - Print the character at the top of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        free_all();
        exit(EXIT_FAILURE);
    }
    if (isascii((*stack)->n))  // Use isascii from ctype.h
    {
        printf("%c\n", (*stack)->n);
        return;
    }
    fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
    free_all();
    exit(EXIT_FAILURE);
}

/**
 * pstr - Print the string starting from the top of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    (void) line_number;

    if (!stack || !*stack)
    {
        putchar('\n');
        return;
    }
    while (tmp)
    {
        if (tmp->n == 0)
            break;
        if (!isascii(tmp->n))  // Use isascii from ctype.h
            break;
        putchar(tmp->n);
        tmp = tmp->next;
    }
    putchar('\n');
}
