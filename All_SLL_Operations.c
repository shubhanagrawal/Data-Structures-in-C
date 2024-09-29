#include<stdio.h>
#include<stdlib.h>  // For malloc
#include<string.h>

typedef struct Node
{
    int prn;
    char name[20];
    struct Node* next;
}node;

int length(node *head)
{
    node *temp=head;
    int ctr=0;
    while(temp!=NULL) 
    {
        temp=temp->next;
        ctr++;
    }
    return ctr;
}

node* insertatfirst(node *head)
{
    node *temp=(node*)malloc(sizeof(node));
    printf("Enter Name of the student");
    scanf("%s",temp->name);
    printf("\nEnter PRN of the student ");
    scanf("%d",&temp->prn);
    temp->next=head;
    return temp;
}

node * insertatindex(node *head)
{
    int pos;
    node*temp=head;
    node *curr=(node*)malloc(sizeof(node));
    curr->next=NULL;
    printf("Enter Name of the student");
    scanf("%s",curr->name);
    printf("\nEnter  PRN of the student");
    scanf("%d",&curr->prn);
    printf("\nEnter position at which element is to be inserted");
    scanf("%d",&pos);

    int  k=length(head); 
    int i=1;
    if(pos>k+1)
    {
        printf("Data cant be inserted");
        return head; // Added return head;
    }
    else
    {
        node *temp2=head;
        while(i<pos-1 && temp2!=NULL) 
        {
            temp2=temp2->next;
            i++;
        }
        curr->next=temp2->next;
        temp2->next=curr;
        return head; // Added return head;
    }
}

node *insertatlast(node *head)
{
    node*temp=head;
    node *curr=(node*)malloc(sizeof(node));
    printf("Enter Name of Secretary");
    scanf("%s",curr->name);
    printf("\nEnter PRN of secretary ");
    scanf("%d",&curr->prn);
    curr->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=curr;
    curr->next=NULL;
    return head; 
}

node *deleteatfirst(node *head)
{
    if(head == NULL) // Added check for empty list
    {
        printf("List is empty");
        return head;
    }
    node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

node *deleteatindex(node *head)
{
    int pos;
    printf("Enter position to be deleted at");
    scanf("%d",&pos);
    int k=length(head); 
    int i=0;
    node *temp=head;
    node *curr=head->next;
    if(pos>k)
    {
        printf("Data cant be deleted");
        return head; // Added return head;
    }
    else
    {
        while(i<pos-1 && curr!=NULL )
        {
            temp=temp->next;
            curr=curr->next;
            i++;
        }
        temp->next=curr->next;
        free(curr);
        return head;
    }
}

node* deleteatlast(node *head)
{
    if(head == NULL) // Added check for empty list
    {
        printf("List is empty");
        return head;
    }
    node *temp=head;
    node *curr=head->next;
    while(curr->next!=NULL)
    {
        temp=temp->next;
        curr=curr->next;
    }
    temp->next=NULL;
    free(curr);
    return head;
}

void  display(node *head)
{
    node *temp=head;
    while(temp->next!=NULL) 
    {
        printf("The Name of the student is  %s \n" , temp->name);
        printf("The PRN of the student is %d \n" , temp->prn);
        temp=temp->next;

    }
}

node*delete(node *head)
{
    int c;
    char ch='y';
    while(ch=='y')
    {
        printf("Enter choice , (1:Remove President , 2: Remove at a position , 3: Remove the secretary)");
        scanf("%d" , &c);
        switch(c)
        {
            case 1:
            head=deleteatfirst(head);
            break;
            case 2:
            head=deleteatindex(head);
            break;
            case 3:
            head=deleteatlast(head);
            break;
            default:
            printf("Wrong Input");

        }
        printf("Do you want to continue(y/n)");
        scanf(" %c",&ch);  
    }
    return head; 
}

struct Node* insert(node* head)
{
    node* temp;
    node* curr;
    temp = head;
    char ch = 'y';
    int c;
    
    while(ch == 'y')
    {
        printf("Enter your choice (1:Add Preident , 2: Add at a position , 3 : Add Secretary )");
        scanf("%d",&c);
        switch(c)
        {
            case 1 :
            head=insertatfirst(head);
            break;
            case 2:
            head=insertatindex(head);
            break;
            case 3:
            head=insertatlast(head);
            break;
            default:
            printf("Wrong Input");
        }
        

        printf("Do you want to continue adding nodes? (y/n): ");
        scanf(" %c", &ch);  
    }

    return head;  
}

node*  merge(node*head1,node*head2)
{
    node *head3=(node*)malloc(sizeof(node));
    head3->next=NULL;
    node *temp=head3;
    node *curr1=head1->next;
    node *curr2=head2->next;
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->prn > curr2->prn)
        {
            temp->next=curr2;
            temp=temp->next;
            curr2=curr2->next;
        }
        else
        {
            temp->next=curr1;
            temp=temp->next;
            curr1=curr1->next;
        }
    }
    if(curr1==NULL)
    {
        temp->next=curr2;
    }
    if(curr2==NULL)
    {
        temp->next=curr1;
    }
    return head3->next; 
}

node* reverse(node*head)
{
    node*prev=NULL;
    node *curr=head->next;;
    node*future;
    while(curr!=NULL)
    {
        future=curr->next;
        curr->next=prev;
        prev=curr;
        curr=future;
    }
    head->next=prev; 
    return head;
}

node* sort(node *head)
{
    int i,j;
    node *prev;
    node *curr;
    node *temp;
    for(i=0;i<length(head)-1;i++) 
    {
        prev=head;
        curr=head->next;
        for(j=0;j<length(head)-i-1;j++) 
        {
            temp=curr->next;
            if(curr->prn > temp->prn)
            {
                int t=curr->prn;
                char s[20];
                strcpy(s,curr->name);
                curr->prn=temp->prn;
                strcpy(curr->name,temp->name);
                temp->prn=t;
                strcpy(temp->name,s);
            }
            prev=prev->next;
            curr=curr->next;
        }
    }
    return head;
}

int main()
{
    node *head=(node*)malloc(sizeof(node));
    head->next=NULL; 
    node *head1=(node*)malloc(sizeof(node));
    head1->next=NULL; 
    int ch;
    int number;
    printf("Enter your choice (1:Adding students, 2: deleting students , 3 : displaying number of students , 4 : Displaying Details of all students , 5: Sorting the Number of Students , 6: Merging of students , 7: Reversing the order of Students)");
    scanf("%d" , &ch);
    switch(ch)
    {
        case 1:
        head=insert(head);
        display(head);
        break;
        case 2:
        head=delete(head);
         display(head);
        break;
        case 3:
        number=length(head);
        printf("The No of Students is %d\n" , number);
        break;
        case 4 :
        display(head);
        break;
        case 5 :
        head=sort(head);
        display(head);
        break;
        case 6 :
        head=insert(head);
        head1=insert(head1);
        head=merge(head,head1);
        display(head);
        break;
        case 7:
        head=reverse(head);
        display(head);
        break;
        default:
        printf("Wrong Input");
        
    }
    return 0; 
}