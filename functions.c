#include "main.h"


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
