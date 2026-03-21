 
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
    } else if (*ptr == '%') {
      ptr++;

      /* if there is no more characters */
      if (*ptr == '\0' && count == 0)
      {
          count += manager_percent(args);
      }

      if (*ptr == 'r')
      {
        return (-1); 
      }
      


          /* VERIFICAR %c*/
        if (*ptr == 'c')
          count += manager_char(args);
                  /* VERIFICAR %s para string >> nested loop*/
        if (*ptr == 's')
          count += manager_string(args);
                  /* VERIFICAR %d para decimal*/
        if (*ptr == 'd')
          count += manager_int(args);
                  /* VERIFICAR %i para integer*/
        if (*ptr == 'i')
          count += manager_int(args);
                  /* VERIFICAR %% para percent sign*/
        if (*ptr == '%')
          count += manager_percent(args);

    }
		ptr++;
   
  
	}
	va_end (args);
	return (count);
}
