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

class CircularLinkedList
{
public:
    Node *head;
    CircularLinkedList()
    {
        head = NULL;
    }
    //Check if the node exists using key value
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != head);
            return temp;
        }
    }
    //Append a node to the list
    void appendNode(Node *new_node)
    {
        if (nodeExists(new_node->key) != NULL)
        {
            cout << "Node already exists with key value : " << new_node->key << ". Append another node with different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = new_node;
                new_node->next = head;
                cout << "Node appended at the first head position" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                    ;
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
                new_node->next = head;
                cout << "Node Appended" << endl;
            }
        }
    }

    //Prepend Node - Attach a node at the start
    void prependNode(Node *new_node)
    {
        if (nodeExists(new_node->key) != NULL)
        {
            cout << "Node already exists with key value : " << new_node->key << ". Append another node with different key value" << endl;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = head;
            head = new_node;
            cout << "Node prepended" << endl;
        }
    }
    //Insert node after a particular node in the list
    void insertNodeAfter(int k, Node *new_node)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value of : " << k << endl;
        }
        else
        {

            if (nodeExists(new_node->key) != NULL)
            {
                cout << "Node already exists with key value : " << new_node->key << ". Appended another node with different key value" << endl;
            }
            else
            {
                if (ptr->next == head)
                {
                    new_node->next = head;
                    ptr->next = new_node;
                    cout << "Node inserted at the end;" << endl;
                }
                else
                {
                    new_node->next = ptr->next;
                    ptr->next = new_node;
                    cout << "Node inserted in between" << endl;
                }
            }
        }
    }

    //Delete node by unique key
    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exist with key value of : " << k << endl;
        }
        else
        {
            if (head == NULL)
            {
                cout << "Circular Linked List is already empty. Cant delete" << endl;
            }
            else if (ptr == head)
            {
                if (head->next == NULL)
                {
                    head = NULL;
                    cout << "Head node unlinked.. List empty" << endl;
                }
                else
                {
                    Node *ptr1 = head;
                    while (ptr1->next != head)
                    {
                        ptr1 = ptr1->next;
                    }
                    ptr1->next = head->next;
                    head = head->next;
                    cout << "Node Unlinked with key value : " << k << endl;
                }
            }
            else
            {
                Node *temp = NULL;
                Node *prev = head;
                Node *curr = head->next;
                while (curr != NULL)
                {
                    if (curr->key == k)
                    {
                        temp = curr;
                        curr = NULL;
                    }
                    else
                    {
                        prev = prev->next;
                        curr = curr->next;
                    }
                    prev->next = temp->next;
                    cout << "Node Unlinked with key value : " << k << endl;
                }
                prev = prev->next;
                cout << "Node Unlinked with keys value : " << k << endl;
            }
        }
    }

    //Update node
    void updateNodeByKey(int k, int new_data)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = new_data;
            cout << "Node data updated successfully" << endl;
        }
        else
        {
            cout << "Node does not exists with key value : " << k << endl;
        }
    }

    //printing
    void printList()
    {
        if (head == NULL)
        {
            cout << "No nodes in Circular Linked List" << endl;
        }
        else
        {
            cout << endl
                 << "head address : " << head << endl;
            cout << "Circular Linked List values : " << endl;
            Node *temp = head;
            do
            {
                cout << "(" << temp->key << "," << temp->data << "," << temp->next << ")-->";
                temp = temp->next;
            } while (temp != head);
        }
    }
};

int main()
{
    CircularLinkedList obj;
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