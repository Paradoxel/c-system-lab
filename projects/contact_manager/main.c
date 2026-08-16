#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME 20
#define MAX_PHONE 12
#define MAX_EMAIL 30

typedef struct 
{
    int id;
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


void find_contact(const ContactManager *manager)
{
    int target_id;
    printf("Please Enter ID: ");
    scanf("%d",&target_id);
    size_t i=0;
    while(i<manager->current_size)
    {
        if(manager->contacts[i].id==target_id)
        {
            printf("FOUND!");
            printf("Name : %s\t",manager->contacts[i].name);
            printf("Phone : %s\t",manager->contacts[i].phone);
            printf("Email : %s\t",manager->contacts[i].email);
            return;
        }
        i++;
    }
    printf("\nNot Found");
}



void remove_contact(ContactManager *manager)
{
    int target_id;
    printf("ID:");
    scanf("%d",&target_id);
    size_t i=0;
    size_t index;
    while(i<manager->current_size)
    {
        if(manager->contacts[i].id==target_id){
            index=i;
            printf("DELETING..");
            for(int i=index+1;i<manager->current_size;i++)
            {
                manager->contacts[i-1]=manager->contacts[i];
            }
            printf("Succesfull DELETING");
            manager->current_size--;
            return;
        }
        i++;
    }    
    printf("\nNOT FOUND");

}



void ensure_capacity(ContactManager *manager)
{

    if(manager->current_size<manager->capacity){
        printf("Has the necessary space...");
        return;
    }
    printf("Expanding the necessary space");
    size_t new_capacity = manager->capacity*2;
    Contact *tmp=realloc(manager->contacts,new_capacity * sizeof *manager->contacts);
    if(tmp==NULL){
        printf("Unsuccessful");
        return;
    }
    manager->contacts=tmp;
    manager->capacity=new_capacity;
    return;


}