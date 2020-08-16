#include <iostream>
using namespace std;

void countingSort(int input_arr[], int s, int r)
{
    int output_arr[s];
    int count_arr[r];

    //initialize all the element to 0
    for (int i = 0; i < r; i++)
    {
        count_arr[i] = 0;
    }
    //to take a count of all elements in the input array
    for (int i = 0; i < s; i++)
    {
        ++count_arr[input_arr[i]];
    }
    //cummulative count of count array to get the positions of elements
    //to be sorted in the output array
    for (int i = 1; i < r; i++)
    {
        count_arr[i] = count_arr[i] + count_arr[i - 1];
    }
    //placing input array elements into output array in proper positions
    //such that the result is a sorted array in ascending orger
    for (int i = 0; i < s; i++)
    {
        output_arr[--count_arr[input_arr[i]]] = input_arr[i];
    }
    //copy output array elements to input array
    for (int i = 0; i < s; i++)
    {
        input_arr[i] = output_arr[i];
    }
};

int main()
{
    int size = 0;
    int range = 10;

    cout << "Enter the size of the array : " << endl;
    cin >> size;

    cout << "Enter " << size << " numbers in random order (range 0-9): " << endl;

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

    countingSort(arr, size, range);

    cout << "After Sorting : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}