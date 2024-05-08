#include "main.h"

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
