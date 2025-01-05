#include <stdio.h>
#include <ctype.h>  // for isalpha()
#include <string.h> // for string operations

#define MAX 100  // Maximum size of the stack

// Stack for storing operators
char stack[MAX];
int top = -1;

// Function to push operator to stack
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

// Function to pop operator from stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to get precedence of operators
int precedence(char c) {
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert infix to postfix
void infixToPostfix(char* infix) {
    int n = strlen(infix);
    int i, k = 0;
    char postfix[MAX];

    for (i = 0; i<n ; i++) {
        // If the character is an operand, add it to the output
        if (isalpha(infix[i])) {
            postfix[k++] = infix[i];
        }
        // If the character is an operator
        else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop the remaining operators from the stack
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';  // Null terminate the postfix expression
    printf("%s\n", postfix);  // Print the postfix expression
}

// Main function
int main() {
    char infix[MAX];
    
    // Input infix expression
    scanf("%s", infix);

    // Convert to postfix and print result
    infixToPostfix(infix);
    
    return 0;
}
