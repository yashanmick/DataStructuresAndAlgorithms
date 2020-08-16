#include <iostream>
using namespace std;

void bubbleSort(int a[])
{
    int rounds = 0;
    for (int i = 0; i < 5; i++)
    {
        rounds++;
        for (int j = 0; j < (5 - i - 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "No of rounds : " << rounds << endl;
};

int main()
{
    int arr[5];
    cout << "Enter 5 numbers in random order: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    cout << "Before Sorting : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;

    bubbleSort(arr);

    cout << "After Sorting : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}