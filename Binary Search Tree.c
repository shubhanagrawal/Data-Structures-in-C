#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode {
    char name[100]; // Adjust size as needed
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode* getnode() {
    treenode *newNode = (treenode *)malloc(sizeof(treenode));
    if (newNode) {
        newNode->left = NULL;
        newNode->right = NULL;
        printf("\nEnter name for the new node: ");
        scanf("%s", newNode->name); // Assumes name is a string
    }
    return newNode;
}

treenode* create(treenode *root) {
    treenode *temp, *curr;  // structure pointer
    int flag;
    char ch = 'y';
   
    if (root == NULL) {  // accepting root node's values (First Node)
        printf("\n Create Root Node ");
        root = getnode();
    } // end of if

    printf("\n Create Binary Search Tree ");
    do {
        flag = 0;
        temp = root; // temp point to root
        curr = getnode(); // allocate memory for newnode
        if (curr == NULL) { // Check if getnode returned NULL
            printf("Memory allocation failed.\n");
            break;
        }

        while (flag == 0) {  
            if (strcmp(curr->name, temp->name) < 0) { // move to left
                if (temp->left == NULL) {
                    temp->left = curr; // attach to left
                    printf(" %s attached to left of %s  ", curr->name, temp->name);
                    flag = 1;
                } // end of inner if
                else {
                    temp = temp->left; // move to left
                }
            } // end of outer if
            else if (strcmp(curr->name, temp->name) > 0) { // move to right
                if (temp->right == NULL) {
                    temp->right = curr; // attach to right
                    printf(" %s attached to right of %s  ", curr->name, temp->name);
                    flag = 1;
                } // end of inner if
                else {
                    temp = temp->right; // move to right
                }
            } // end of else if
            else {
                printf("Node with name %s already exists. Skipping...\n", curr->name);
                free(curr); // Free memory if duplicate
                flag = 1; // Exit the while loop
            }
        } // end of while flag

        printf("\n Do you want to continue? (n/y) ");
        scanf(" %c", &ch);
    } while (ch == 'y');
   
    return root; // return root node
}

void inorder(treenode *temp)
{
if(temp!=NULL)
{
inorder(temp->left);
printf( " %s",temp->name);
inorder(temp->right);
}
}


void leveldisp(treenode* root)
{
    treenode* Q[20]; // Create Queue
    treenode* temp;
    int front = 0, rear = 0, level = 0, leaf = 0;

    if (root == NULL) {
        printf("Tree is Empty\n");
        return;
    }

    Q[rear++] = root; // Initialize queue with root node
    Q[rear++] = NULL; // Mark the end of the current level
    printf("\n  Level  %d ", level++);

    while (front < rear) {
        temp = Q[front++]; // Pop

        if (temp == NULL) {
            if (front < rear) { // If there are more nodes to process
                printf("\n  Level  %d ", level++);
                Q[rear++] = NULL; // Push in queue for next level
            }
        } else {
            printf(" %s", temp->name);
            if (temp->left != NULL) {
                Q[rear++] = temp->left; // Push in queue
            }
            if (temp->right != NULL) {
                Q[rear++] = temp->right; // Push in queue
            }
            if (temp->left == NULL && temp->right == NULL) {
                leaf++;
            }
        }
    }

    printf("\n Depth of Tree : %d ", level - 1);
    printf("\n Leaf Nodes : %d\n", leaf);
}


int main()
{
treenode * root=NULL ;
         root=create(root);
         //printf("\n Inorder \n ");
//inorder(root);
leveldisp(root);
       return 0;
}