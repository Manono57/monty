#include "monty.h"

/**
 * rotl - Rotate the stack to the top
 * @stack: Double linked list
 * @line_number: File line execution
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *tm = *stack;
    (void) line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;
    (*stack)->next->prev = NULL;
    while (tm->next)
        tm = tm->next;
    tm->next = *stack;
    (*stack) = (*stack)->next;
    tm->next->next = NULL;
    tm->next->prev = tm;
}

/**
 * rotr - Rotate the stack to the bottom
 * @stack: Double linked list
 * @line_number: File line execution
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    (void) line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    tmp = *stack;
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = *stack;
    tmp->prev->next = NULL;
    tmp->prev = NULL;

    (*stack)->prev = tmp;
    *stack = tmp;
}

/**
 * stack - Set the stack mode (LIFO)
 * @stack: Double linked list
 * @line_number: File line execution
 */
void stack(stack_t **stack, unsigned int line_number)
{
    (void) line_number;
    (void) stack;

    var.MODE = 0;
}

/**
 * queue - Set the queue mode (FIFO)
 * @stack: Double linked list
 * @line_number: File line execution
 */
void queue(stack_t **stack, unsigned int line_number)
{
    (void) line_number;
    (void) stack;

    var.MODE = 1;
}
