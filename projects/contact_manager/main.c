#include<stdlib.h>
#define MAX_NAME 20
#define MAX_PHONE 12
#define MAX_EMAIL 30

typedef struct 
{
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
} Contact ;

typedef struct 
{
    Contact *contacts;
    size_t current_size;
    size_t capacity;
} ContactManager ;
