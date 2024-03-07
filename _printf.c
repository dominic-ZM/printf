#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * process_arguments - dispatches action on arguments based on format
 * @format: the format to follow
 * @args: variable number of arguments passed to the function
 * @count: how many characters were successfully printed
 *
 * Return: none
 */

void process_arguments(const char *format, va_list args, int *count)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
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
					break;
			}
		} else
			process_normal(*format, count);
		format++;
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

	count = 0;

	va_start(args, format);
	process_arguments(format, args, &count);
	va_end(args);
	return (count);
}
