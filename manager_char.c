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
	/* Sacamos el valor como int (C promueve char a int en va_arg),
	 * luego lo casteamos de regreso a char */
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
	/* Le decimos al compilador que args no se usa a proposito
	 * para evitar el warning de -Wextra */
	(void)args;

	/* %% en el format imprime un solo % */
	_putchar('%');

	/* Solo imprimimos 1 caracter */
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
	/* Acumulador de digitos impresos */
	int count = 0;

	/* Si el numero tiene mas de 1 digito, primero imprimimos los anteriores.
	 * Ejemplo: 347 llama con 34, que llama con 3, imprime 3, luego 4, luego 7 */
	if (num >= 10)
		count += print_number(num / 10);

	/* num % 10 da el ultimo digito. Sumarle '0' (ASCII 48) lo
	 * convierte al caracter correcto: 7 + '0' = '7' */
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
	/* n guarda el valor original con signo */
	int n;

	/* num guarda la version sin signo para pasarla a print_number */
	unsigned int num;

	/* Contador total incluyendo el '-' si aplica */
	int count = 0;

	/* Sacamos el entero del va_list */
	n = va_arg(args, int);

	if (n < 0)
	{
		/* Imprimimos el signo negativo primero */
		_putchar('-');
		count++;

		/* Convertimos a unsigned para que print_number reciba
		 * siempre un numero positivo. El cast maneja INT_MIN sin overflow */
		num = (unsigned int)-n;
	}
	else
	{
		/* Si es positivo, solo casteamos directo */
		num = (unsigned int)n;
	}

	/* print_number recibe siempre un valor sin signo */
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

	/* Tabla de digitos hex en minuscula */
	char *hex_lower = "0123456789abcdef";

	/* Tabla de digitos hex en mayuscula */
	char *hex_upper = "0123456789ABCDEF";

	/* Seleccionamos cual tabla usar segun el parametro uppercase */
	char *hex = uppercase ? hex_upper : hex_lower;

	/* Misma logica recursiva que print_number pero en base 16 */
	if (num >= 16)
		count += print_hex(num / 16, uppercase);

	/* num % 16 da un indice del 0 al 15, hex[indice] da el caracter correcto */
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
	/* Sacamos el numero sin signo del va_list */
	unsigned int num = va_arg(args, unsigned int);

	/* Delegamos todo el trabajo de impresion a print_hex */
	return (print_hex(num, uppercase));
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

	/* Tabla de digitos hex, solo minusculas para punteros */
	char *hex = "0123456789abcdef";

	/* Usamos unsigned long porque en sistemas de 64 bits los punteros
	 * ocupan 8 bytes. Con unsigned int (4 bytes) perderiamos la mitad */
	if (num >= 16)
		count += print_hex_pointer(num / 16);

	_putchar(hex[num % 16]);
	count++;

	return (count);
}

/**
 * manager_pointer - prints a pointer address in hexadecimal
 * @args: va_list containing the pointer
 *
 * Return: number of characters printed
 */
int manager_pointer(va_list args)
{
	/* Sacamos el puntero como void* (tipo generico) y casteamos
	 * a unsigned long para poder hacer aritmetica con la direccion */
	unsigned long ptr = (unsigned long)va_arg(args, void *);
	int count = 0;

	/* Los punteros siempre llevan el prefijo "0x" */
	_putchar('0');
	_putchar('x');

	/* Contamos esos 2 caracteres del prefijo */
	count += 2;

	if (ptr == 0)
	{
		/* Caso especial NULL: sin este check, print_hex_pointer
		 * no imprimiria nada para el 0 y quedaria solo "0x" */
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
 * print_octal - prints an unsigned number in octal recursively
 * @num: the unsigned number to print
 *
 * Return: number of characters printed
 */
int print_octal(unsigned int num)
{
	int count = 0;

	/* Misma logica recursiva que print_number pero en base 8 */
	if (num >= 8)
		count += print_octal(num / 8);

	/* num % 8 da digitos del 0 al 7. Sumarle '0' los convierte a char */
	_putchar((num % 8) + '0');
	count++;

	return (count);
}

/**
 * manager_octal - prints an unsigned integer in octal
 * @args: va_list containing the unsigned integer
 *
 * Return: number of characters printed
 */
int manager_octal(va_list args)
{
	/* Sacamos el numero UNA SOLA VEZ del va_list.
	 * El bug original era pasarse a si mismo con va_list en la recursion,
	 * lo que consumia un argumento extra de la pila cada vez */
	unsigned int num = va_arg(args, unsigned int);

	/* Delegamos la impresion a print_octal que trabaja con el numero puro */
	return (print_octal(num));
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

	/* A diferencia de manager_int, no hay chequeo de signo.
	 * %u trata los bits del valor como siempre positivo */
	return (print_number(num));
}
