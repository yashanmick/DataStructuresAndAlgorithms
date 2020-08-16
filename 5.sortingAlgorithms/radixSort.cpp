#include <iostream>
using namespace std;

//counting sort
void countingSort(int input_arr[], int size, int div)
{
    int output_arr[size];
    int count_arr[10] = {0};

    //to take a count of all elements in the input array
    for (int i = 0; i < size; i++)
    {
        count_arr[(input_arr[i] / div) % 10]++;
    }
    //cummulative count of count array to get the positions of elements
    //to be sorted in the output array
    for (int i = 1; i < 10; i++)
    {
        count_arr[i] = count_arr[i] + count_arr[i - 1];
    }
    //placing input array elements into output array in proper positions
    //such that the result is a sorted array in ascending orger
    for (int i = size - 1; i >= 0; i--)
    {
        output_arr[count_arr[(input_arr[i] / div) % 10] - 1] = input_arr[i];
        count_arr[(input_arr[i] / div) % 10]--;
    }
    //copy output array elements to input array
    for (int i = 0; i < size; i++)
    {
        input_arr[i] = output_arr[i];
    }
};

//get max function
int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

//radix sort
void radixSort(int arr[], int size)
{
    int m = getMax(arr, size);
    for (int div = 1; m / div > 0; div *= 10)
    {
        countingSort(arr, size, div);
    }
}

int main()
{
    int size = 0;
    int range = 10;

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

    radixSort(arr, size);

    cout << "After Sorting : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}