#include <stdio.h>

int main(void)
{
    int age = 19;
    int *p = &age;

    printf("age  = %d\n", age);
    printf("&age = %p\n", (void *)&age);

    printf("p    = %p\n", (void *)p);
    printf("*p   = %d\n", *p);

    return 0;
}