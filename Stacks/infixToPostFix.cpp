#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

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

string infixToPostfix (string infix) {

    stack<char> s;
    string postfix = "";

    for (int i = 0; i<infix.length(); i++) {

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
        else if(ch == '(') {
            s.push(ch);
        }
        //char is closing bracket
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (s.empty()) {
                return "INVALID";
            }

            s.pop();
        }
        //char is operator
        else if (isOperator(ch)) {
            while (!s.empty() && s.top() != '(' &&
                   (precedence(s.top()) > precedence(ch) ||
                   (precedence(s.top()) == precedence(ch) && ch != '^'))) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
        else {
            return "INVALID";
        }

    }

    while (!s.empty()) {
        if (s.top() == '(') {
            return "INVALID";
        }

        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main (void) {

    string infix;

    cout << "Enter infix statement: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    if (postfix == "INVALID") {
        cout << "Infix input was invalid to be converted to postfix.";
    }
    else {
        cout << "postfix: " << postfix;
    }

    return 0;
}