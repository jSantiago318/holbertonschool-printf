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
  va_start (args, format);
	count = 0;
	ptr = format;
	


  if (format == NULL)
		return va_end(args), -1; 
  /* added va_end on return trying to porce the printf(%) to work */
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

      /* Handle end of string - just return with count */
      if (*ptr == '\0')
      {
        count--; /* don't count the '%' if it's at the end */
        break;
      }
      /* Handle known format specifiers */
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
        _putchar('%');
        _putchar(*ptr);
        count += 2;
      }

      ptr++;
    }
	}
	/* va_end (args); */
	return va_end(args), count--;
}
