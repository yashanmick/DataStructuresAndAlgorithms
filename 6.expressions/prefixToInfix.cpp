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

//prefix to infix
string prefixToInfix(string prefix)
{
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            string op(1, prefix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push('(' + op1 + prefix[i] + op2 + ')');
        }
    }
    return s.top();
}

int main()
{
    string infix, prefix;
    cout << "Enter a Infix Expression : " << endl;
    cin >> prefix;
    stack<char> s;
    cout << "INFIX EXPRESSION : " << prefix << endl;
    infix = prefixToInfix(prefix);
    cout << endl
         << "PREFIX EXPRESSION : " << infix << endl;

    return 0;
}