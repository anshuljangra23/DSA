#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr1[100], arr2[100];

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];   // Copy for insertion sort
    }

    cout << "\nOriginal Array: ";
    printArray(arr1, n);

    bubbleSort(arr1, n);
    cout << "\nArray after Bubble Sort: ";
    printArray(arr1, n);

    insertionSort(arr2, n);
    cout << "Array after Insertion Sort: ";
    printArray(arr2, n);

    return 0;
}
