#include <stdio.h>

int main(void)
{
    int secret = 12345;
    int numbers[3] = {10, 20, 30};

    printf("before: %d %d %d\n",
           numbers[0], numbers[1], numbers[2]);

    printf("secret before = %d\n", secret);

    printf("&secret      = %p\n", (void *)&secret);
    printf("&numbers[3]  = %p\n", (void *)(numbers + 3));

    numbers[3] = 999;

    printf("after:  %d %d %d\n",
           numbers[0], numbers[1], numbers[2]);

    printf("secret after = %d\n", secret);

    return 0;
}