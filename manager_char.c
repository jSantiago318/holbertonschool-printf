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

/**
 * print_hex - prints an unsigned number in hexadecimal
 * @num: the unsigned number to print
 * @uppercase: 1 for uppercase (A-F), 0 for lowercase (a-f)
 *
 * Return: number of characters printed
 */
int print_hex(unsigned int num, int uppercase)
{
	int count = 0;
	char *hex_lower = "0123456789abcdef";
	char *hex_upper = "0123456789ABCDEF";
	char *hex = uppercase ? hex_upper : hex_lower;

	if (num >= 16)
		count += print_hex(num / 16, uppercase);
	_putchar(hex[num % 16]);
	count++;
	return (count);
}

/**
 * manager_hex - prints an unsigned integer in hexadecimal
 * @args: va_list containing the unsigned integer
 * @uppercase: 1 for uppercase, 0 for lowercase
 *
 * Return: number of characters printed
 */
int manager_hex(va_list args, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_hex(num, uppercase));
}

/**
 * manager_pointer - prints a pointer address in hexadecimal
 * @args: va_list containing the pointer
 *
 * Return: number of characters printed
 */
int manager_pointer(va_list args)
{
	unsigned long ptr = (unsigned long)va_arg(args, void *);
	int count = 0;

	_putchar('0');
	_putchar('x');
	count += 2;

	if (ptr == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		count += print_hex_pointer(ptr);
	}
	return (count);
}

/**
 * print_hex_pointer - prints pointer in hex (helper for pointers)
 * @num: the address to print in hex
 *
 * Return: number of characters printed
 */
int print_hex_pointer(unsigned long num)
{
	int count = 0;
	char *hex = "0123456789abcdef";

	if (num >= 16)
		count += print_hex_pointer(num / 16);
	_putchar(hex[num % 16]);
	count++;
	return (count);
}

