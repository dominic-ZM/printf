#ifndef _MAIN
#define _MAIN

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

int _printf(const char *format, ...);
void process_arguments(const char *format, va_list args, int *count);
void output_char(int c, int *count);
void process_percent(int *count);
void process_string(char *str, int *count);
void process_normal(int c, int *count);
void process_char(int c, int *count);

#endif
