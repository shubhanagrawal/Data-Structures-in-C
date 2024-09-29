#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
} Node;

void create(Node *head)
{
    Node* temp;
    Node* curr;
    char ch = 'y';  // Initialize 'ch' with 'y' to enter the loop
    temp = head;
    
    while (ch == 'y')
    {
        curr = (Node*)malloc(sizeof(Node));
        printf("Enter data: ");
        scanf("%d", &curr->data);
        curr->next = NULL;
        temp->next = curr;
        temp = curr;
        
        printf("Do you want to continue (y/n): ");
        scanf(" %c", &ch);  // Add space before %c to consume newline character
    }
}
void display(Node *head)
{
    Node *curr;
    if (head->next == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        curr = head->next;
        while (curr != NULL)
        {
            printf("The data is %d\n", curr->data);
            curr = curr->next;
        }
    }
}
int length(Node *head)
{
    Node *curr = head->next;
    int i = 0;
    while (curr != NULL)
    {
        i++;
        curr = curr->next;
    }
    return i;
}
void insert(Node *head)
{
    int i = 1;
    Node *curr = head;
    Node *nnode;
    nnode = (Node *)malloc(sizeof(Node));
    
    int pos;
    printf("Enter data of the node and position to be inserted: ");
    scanf("%d %d", &nnode->data, &pos);

    int k = length(head);  // Corrected 'len' to 'length'
    if (pos > k + 1)
    {
        printf("Data can't be inserted\n");
    }
    else
    {
        while (curr != NULL && i < pos)
        {
            i++;
            curr = curr->next;
        }
        nnode->next = curr->next;
        curr->next = nnode;
    }
}
void delete(Node *head)
{
    int ctr = 1;
    Node *curr = head->next;
    Node *temp;
    Node *prev = head;

    int pos;
    printf("Enter position to be deleted: ");
    scanf("%d", &pos);

    int k = length(head);  // Corrected 'len' to 'length'
    if (pos > k)
    {
        printf("Data can't be deleted\n");
    }
    else
    {
        while (curr != NULL && ctr < pos)
        {
            ctr++;
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL)
        {
            temp = curr;
            prev->next = curr->next;
            free(temp);  // Freeing the memory to prevent memory leak
        }
    }
}
void reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head->next;
    Node *future;
    
    while (curr != NULL)
    {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }
    head->next = prev;
}
void merge(Node *head, Node *head2)
{
    Node *curr1 = head->next;
    Node *curr2 = head2->next;
    Node *temp = NULL;
    Node *mergedHead = NULL;
    Node *mergedTail = NULL;
    int flag;
    if(curr1->data < curr2 ->data)
    {
        temp=head;
        flag=1;

    }
    else
    {
        temp=head2;
        flag=0;
    }
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data > curr2->data)
        {
            temp->next=curr1;
            temp=curr1;
            curr1=curr1->next;
        }
        else
        {
             temp->next=curr2;
            temp=curr2;
            curr2=curr2->next;
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
    if(flag==1)
    {
        display(head);
    }
    else{
        display(head2);
    }

}
void sortbypointers(Node *head)
{
    int len = length(head);
    Node *curr;
    Node *temp;
    Node *prev;
    
    for (int i = 0; i < len - 1; i++)
    {
        curr = head->next;
        prev = head;
        
        for (int j = 0; j < len - i - 1; j++)
        {
            temp = curr->next;
            if (curr->data > temp->data)
            {
                prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;
                curr = temp;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}
int main() {
    // Initialize head and head2
    Node* head = (Node*)malloc(sizeof(Node));
    Node* head2 = (Node*)malloc(sizeof(Node));

    // Initialize the next pointers
    head->next = NULL;
    head2->next = NULL;

    // Example operations (create, display, etc.)
    printf("Creating first list:\n");
    create(head);
    printf("Displaying first list:\n");
    display(head);

    printf("Creating second list:\n");
    create(head2);
    printf("Displaying second list:\n");
    display(head2);

    printf("Merging lists:\n");
    merge(head, head2);

    printf("Reversing the merged list:\n");
    reverse(head);
    display(head);

    printf("Sorting the merged list:\n");
    sortbypointers(head);
    display(head);

    // Free allocated memory (omitted for brevity)

    return 0;
}
