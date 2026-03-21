#include "main.h"
#include <string.h>

/**
 * manager_char - prints a char argument
 * @args: va_list containing the char
 *
 * Return: number of characters printed
 */
int manager_char(va_list args)
{
	/*
	 * Sacamos el valor como int (C promueve char a int en va_arg),
	* luego lo casteamos de regreso a char
	*/
	char c = (char)va_arg(args, int);

	/* Imprimimos el caracter */
	_putchar(c);

	/* %c siempre imprime exactamente 1 caracter */
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
	/* Sacamos el puntero al string del va_list */
	char *char_ptr = va_arg(args, char *);

	/* Contador de caracteres impresos */
	int count = 0;

	/* Si el puntero es NULL, usamos "(null)" en vez de crashear */
	if (char_ptr == NULL)
		char_ptr = "(null)";

	/* Iteramos mientras el caracter actual no sea '\0' (fin del string) */
	while (*char_ptr)
	{
		/* Imprimimos el caracter actual y avanzamos el puntero (postfijo) */
		_putchar(*char_ptr++);

		/* Contamos cada caracter impreso */
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
	/*
	* Le decimos al compilador que args no se usa a proposito
	 * para evitar el warning de -Wextra
	 */
	(void)args;

	/* %% en el format imprime un solo % */
	_putchar('%');

	/* Solo imprimimos 1 caracter */
	return (1);
}

/**
 * manager_pointer - prints a pointer address in hexadecimal
 * @args: va_list containing the pointer
 *
 * Return: number of characters printed
 */
int manager_pointer(va_list args)
{
	/*
	* Sacamos el puntero como void* (tipo generico) y casteamos
	 * a unsigned long para poder hacer aritmetica con la direccion
	 */
	unsigned long ptr = (unsigned long)va_arg(args, void *);
	int count = 0;

	/* Los punteros siempre llevan el prefijo "0x" */
	_putchar('0');
	_putchar('x');

	/* Contamos esos 2 caracteres del prefijo */
	count += 2;

	if (ptr == 0)
	{
		/*
		* Caso especial NULL: sin este check, print_hex_pointer
		 * no imprimiria nada para el 0 y quedaria solo "0x"
		 */
		_putchar('0');
		count++;
	}
	else
	{
		/* Para cualquier otra direccion usamos el helper de punteros */
		count += print_hex_pointer(ptr);
	}
	return (count);
}


/**
 * manager_unsigned - prints an unsigned integer
 * @args: va_list containing the unsigned integer
 *
 * Return: number of characters printed
 */
int manager_unsigned(va_list args)
{
	/* Sacamos el valor como unsigned int, nunca habra signo negativo */
	unsigned int num = va_arg(args, unsigned int);

	/*
	* A diferencia de manager_int, no hay chequeo de signo.
	 * %u trata los bits del valor como siempre positivo
	 */
	return (print_number(num));
}
