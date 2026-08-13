#include<stdio.h>
#include<stdlib.h>

int main(void)
{

    int *numbers=malloc(3*sizeof *numbers);

    if (numbers==NULL)
        return 1;

    *(numbers)=10;
    *(numbers+1)=20;
    *(numbers+2)=30;


    printf("Before realloc:\n");
    printf("%d %d %d\n", numbers[0], numbers[1], numbers[2]);
    printf("address = %p\n",(void *)&numbers);

    numbers = realloc(numbers, 5 * sizeof *numbers);

    if (numbers == NULL)
        return 1;

    numbers[3] = 40;
    numbers[4] = 50;

    printf("After realloc:\n");
    printf("%d %d %d %d %d\n",
        numbers[0],
        numbers[1],
        numbers[2],
        numbers[3],
        numbers[4]);

    printf("address = %p\n", (void *)numbers);

    free(numbers);


    return 0;
}