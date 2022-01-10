#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct details {
    int eid;
    char ename[30];
    char ead[100];
    char edep[200];
    struct details *next;
    struct details *prev;
}details;

details *head=NULL,*last=NULL;
int n;

void add_employee(int n)
{
    for(int i=1;i<=n;i++)
    {
        details *link=(details*)malloc(sizeof(details));
        link->prev=NULL;
        link->next=NULL;
        printf("Enter %d employee id:\n",i);
        scanf("%d",&link->eid);
        printf("Enter %d employee name:\n",i);
        scanf("%s",&link->ename);
        printf("Enter %d employee address:\n",i);
        scanf("%s",&link->ead);
        printf("Enter %d employee department:\n",i);
        scanf("%s",&link->edep);
        printf("\n\n\n");
    
        if(head==NULL)
        {
            head=link;
        }
        else
        {
            head->prev=link;
            link->next=head;
            head=link;
        }
    }
    
}

void display(int n,details *ptr)
{
        int j=n;
        if(ptr==NULL)
        {
            return;
        }

        printf("%d Employee id is %d\n",j,ptr->eid);
        printf("%d Employee name is %s\n",j,ptr->ename);
        printf("%d Employee address is %s\n",j,ptr->ead);
        printf("%d Employee working department is %s\n",j,ptr->edep);
        printf("\n");
        j--;
        ptr=ptr->next;
        display(n,ptr);
}    
        
int main() 
{
    int n;
    printf("Enter thr maximum number of employees\n");
    scanf("%d",&n);
    add_employee(n);
    details *ptr=head;
    display(n,ptr);
    return 0;
}
