#include <iostream>
using namespace std;

//partition function
int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;

    for (int i = s; i < e; i++)
    {
        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }

    //swapping pivot
    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

//quick sort function
void quickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);
        quickSort(arr, s, (p - 1)); //recursive quickSort call for left partition
        quickSort(arr, (p + 1), e); //recursive quickSort call for right partition
    }
}

int main()
{
    int size = 0;

    cout << "Enter the size of the array : " << endl;
    cin >> size;

    cout << "Enter " << size << " numbers in random order: " << endl;

    int myarr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> myarr[i];
    }
    cout << "Before Sorting : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarr[i] << "  ";
    }
    cout << endl;

    quickSort(myarr, 0, (size - 1));

    cout << "After Sorting : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarr[i] << "  ";
    }
    return 0;
}