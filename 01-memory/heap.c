#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int *p=malloc(sizeof *p);
    if (p==NULL){
        return 1;
    }
    *p=42;
    printf("p = %p\n",(void *)p);
    printf("*p = %d\n",*p);
    free(p);
    return 0;
}