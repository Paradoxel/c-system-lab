#include<stdio.h>
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



void add_contact(ContactManager *manager){
    Contact *contact=&(manager->contacts[manager->current_size]);
    printf("Name :");
    fgets(contact->name,sizeof(contact->name),stdin);
    
    printf("Phone :");
    fgets(contact->phone,sizeof(contact->phone),stdin);

    printf("Email :");
    fgets(contact->email,sizeof(contact->email),stdin);
    

    manager->current_size++;
}


void list_contacts(const ContactManager *manager)
{

    size_t i=0;
    while(i<manager->current_size)
    {
        printf("-%zu\n", i);
        printf("Name : %s\t",manager->contacts[i].name);
        printf("Phone : %s\t",manager->contacts[i].phone);
        printf("Email : %s\t",manager->contacts[i].email);
        printf("\n");
        i++;
    }



}