#include <iostream>

using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;
    bool isEmpty()
    {
        if (root == NULL)
            return true;

        else
            return false;
    }
};

int main()
{
    int option;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print BST values" << endl;
        cout << "5. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            break;
        case 2:
            cout << "SEARCH" << endl;
            break;
        case 3:
            cout << "DELETE" << endl;
            break;
        case 4:
            cout << "PRINT and TRAVERSE" << endl;
            break;
        case 5:
            cout << "CLEAR SCREEN" << endl;
            system("cls");
            break;
        default:
            cout << "Enter a proper option number " << endl;
        }

    } while (option != 0);

    return 0;
}