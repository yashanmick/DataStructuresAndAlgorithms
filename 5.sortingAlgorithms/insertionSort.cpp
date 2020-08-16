#include <iostream>
using namespace std;

void insertionSort(int arr[])
{
    int j = 0;
    int key;

    for (int i = 0; i < 5; i++)
    {
        key = arr[i]; //picking the element
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

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

    insertionSort(arr);

    cout << "After Sorting : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}