#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack to store intermediate expressions
char stack[MAX][MAX];
int top = -1;

// Function to check if a character is an operator
int isOperator(char op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

// Function to push a string onto the stack
void push(const char *str)
{
    if (top < MAX - 1)
    {
        top++;
        strcpy(stack[top], str);
    }
    else
    {
        printf("Stack Overflow\n");
        exit(1);
    }
}

// Function to pop a string from the stack
void pop(char *str)
{
    if (top >= 0)
    {
        strcpy(str, stack[top]);
        top--;
    }
    else
    {
        printf("Stack Underflow\n");
        exit(1);
    }
}

// Function to concatenate three strings with an operator in between
void concat(char *dest, const char *str1, char op, const char *str2)
{
    strcpy(dest, str1);
    int len = strlen(dest);
    dest[len] = op;
    strcpy(dest + len + 1, str2);
    dest[len + 1 + strlen(str2)] = '\0';  // Null-terminate the final string
}

// Function to convert postfix expression to infix expression
void post_to_inf(char *string)
{
    char s0[2], s1[MAX], s2[MAX], inf[MAX];

    for (int i = 0; i < strlen(string); i++)
    {
        s0[0] = string[i];
        s0[1] = '\0';

        if (!isOperator(s0[0])) // If character is an operand
        {
            push(s0);
        }
        else // If character is an operator
        {
            pop(s1);
            pop(s2);

            // Form the infix expression with parentheses
            concat(inf, s2, s0[0], s1);
            push(inf);
        }
    }

    pop(inf); // Final infix expression is at the top of the stack

    printf("\nThe infix expression is : %s", inf);
    printf("\n***************************************************\n");
}

int main()
{
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    post_to_inf(postfix);

    return 0;
}