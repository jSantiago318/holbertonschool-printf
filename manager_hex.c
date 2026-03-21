#include "main.h"

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

    /*
    * Usamos unsigned long porque en sistemas de 64 bits los punteros
    * ocupan 8 bytes. Con unsigned int (4 bytes) perderiamos la mitad
    */
	if (num >= 16)
		count += print_hex_pointer(num / 16);

	_putchar(hex[num % 16]);
	count++;

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
	/*
    *Sacamos el numero UNA SOLA VEZ del va_list.
	* El bug original era pasarse a si mismo con va_list en la recursion,
	* lo que consumia un argumento extra de la pila cada vez
    */
	unsigned int num = va_arg(args, unsigned int);

	/* Delegamos la impresion a print_octal que trabaja con el numero puro */
	return (print_octal(num));
}
