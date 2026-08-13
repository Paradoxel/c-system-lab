#include<stdio.h>

int main(void){

    int numbers[3]={10,20,30};
    int *p=numbers;
    printf("p     = %p\n", (void *)p);
    printf("p + 1 = %p\n", (void *)(p + 1));
    printf("p + 2 = %p\n", (void *)(p + 2));

    printf("*p       = %d\n", *p);
    printf("*(p + 1) = %d\n", *(p + 1));
    printf("*(p + 2) = %d\n", *(p + 2));


    p++;
    printf("after p++:\n");
    printf("p  = %p\n", (void *)p);
    printf("*p = %d\n", *p);
    
    return 0;
}