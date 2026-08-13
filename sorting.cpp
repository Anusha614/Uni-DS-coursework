#include <iostream>
#include <ctime>
using namespace std;

int comparisons = 0;
int swaps = 0;

// Bubble Sort
void bubbleSort(int arr[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
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
            comparisons++;

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Partition Function
int partition(int arr[], int left, int right)
{
    int pivot = arr[left];

    int i = left + 1;
    int j = right;

    while (i <= j)
    {
        while (i <= right && arr[i] <= pivot)
        {
            comparisons++;
            i++;
        }

        while (j >= left && arr[j] > pivot)
        {
            comparisons++;
            j--;
        }

        if (i < j)
        {
            swaps++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    swaps++;

    return j;
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

void selectionSort (int arr[])
{
    for (int i = 0; i < 4; i++){

        int min_idx = i;

        for (int j =i + 1; j < 5; j++){

            comparisons ++;

            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }

        }

        swap(arr[i], arr[min_idx]);
        swaps ++;

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
    cout << "\n4. Selection Sort";
    cout << "\nEnter your choice: ";
    cin >> choice;

    clock_t start = clock();

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

    case 4:
        selectionSort(arr);
        break;

    default:
        cout << "Invalid Choice!";
        return 0;
    }

    clock_t end = clock();

    cout << "\nSorted Array: ";

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSwaps performed: " << swaps;
    cout << "\nComparisons performed: " << comparisons;
    cout << "\nTime taken to perform: " << timeTaken;
    

    cout << endl;

    return 0;
}