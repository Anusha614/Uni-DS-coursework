#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int arr[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[])
{
    for (int i = 1; i < 5; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Partition Function
int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int p = partition(arr, left, right);

        quickSort(arr, left, p - 1);
        quickSort(arr, p + 1, right);
    }
}

int main()
{
    int arr[5];

    cout << "Enter 5 array elements: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    int choice;

    cout << "\n1. Bubble Sort";
    cout << "\n2. Insertion Sort";
    cout << "\n3. Quick Sort";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        bubbleSort(arr);
        break;

    case 2:
        insertionSort(arr);
        break;

    case 3:
        quickSort(arr, 0, 4);
        break;

    default:
        cout << "Invalid Choice!";
        return 0;
    }

    cout << "\nSorted Array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}