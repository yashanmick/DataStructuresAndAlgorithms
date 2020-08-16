#include <iostream>
using namespace std;

int binarySearch(int a[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[10];
    int num;
    int output;

    cout << "Please enter 10 elements in the array" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    cout << "Please enter a element to search" << endl;
    cin >> num;

    output = binarySearch(arr, 0, 9, num);

    if (output == -1)
    {
        cout << "No match found" << endl;
    }
    else
    {
        cout << "Match found at index position " << output << endl;
    }

    return 0;
}