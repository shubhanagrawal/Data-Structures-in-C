#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include<stdio.h>

#define MAX 100

int priority(char op)
{
    switch(op)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1; // Return -1 for invalid operator
    }
}

void infixtopostfix(const char *infix, char *postfix)
{
    char stack[MAX];
    int top = -1;
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];
        if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            stack[++top] = ch; // push
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[k++] = stack[top--]; // pop
            }
            top--; // pop '('
        }
        else
        {
            while (top != -1 && priority(stack[top]) >= priority(ch))
            {
                postfix[k++] = stack[top--];
            }
            stack[++top] = ch; // push the operator
        }
    }
   
    while (top != -1) // pop all operators
    {
        postfix[k++] = stack[top--];
    }
   
    postfix[k] = '\0';
}

int main()
{
    char infix[MAX];
    printf("Infix Expression -> ");
    scanf("%s", infix);
    char postfix[MAX];
   
    infixtopostfix(infix, postfix);
   
    printf("Expression : %s \n", infix);
    printf("Postfix Expression : %s \n", postfix);
   
    return 0;
}