#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node *n)
    {
        head = n;
    }

    //Check if node exists using key value
    Node *checkIfNodeExist(int k)
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

    //Append a node to the list
    void appendNode(Node *n)
    {
        if (checkIfNodeExist(n->key) != NULL)
        {
            cout << "Node Already exists with key value :" << n->key << ". Append another node with different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended as head node" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->prev = ptr;
                cout << "Node appended" << endl;
            }
        }
    }

    //Prepend node : attach a node at the start
    void prependNode(Node *n)
    {
        if (checkIfNodeExist(n->key) != NULL)
        {
            cout << "Node Already exists with key value :" << n->key << ". Append another node with different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node prepended as head node" << endl;
            }
            else
            {
                head->prev = n;
                n->next = head;
                head = n;
                cout << "Node prepended" << endl;
            }
        }
    }

    //Insert node after
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = checkIfNodeExist(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value: " << k << endl;
        }
        else
        {
            if (checkIfNodeExist(n->key) != NULL)
            {
                cout << "Node Already exists with key value : " << n->key << ". Append another node with different key value" << endl;
            }
            else
            {
                cout << "Inserting" << endl;
                Node *nextNode = ptr->next;

                //inserting at the end
                if (nextNode == NULL)
                {
                    ptr->next = n;
                    n->prev = ptr;
                    cout << "Node inserted at the END" << endl;
                }
                //inserting in between
                else
                {
                    n->next = nextNode;
                    nextNode->prev = n;
                    n->prev = ptr;
                    ptr->next = n;

                    cout << "Node inserted in between" << endl;
                }
            }
        }
    }

    //Deleting a node
    void deleteNodeByKey(int k)
    {
        Node *ptr = checkIfNodeExist(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value: " << k << endl;
        }
        else
        {
            if (head == NULL)
            {
                cout << "Doubly Linked List already empty. Cant delete" << endl;
            }
            else if (head != NULL)
            {
                if (head->key == k)
                {
                    head = head->next;
                    cout << "Node unlinked with keys value :" << k << endl;
                }
                else
                {
                    Node *nextNode = ptr->next;
                    Node *prevNode = ptr->prev;
                    //deleting at the end
                    if (nextNode == NULL)
                    {
                        prevNode->next = NULL;
                        cout << "Node deleted at the end" << endl;
                    }
                    //deleting in between
                    else
                    {
                        prevNode->next = nextNode;
                        nextNode->prev = prevNode;
                        cout << "Node deleted in between" << endl;
                    }
                }
            }
        }
    }

    //Update node
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = checkIfNodeExist(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data updated successfully" << endl;
        }
        else
        {
            cout << "Node dosen't exist with key value : " << k << endl;
        }
    }

    //Printing
    void printList()
    {
        if (head == NULL)
        {
            cout << "No nodes in doubley linked list";
        }
        else
        {
            cout << endl
                 << "Double Linked List values : ";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") <--> ";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    DoublyLinkedList obj;
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
            obj.appendNode(n1);
            break;
        case 2:
            cout << "Prepend Node operation - \nEnter key & data of the node to be prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.prependNode(n1);
            break;
        case 3:
            cout << "Insert Node after operation - \nEnter key of existing Node after which you want to insert this new node" << endl;
            cin >> k1;
            cout << "Enter key & data of the new node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertNodeAfter(k1, n1);
            break;
        case 4:
            cout << "Delete node by key operation - \nEnter key of the Node to be deleted" << endl;
            cin >> k1;
            obj.deleteNodeByKey(k1);
            break;
        case 5:
            cout << "Update node by key operation - \nEnter key & new data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            obj.updateNodeByKey(key1, data1);
            break;
        case 6:
            obj.printList();
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