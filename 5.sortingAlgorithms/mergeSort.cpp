#include <iostream>
using namespace std;

//merge function
void merge(int arr[], int l, int m, int r)
{
    int i = l;     //starting index for left sub arr
    int j = m + 1; //starting index for right sub arr
    int k = l;     //starting index for temp arr

    int temp[5]; //temp arr

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i]; //arr[i] is smaller than arr[j]
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j]; //arr[j] is smaller than arr[i]
            j++;
            k++;
        }
    }

    while (i <= m)
    {
        temp[k] = arr[i]; //copying all elements from left subarr to temp as it is
        i++;
        k++;
    }

    while (j <= r)
    {
        temp[k] = arr[j]; //copying all elements from right subarr to temp as it is
        j++;
        k++;
    }

    //copying temp to original arr
    for (int s = l; s <= r; s++)
    {
        arr[s] = temp[s];
    }
}

//merge sort function
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int size;

    cout << "Enter the size of the array : " << endl;
    cin >> size;

    cout << "Enter " << size << " numbers in random order: " << endl;

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

    mergeSort(arr, 0, (size - 1));

    cout << "After Sorting : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}