

#define stack_size 100

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;

node* stack[100];
int top = -1;

int isempty() {
    return (top == -1);
}

int isfull() {
    return (top == (stack_size - 1));
}

void push(node* node) {
    if (isfull()) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = node;
    }
}

node* pop() {
    if (isempty()) {
        printf("Stack is empty\n");
        return NULL;
    } else {
        return stack[top--];
    }
}

node* getnode() {
    node* nnode = (node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &nnode->data);
   
    nnode->left = NULL;
    nnode->right = NULL;
   
    return nnode;
}

node* create(node* root) {
    int flag = 0;
    node* temp;
    char direction;
    char ch = 'y';
   
    while (ch == 'y') {
        temp = root;
        flag = 0;
        node* curr = getnode();
       
        while (flag == 0) {
            printf("Enter direction (left : l , right : r): ");
            scanf(" %c", &direction);  // Added space before %c to consume newline
           
            if (direction == 'l') {
                if (temp->left == NULL) {
                    temp->left = curr;
                    printf("\n%d attatched to the left of %d \n",curr->data,temp->data);
                    flag = 1;
                }
                temp = temp->left;
            } else if (direction == 'r') {
                if (temp->right == NULL) {
                    temp->right = curr;
                    printf("\n%d attatched to the right of %d \n",curr->data,temp->data);
                    flag = 1;
                }
                temp = temp->right;
            } else {
                printf("Invalid direction. Please enter 'l' or 'r'.\n");
            }
        }
        printf("Do you want to continue(y/n): ");
        scanf(" %c", &ch);  // Added space before %c to consume newline
    }
   
    return root;
}

void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preordernonrecursive(node *root)
{
       node *stack[stack_size]; // stack created(it is an array of structure pointers)
       int top=-1;
       node * curr=root;
       while(curr!= NULL || top!=-1) // till end of stack
       {
              while(curr!=NULL)
              {
                     printf(" %d " , curr->data); // display
                     stack[++top]=curr;  // push
                     curr=curr->left; // move to left
              }
              curr=stack[top--]; // pop
              curr=curr->right;
        }
}
void inordernonrecursive(node *root)
{
       node *stack[stack_size]; // stack created(it is an array of structure pointers)
       int top=-1;
       node * curr=root;
       while(curr!= NULL || top!=-1) // till end of stack
       {
              while(curr!=NULL)
              {
                     stack[++top]=curr;  // push
                     curr=curr->left; // move to left
              }
              curr=stack[top--]; // pop
              printf(" %d " , curr->data); // display
              curr=curr->right;
        }
}

             
             

int main() {
    node* head;
    printf("Create Root Node\n");
    head = getnode();
    printf("Create Binary Tree\n");
    head = create(head);
    printf("In Order Traversal(Recusive): ");
    inorder(head);
    printf("\n");
   
    printf("In Order Traversal (non-recursive): ");
    inordernonrecursive(head);
    printf("\n");
   
    /*printf("Post Order Traversal: ");
    postorder(head);
    printf("\n");
    */

    return 0;
}
