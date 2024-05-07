#include "main.h"

/**
 * process_normal - handles normal chars
 * @c: the char to be handled
 * @count: how many characters printed so far
 *
 * Return: none
 */

void process_normal(int c, int *count)
{
	output_char(c, count);
}

/**
 * output_char - prints the specified char
 * @c: the specified char
 * @count: number of characters printed so far
 *
 * Return: none
 */

void output_char(int c, int *count)
{
		if (putchar(c))
			(*count)++;
}

/**
 * process_unsignend_int - handles the d and i flags
 * @number: the integer to output
 * @count: number of characters printed
 *
 * Return: none
 */
