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

//prefix to postfix
string prefixToPostfix(string prefix)
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
            s.push(op1 + op2 + prefix[i]);
        }
    }
    return s.top();
}

int main()
{
    string prefix, postfix;
    cout << "Enter a Prefix Expression : " << endl;
    cin >> prefix;
    stack<char> s;
    cout << "PREFIX EXPRESSION : " << prefix << endl;
    prefix = prefixToPostfix(prefix);
    cout << endl
         << "prefix EXPRESSION : " << prefix << endl;

    return 0;
}