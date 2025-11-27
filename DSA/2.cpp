#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
int main()
{
    int arr[] = {5, 15, 25, 35, 45};
    int n = 5;
    int target[] = {5, 25, 100};
    string cases[] = {"Best Case", "Avg Case", "Worst Case"};
    for (int i = 0; i < 3; i++)
    {
        int index = linearSearch(arr, n, target[i]);
        cout << cases[i] << ": ";
        if (index != -1)
        {
            cout << "Element " << target[i] << " found at index " << index << endl;
        }
        else
        {
            cout << "Element " << target[i] << " not found in the array\n"
                 << endl;
        }
    }
    return 0;
}