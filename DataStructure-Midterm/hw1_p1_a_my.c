#include <stdio.h>
#include <string.h>

void prefixToInfix(char* prefix) {
    int n = strlen(prefix);
    char stack[100][100];
    int top =-1;
    for (int i=n-1; i>=0 ; i--){
        char ch = prefix[i];
        switch (ch) {
            case '+':
            case '-':
            case '*':
            case '/': {
                char operand1[100],operand2[100];
                strcpy(operand1,stack[top--]);
                strcpy(operand2,stack[top--]);
                char expr[100];
                sprintf(expr,"%s%c%s",operand1,ch,operand2);
                strcpy(stack[++top],expr);
                break;
            }
            default: {
                char operand[2] = {ch,'\0'};
                strcpy(stack[++top],operand);
                break;
            }
        }
    }
    printf("%s\n",stack[top]);
}

int main() {
    char prefix[100];
    scanf("%s",prefix);
    prefixToInfix(prefix);
    return 0;
}