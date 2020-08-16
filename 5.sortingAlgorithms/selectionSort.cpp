#include <iostream>
using namespace std;

void selectionSort(int arr[])
{
    for (int i = 0; i < 4; i++)
    {
        int min = i;

        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
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
    cout << "UNSORTED ARRAY : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;

    selectionSort(arr);

    cout << "SORTED ARRAY : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}