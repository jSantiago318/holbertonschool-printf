#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);

int manager_char(va_list args);
int manager_string(va_list args);
int manager_percent(va_list args);
int manager_int(va_list args);
int print_number(unsigned int num);


#endif
