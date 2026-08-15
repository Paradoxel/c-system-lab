#include<stdlib.h>
#include<string.h>
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



int init_manager(ContactManager *contactManager){
    contactManager->current_size=0;
    contactManager->capacity=2 ;
    contactManager->contacts=malloc(contactManager->capacity*sizeof *contactManager->contacts);
    if(contactManager->contacts==NULL){
        return 0;
    }
    return 1;
}


void destroy_manager(ContactManager *contactManager)
{
    free(contactManager->contacts);
    contactManager->capacity=0;
    contactManager->current_size=0;
    contactManager->contacts=NULL;
}