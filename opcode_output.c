#include <stdio.h>
#include "monty.h"  // custom header file

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

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of ASCII range\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}

/**
 * pstr - Print a string of characters from the stack
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
		if (tmp->n <= 0 || tmp->n > 127)
			break;

		putchar(tmp->n);

		if (tmp->n == 0)
			break;

		tmp = tmp->next;
	}

	putchar('\n');
}
