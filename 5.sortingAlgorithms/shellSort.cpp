#include <iostream>
using namespace std;

void shellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < size; j++)
        {
            int temp = arr[j];
            int i = 0;

            for (i = j; (i >= gap) && (arr[i - gap]) > temp; i -= gap)
            {
                arr[i] = arr[i - gap];
            }
            arr[i] = temp;
        }
    }
}

int main()
{
    int size;

    cout << "Enter the size of the array : " << endl;
    cin >> size;

    cout << "Enter " << size << " numbers in random order : " << endl;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Before Sorting : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;

    shellSort(arr, size);

    cout << "After Sorting : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}