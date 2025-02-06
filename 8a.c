#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}
char pop() {
    if (top == -1) return -1;
    return stack[top--];
}
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}
int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}
void reverse(char* exp) {
    int length = strlen(exp);
    for (int i = 0; i < length / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
}
void swapParentheses(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
}
void infixToPostfix(char* exp, char* result) {
    int i, j = 0;
    for (i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {
            result[j++] = exp[i];
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = pop();
            }
            pop();
        } else if (isOperator(exp[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                result[j++] = pop();
            }
            push(exp[i]);
        }
    }
    while (top != -1) {
        result[j++] = pop();
    }
    result[j] = '\0';
}
void infixToPrefix(char* exp, char* result) {
    reverse(exp);
    swapParentheses(exp);
    infixToPostfix(exp, result);
    reverse(result);
}
int main() {
    char exp[MAX], postfixResult[MAX], prefixResult[MAX];
    printf("Enter infix expression: ");
    scanf("%s", exp);
    infixToPostfix(exp, postfixResult);
    printf("Postfix Expression: %s\n", postfixResult);
    infixToPrefix(exp, prefixResult);
    printf("Prefix Expression: %s\n", prefixResult);
    return 0;
}