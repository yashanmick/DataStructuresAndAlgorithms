#include <iostream>
#include <string>
#include <stack>

using namespace std;

//check whether the character is a operand
bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//check whether the character is a operator
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//check operator precedence
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if ((c == '*') || (c == '/'))
        return 2;
    else if ((c == '+') || (c == '-'))
        return 1;
    else
        return -1;
}

//postfix to infix
string postfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string op(1, postfix[i]);
            //string op=postfix[i];
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push('(' + op2 + postfix[i] + op1 + ')');
        }
    }
    return s.top();
}

int main()
{
    string infix, postfix;
    cout << "Enter a POSTfix Expression : " << endl;
    cin >> postfix;
    stack<char> s;
    cout << "POSTFIX EXPRESSION : " << postfix << endl;
    infix = postfixToInfix(postfix);
    cout << endl
         << "INFIX EXPRESSION : " << infix << endl;

    return 0;
}