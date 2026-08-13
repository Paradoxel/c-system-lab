#include <stdio.h>

int main(void)
{
    int numbers[3] = {10, 20, 30};

    printf("numbers[0] = %d\n", numbers[0]);
    printf("numbers[1] = %d\n", numbers[1]);
    printf("numbers[2] = %d\n", numbers[2]);


    printf("&numbers[0] = %p\n", (void *)&numbers[0]);
    printf("&numbers[1] = %p\n", (void *)&numbers[1]);
    printf("&numbers[2] = %p\n", (void *)&numbers[2]);


    return 0;
}