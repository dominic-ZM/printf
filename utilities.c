#include "main.h"

/**
 * process_char - handles %c flag
 * @c: the character to be printed
 * @count: number of characters printed so far
 *
 * Return: none
 */

void process_char(int c, int *count)
{
	if (c == '\0')
	{
		putchar(c);
		(*count)++;
		return;
	}

	output_char(c, count);
}

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
 * process_string - handles %s flag
 * @str: the string to be printed
 * @count: number of characters printed so far
 *
 * Return: none
 */

void process_string(char *str, int *count)
{
	if (str == NULL)
	{
		process_string("(null)", count);
		return;
	}
	while (*str)
		output_char(*str++, count);
}

/**
 * process_percent - handles the %% flag
 * @count: number of characters printed so far
 *
 * Return: none
 */

void process_percent(int *count)
{
	output_char('%', count);
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
