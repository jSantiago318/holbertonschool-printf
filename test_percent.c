#include <stdio.h>
#include "main.h"

int __main(void)
{
    int result;
    
    printf("Test 1: _printf(\"%%\");\n");
    result = _printf("%");
    printf("\nLength: %d\n", result);
    
    printf("\n---\n");
    printf("Test 2: _printf(\"%%!\");\n");
    result = _printf("%!");
    printf("\nLength: %d\n", result);
    
    printf("\n---\n");
    printf("Test 3: _printf(\"hello\");\n");
    result = _printf("hello");
    printf("\nLength: %d\n", result);

      printf("\n---\n");
    printf("Test 4: _printf(\"%%K\");\n");
    result = _printf("%K");
    printf("\nLength: %d\n", result);

    printf("\n---\n"); 
    result = _printf("%");
    printf("\nLength: %d\n", result);
    
    return (0);
}
