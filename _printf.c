#include "main.h"
#include <string.h>

/**
 * _printf - produces output according to a format string
 * @format: the format string with directives
 *
 * Return: number of characters printed, -1 if format is NULL
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;
   
	const char *ptr;

	if (format == NULL)
		return (-1);

	va_start (args, format);
	count = 0;
	ptr = format;
	while (*ptr)
	{
     /* 
      print the normal character without % being in pointer
    */
    if (*ptr != '%')
    {
      _putchar(*ptr);
      count++;
      ptr++;
    }
    else if (*ptr == '%')
    {
      ptr++;

      if (*ptr == '\0')
      {
        /*si no hay mas codigo o string para leer para de correr*/
        _putchar('%');
        count++;
        break;
      }
      else if (*ptr == 'c')
      {
        count += manager_char(args);
      }
      else if (*ptr == 's')
      {
        count += manager_string(args);
      }
      else if (*ptr == 'd')
      {
        count += manager_int(args);
      }
      else if (*ptr == 'i')
      {
        count += manager_int(args);
      }
      else if (*ptr == 'x')
      {
        count += manager_hex(args, 0);
      }
      else if (*ptr == 'X')
      {
        count += manager_hex(args, 1);
      }
      else if (*ptr == 'p')
      {
        count += manager_pointer(args);
      }
      else if (*ptr == '%')
      {
        count += manager_percent(args);
      }
      else if (*ptr == 'o')
      {
        count += manager_octal(args);
      }
      else if (*ptr == 'u')
      {
        count += manager_unsigned(args);
      }
      else
      {
        /* unknown format specifier - print % and the char */
        /* 
        * Asi se debe de imprimir 
        *Correct output - case: _printf("%");
        *Correct output - case: _printf("%!\n");
        *Correct output - case: _printf("%K\n");
        */
        _putchar('%');
        _putchar(*ptr);
        count += 2;
      }

      ptr++;
    }
	}
	va_end (args);
	return (count);
}
