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
    if(!ensure_capacity(manager))
    {
        printf("An error occurred.\nplease try again.");
        return;
    }
    Contact *contact=&(manager->contacts[manager->current_size]);
    int id;
    if(!read_int(&id)){
        printf("Invalid ID.\n");
        return;
    }
    if(id_exists(manager,id))
    {
        printf("ID already exists!\n");
        return;
    }
    contact->id=id;
    printf("Name :");
    fgets(contact->name,sizeof(contact->name),stdin);
    
    printf("Phone :");
    fgets(contact->phone,sizeof(contact->phone),stdin);

    printf("Email :");
    fgets(contact->email,sizeof(contact->email),stdin);
    // clear \n in string
    remove_newline(contact->name);
    remove_newline(contact->phone);
    remove_newline(contact->email);

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
    if(!read_int(&target_id)){
        printf("Invalid ID.\n");
        return;
    }
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
    if(!read_int(&target_id)){
        printf("Invalid ID.\n");
        return;
    }
    size_t i=0;
    size_t index;
    while(i<manager->current_size)
    {
        if(manager->contacts[i].id==target_id){
            index=i;
            printf("DELETING..");
            for(size_t i=index+1;i<manager->current_size;i++)
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



int ensure_capacity(ContactManager *manager)
{

    if(manager->current_size<manager->capacity){
        printf("Has the necessary space...");
        return 1;
    }
    printf("Expanding the necessary space");
    size_t new_capacity = manager->capacity*2;
    Contact *tmp=realloc(manager->contacts,new_capacity * sizeof *manager->contacts);
    if(tmp==NULL){
        printf("Unsuccessful");
        return 0;
    }
    manager->contacts=tmp;
    manager->capacity=new_capacity;
    return 1;

}


void clear_input()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
    


}

void remove_newline(char *c)
{


    while(*c!='\0')
    {
        if(*c=='\n')
        {
            *c='\0';
            return;
        }
        c++;
    }
    


}


int id_exists(const ContactManager *manger,int id)
{

    for(size_t i=0;i<manger->current_size;i++)
    {
        if(manger->contacts[i].id==id)
        {
            return 1;
        }
    }
    return 0;


}



void update_contact(ContactManager *manager)
{

    printf("ID : ");
    int id;
    scanf("%d",&id);
    clear_input();
    for(size_t i=0;i<manager->current_size;i++)
    {
        if(manager->contacts[i].id==id){
            Contact *contact=&manager->contacts[i];
            printf("Contact Found...\nEnter for skip:\n");
            printf("Name : ");
            char name[MAX_NAME];
            if(fgets(name,sizeof(name),stdin)!=NULL){
                    remove_newline(name);
                    if(name[0]!='\0'){
                        strcpy(contact->name,name);
                    }
                    
            }


            printf("Email : ");
            char email[MAX_EMAIL];
            if(fgets(email,sizeof(email),stdin)!=NULL){
                remove_newline(email);
                if(email[0]!='\0'){
                    strcpy(contact->email,email); 
                }
            }

            printf("Phone : ");
            char phone[MAX_PHONE];
            if(fgets(phone,sizeof(phone),stdin)!=NULL)
            {
                remove_newline(phone);
                if(phone[0]!='\0'){
                strcpy(contact->phone,phone);                    
                }

            }
            printf("Successfully updated.");
            return;  
        }
    }
    printf("Did not found ");
}


int read_int(int *value)
{
    int result=scanf("%d",value);

    clear_input();
    return result==1;

}