 
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
  // string return_string
  
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

      /* if there is no more characters */
      if (*ptr == '\0')
      {
          _putchar('%');
          count++;
      }
      else if (*ptr == 'r')
      {
        return (-1); 
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
      else if (*ptr == '%')
      {
        count += manager_percent(args);
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
	va_end (args);
	return (count);
}
