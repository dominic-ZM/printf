#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("Let's print a simple sentence.\n");
	len2 = printf("Let's print a simple sentence.\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		printf("len1: %d\nlen2: %d\n", len, len2);
		fflush(stdout);
		return (1);
	}
	return (0);
}
