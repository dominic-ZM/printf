#include "main.h"

/**
 ** handle_backslash - dispatches action on arguments based on format
 ** @format: the format to follow
 ** @count: how many characters were successfully printed
 **
 ** Return: none
 **/

void handle_backslash(const char *format, int *count)
{
	int i;

	int escape_nums[] = {7, 8, 12, 10, 13, 9, 11, 92, 39, 34, 63, 0};
	char *escape_chars = "abfnrtv\\'\"?0";

	if (*format == '\0')
		return;

	i = 0;

	while (*escape_chars)
	{
		if (*format == *escape_chars)
		{
			process_char(escape_nums[i], count);
			return;
		}
		escape_chars++;
		i++;
	}
}

/**
 * handle_percent - dispatches action on arguments based on format
 * @format: the format to follow
 * @args: arguments passed to the function
 * @count: how many characters were successfully printed
 *
 * Return: none
 */

void handle_percent(const char *format, va_list args, int *count)
{
	if (*format == '\0')
		return;
	switch (*format)
	{
		case 'c':
			process_char(va_arg(args, int), count);
			break;
		case 's':
			process_string(va_arg(args, char *), count);
			break;
		case '%':
			process_percent(count);
			break;
		default:
			process_percent(count);
			break;
	}
}

/**
 * _printf - produces output according to a format.
 * @format: the format to follow
 * @...: variable number of arguments passed to the function
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int count;
	va_list args;

	if (format == NULL)
		return (-1);
	count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_percent(format, args, &count);
		}
		if (*format == 92)
		{
			format++;
			handle_backslash(format, &count);
		}
		process_normal(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
