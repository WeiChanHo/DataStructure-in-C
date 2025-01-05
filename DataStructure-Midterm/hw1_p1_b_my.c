#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if(top==MAX-1){
        printf("stack overflow\n");
        return;
    }
    stack[++top]=c;
}

char pop() {
    if(top ==-1){
        printf("stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char c) {
    if(c=='*' || c=='/'){
        return 2;
    }else if (c =='+' || c=='-'){
        return 1;
    }
    return 0;
}

int isOperator(char c) {
    return (c=='+'||c=='-'||c=='*'||c=='/');
}

void infixToPostfix(char* infix) {
    int n = strlen(infix);
    int i,k =0;
    char postfix[MAX];

    for (i=0;i<n;i++) {
        if(isalpha(infix[i])){
            postfix[k++] = infix[i];
        }
        else if(isOperator(infix[i])){
            while (top!=1 && (precedence(stack[top])>= precedence(infix[i]))){
                postfix[k++]= pop();
            }
            push(infix[i]);
        }
    }
    while (top!=-1){
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf("%s\n",postfix);
}

int main() {
  char infix[MAX];
  scanf("%s",infix);
  infixToPostfix(infix);
  return 0;
}