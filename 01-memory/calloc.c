#include<stdio.h>
#include<stdlib.h>

int main(void)
{

    int *numbers=calloc(3,sizeof(int));

    if (numbers==NULL)
        return 1;





    printf("%d\n", numbers[0]);
    printf("%d\n", numbers[1]);
    printf("%d\n", numbers[2]);

    free(numbers);





    return 0;
}