/*
1. Understanding of what is linked list & singly linked list
2. C++ objects and classes
3. pointers in C++
4. Dynamic menory allocation

    DISCLAIMER : There are different ways to implement linked list 

    Singly linked List operations-
    1. appendNode()
    2. prependNode()
    3. insertNodeAfter()
    4. deleteNodeByKey()
    5. updateNodeByKey()
    6. print()
*/

#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class SinglyLinkedList
{
public:
    Node *head;
    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head = n;
    }
    //method to find if a node exists using key value
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    //append a node to the list
    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists : " << n->key << ". Append another node with different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node appended" << endl;
            }
        }
    }
    //prependNode - attach a node at the start
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists : " << n->key << ". Append another node with different key value" << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node prepended" << endl;
        }
    }
    //Insert a node after a perticular node in the list
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exist with key value: " << k << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node already exists : " << n->key << ". Append another node with different key value" << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node inserted" << endl;
            }
        }
    }
    //Delete node by unique key
    void deleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "Singly Linked List already Empty. Cant delete" << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node Unlinked with key value : " << k << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "Node Unlinked with keys value : " << k << endl;
                }
                else
                {
                    cout << "Node doesn't exist with key value : " << k << endl;
                }
            }
        }
    }
    //Update node by key
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node Data updated successfully" << endl;
        }
        else
        {
            cout << "Node doesn't exist with key value : " << k << endl;
        }
    }
    //printing
    void printList()
    {
        if (head == NULL)
        {
            cout << "No Nodes in Singly Linked List";
        }
        else
        {
            cout << endl
                 << "Singly Linked List Values : ";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ")--> ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
    do
    {
        cout << endl;
        cout << "what operation do you want to perform? Select option numner. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;
        Node *n1 = new Node(); //dynamic memory allocaion

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node operation - \nEnter key & data of the node to be appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            break;
        case 2:
            cout << "Prepend Node operation - \nEnter key & data of the node to be prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;
        case 3:
            cout << "Insert Node after operation - \nEnter key of existing Node after which you want to insert this new node" << endl;
            cin >> k1;
            cout << "Enter key & data of the new node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodeAfter(k1, n1);
            break;
        case 4:
            cout << "Delete node by key operation - \nEnter key of the Node to be deleted" << endl;
            cin >> k1;
            s.deleteNodeByKey(k1);
            break;
        case 5:
            cout << "Update node by key operation - \nEnter key & new data to be updated";
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1, data1);
            break;
        case 6:
            s.printList();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter proper option number." << endl;
        }
    } while (option != 0);
    return 0;
}