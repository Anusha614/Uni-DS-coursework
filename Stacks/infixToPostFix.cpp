#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

char s[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!";
        return;
    }

    s[++top] = ch;
}

void pop() {
    if (top == -1) {
        return;
    }

    top--;
}

char peek() {
    if (top == -1) {
        return '\0';
    }

    return s[top];
}

bool isEmpty() {
    return top == -1;
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;

    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' ||
           ch == '/' || ch == '%' || ch == '^';
}

string infixToPostfix(string infix) {

    top = -1;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {

        char ch = infix[i];

        //base cases:

        //char is a space
        if (isspace(ch)) {
            continue;
        }
        //char is alphabet
        else if (isalnum(ch)) {
            postfix += ch;
        }
        //char is opening bracket
        else if (ch == '(') {
            push(ch);
        }
        //char is closing bracket
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix += peek();
                pop();
            }

            if (isEmpty()) {
                return "INVALID";
            }

            pop();
        }
        //char is operator
        else if (isOperator(ch)) {
            while (!isEmpty() && peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch) && ch != '^'))) {
                postfix += peek();
                pop();
            }

            push(ch);
        }
        else {
            return "INVALID";
        }
    }

    while (!isEmpty()) {
        if (peek() == '(') {
            return "INVALID";
        }

        postfix += peek();
        pop();
    }

    return postfix;
}

int main() {

    string infix;

    cout << "Enter infix statement: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    if (postfix == "INVALID") {
        cout << "Infix input was invalid to be converted to postfix.";
    }
    else {
        cout << "Postfix: " << postfix;
    }

    return 0;
}