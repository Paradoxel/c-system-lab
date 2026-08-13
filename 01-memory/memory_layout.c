
#include <stdio.h>

int global = 100;

int main(void)
{
    int local = 200;

    printf("global         = %d\n", global);
    printf("&global        = %p\n", (void *)&global);

    printf("local          = %d\n", local);
    printf("&local         = %p\n", (void *)&local);

    return 0;
}