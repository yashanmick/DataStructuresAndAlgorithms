#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

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

//infix to prefix
string InfixToPrefix(stack<char> s, string infix)
{
    string prefix;
    //reverse the infix
    reverse(infix.begin(), infix.end());

    //convert '(' --> ')' and ')' --> '('
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((s.top() != '(') && (!s.empty()))
            {
                char temp = s.top();
                prefix += temp;
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if (precedence(infix[i] > precedence(s.top())))
                {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
                {
                    while ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(s.top()))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while ((!s.empty()) && (precedence(infix[i]) < precedence(s.top())))
                    {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string infix, prefix;
    cout << "Enter a Infix Expression : " << endl;
    cin >> infix;
    stack<char> s;
    cout << "INFIX EXPRESSION : " << infix << endl;
    prefix = InfixToPrefix(s, infix);
    cout << endl
         << "PREFIX EXPRESSION : " << prefix << endl;

    return 0;
}