#include "main.h"
#include <string.h>

/**
 * handle_char - prints a char argument
 * @args: va_list containing the char
 *
 * Return: number of characters printed
 */
int manager_char(va_list args)
{
	char c = (char)va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * manager_string - prints a string argument
 * @args: va_list containing the string
 *
 * Return: number of characters printed
 */
int manager_string(va_list args)
{
	char *char_ptr = va_arg(args, char *);
	int count = 0;

	if (char_ptr == NULL)
		char_ptr = "(null)";

	while (*char_ptr)
	{
		_putchar(*char_ptr++);
		count++;
	}
	return (count);
}

/**
 * manager_percent - prints a literal percent sign
 * @args: unused
 *
 * Return: 1
 */
int manager_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}

/**
 * print_number - prints an unsigned number recursively
 * @num: the unsigned number to print
 *
 * Return: number of characters printed
 */
int print_number(unsigned int num)
{
	int count = 0;

	if (num >= 10)
		count += print_number(num / 10);
	_putchar((num % 10) + '0');
	count++;
	return (count);
}

/**
 * manager_int - prints an integer argument
 * @args: va_list containing the integer
 *
 * Return: number of characters printed
 */
int manager_int(va_list args)
{
	int n;
	unsigned int num;
	int count = 0;

	n = va_arg(args, int);
	if (n < 0)
	{
		_putchar('-');
		count++;
		num = (unsigned int)-n;
	}
	else
	{
		num = (unsigned int)n;
	}
	count += print_number(num);
	return (count);
}

