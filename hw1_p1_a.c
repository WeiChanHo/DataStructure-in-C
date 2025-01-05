#include <stdio.h>
#include <string.h>

// Function to convert prefix to infix using switch
void prefixToInfix(char* prefix) {
    int n = strlen(prefix);
    // Stack to store operands
    char stack[100][100];
    int top = -1;

    // Traverse the prefix expression from right to left
    for (int i = n - 1; i >= 0; i--) {
        char ch = prefix[i];

        // Use switch to determine if the character is an operator or operand
        switch (ch) {
            // Operators
            case '+':
            case '-':
            case '*':
            case '/': {
                // Pop two operands from the stack
                char operand1[100], operand2[100];
                strcpy(operand1, stack[top--]);
                strcpy(operand2, stack[top--]);

                // Form a new string by combining the operator with the two operands
                char expr[100];
                sprintf(expr, "%s%c%s", operand1, ch, operand2);

                // Push the resulting expression back to the stack
                strcpy(stack[++top], expr);
                break;
            }
            // Default case (operands)
            default: {
                // Push the operand as a string
                char operand[2] = {ch, '\0'};
                strcpy(stack[++top], operand);
                break;
            }
        }
    }

    // The final expression is stored at the top of the stack
    printf("%s\n", stack[top]);
}

// Main function to read input and print output
int main() {
    char prefix[100];
    scanf("%s", prefix);

    // Convert prefix to infix
    prefixToInfix(prefix);

    return 0;
}
