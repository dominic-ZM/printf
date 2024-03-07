#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format.
 * @format: the format to follow
 * @...: variable number of arguments passed to the function
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count;
	char *str;

	count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += putchar(va_arg(args, int));
					break;
				case 's':
				{
					str = va_arg(args, char *);
					while (*str)
					{
						count += putchar(*str);
						str++;
					}
				}
					break;
				case '%':
					count += putchar('%');
					break;
				default:
					count += putchar('%');
					count += putchar(*format);
			}
		} else
			count += putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
