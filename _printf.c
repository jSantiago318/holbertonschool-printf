 
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
    }
      if (*ptr == '%') {
      ptr++;

      /* 
      * verify length of scring, if it is only % and 1 char long, return character
      */

      if (*ptr == '\0')
      {
        _putchar('%');
        count++;
      }



      if (*ptr == 'r')
      {
        return (-1);
      }
      

      /*
       * %c print a single character
       * /d print a decimal (base 10) number
       * /e print an exponential floating-point number
       * /f print a floating-point number
       * /g print a general-format floating-point number
       * /i print an integer in base 10
       * /o print a number in octal (base 8)
       * /s print a string of characters
       * /u print an unsigned decimal (base 10) number
       * /x print a number in hexidecimal (base 16)
       * %% print a percent sign (\% also works)
       */
      
       /*
      if (*ptr == 'c')
        count += manager_char( format);
      else if (*ptr == 's')
        count += manager_string( format);
      else if (*ptr == '%') 
      {
        _putchar('%');
        count++;
      }
        */


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
        {
          _putchar('%');
          count++;
        }

    }
		ptr++;
   
  
	}
	va_end (args);
	return (count);
}
