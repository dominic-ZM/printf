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
 * process_signed_int - handles the d and i flags
 * @number: the integer to output
 * @count: number of characters printed
 *
 * Return: none
 */

void process_signed_int(int number, int *count)
{
	int index;
	int intermediate;
	char buffer[12];
	int is_int_min;

	index = 0;
	intermediate = 0;
	is_int_min = 0;
	if (number < 0)
	{
		output_char('-', count);
		if (number == INT_MIN)
		{
			number = INT_MAX;
			buffer[index] = 8 + '0';
			index++;
			is_int_min = 1;
		}
		else
			number = number * -1;
	}
	if (number == 0)
	{
		output_char('0', count);
		return;
	}
	while (number > 0)
	{
		intermediate = number % 10;
		number = number / 10;
		if (is_int_min)
		{
			is_int_min = 0;
			continue;
		}
		buffer[index++] = intermediate + '0';
	}
	index--;
	for (; index >= 0; index--)
		output_char(buffer[index], count);
}

/**
 * process_conv_unsigned_to_bin - argument is converted to binary
 * @number: the unsigned int to convert to binary
 * @count: tracks how many characters printed
 *
 * Return: none
 */

void process_conv_unsigned_to_bin(unsigned int number, int *count)
{
	int i;
	int binary[32];

	if (number == 0)
	{
		output_char('0', count);
		return;
	}
	i = 0;

	while (number > 0)
	{
		binary[i] = '0' + number % 2;
		number /= 2;
		i++;
	}
	i--;
	for (; i >= 0; i--)
		output_char(binary[i], count);
}
