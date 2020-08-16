#include <iostream>

using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int arr[5];

public:
    Queue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (rear == (sizeof(arr) - 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    int dequeue()
    {
        int temp;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else if (front == rear)
        {
            temp = arr[front];
            arr[front] = 0;
            rear = -1;
            front = -1;
            return temp;
        }
        else
        {
            temp = arr[front];
            arr[front] = 0;
            front++;
            return temp;
        }
    }
    int count()
    {
        return (rear - front + 1);
    }
    void display()
    {
        cout << "all values in the queue are " << endl;
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q1;
    int option, value;
    do
    {
        cout << endl;
        cout << "what operation do you want to perform? Select option numner. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enqueue operation \nEnter an item to Enqueue in the Queue" << endl;
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            cout << "Dequeue operation \nDequeue value : " << q1.dequeue() << endl;
            break;
        case 3:
            if (q1.isEmpty())
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                cout << "Queue is not empty" << endl;
            }
            break;
        case 4:
            if (q1.isFull())
            {
                cout << "Queue is full" << endl;
            }
            else
            {
                cout << "Queue is not full" << endl;
            }
            break;
        case 5:
            cout << "Count operation \nCount of items in queue : " << q1.count() << endl;
            break;
        case 6:
            cout << "Display function called \nDisplaying all the elements in the queue : " << endl;
            q1.display();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter proper option number " << endl;
        }
    } while (option != 0);
    {
    }
    return 0;
}