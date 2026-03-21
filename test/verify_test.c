#include "main.h"
#include <stdio.h>

int main(void)
{
    int len1, len2, len3;

    printf("=== Test 1: _printf(\"%%\"); ===\n");
    printf("Expected: (nothing)\n");
    printf("Actual: [");
    len1 = _printf("%");
    printf("]\n");
    printf("Length returned: %d\n\n", len1);

    printf("=== Test 2: _printf(\"%%!\\n\"); ===\n");
    printf("Expected: %%!\\n\n");
    printf("Actual: [");
    len2 = _printf("%!\n");
    printf("]\n");
    printf("Length returned: %d\n\n", len2);

    printf("=== Test 3: _printf(\"%%K\\n\"); ===\n");
    printf("Expected: %%K\\n\n");
    printf("Actual: [");
    len3 = _printf("%K\n");
    printf("]\n");
    printf("Length returned: %d\n", len3);

    return 0;
}
