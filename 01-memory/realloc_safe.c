#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *numbers = malloc(3 * sizeof *numbers);

    if (numbers == NULL)
    {
        return 1;
    }

    printf("First Address : %p\n", (void *)numbers);

    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;

    int *tmp = realloc(numbers, 6 * sizeof *numbers);

    if (tmp == NULL)
    {
        free(numbers);
        return 1;
    }

    numbers = tmp;

    numbers[3] = 40;
    numbers[4] = 50;

    printf("%d %d %d %d %d\n",
           numbers[0],
           numbers[1],
           numbers[2],
           numbers[3],
           numbers[4]);

    printf("New Address : %p\n", (void *)numbers);

    free(numbers);

    return 0;
}