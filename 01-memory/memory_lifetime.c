#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int *p=malloc(sizeof *p);

    if (p==NULL){
        return 1;
    }

    *p=100;

    printf("before free : %d\n",*p);


    free(p);

    printf("after free: %d\n",*p);

    return 0;
}