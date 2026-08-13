#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int *p=malloc(sizeof *p);
    
    if(p==NULL)
        return 1;

    *p=41;

    printf("before free %d\n",*p);


    free(p);

    p==NULL;

    return 0;
}