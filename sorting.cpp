#include <iostream>
#include <ctime>
using namespace std;

int iterations = 0;
int swaps = 0;

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            iterations++;

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
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            iterations++;

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
            iterations++;
            i++;
        }

        while (j >= left && arr[j] > pivot)
        {
            iterations++;
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

// Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < n; j++)
        {
            iterations++;

            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        swap(arr[i], arr[min_idx]);
        swaps++;
    }
}

int main()
{
    int choice;

    int sizes[] = {10, 50, 100, 1000, 5000};

    do
    {
        cout << "\nSORTING ALGORITHMS";
        cout << "\n1. Bubble Sort";
        cout << "\n2. Insertion Sort";
        cout << "\n3. Quick Sort";
        cout << "\n4. Selection Sort";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            cout << "\nRESULTS";

            for (int k = 0; k < 5; k++)
            {
                int n = sizes[k];

                int* arr = new int[n];

                for (int i = 0; i < n; i++)
                {
                    arr[i] = rand();
                }

                iterations = 0;
                swaps = 0;

                clock_t start = clock();

                switch (choice)
                {
                case 1:
                    bubbleSort(arr, n);
                    break;

                case 2:
                    insertionSort(arr, n);
                    break;

                case 3:
                    quickSort(arr, 0, n - 1);
                    break;

                case 4:
                    selectionSort(arr, n);
                    break;
                }

                clock_t end = clock();

                double timeTaken =
                    double(end - start) / CLOCKS_PER_SEC;

                cout << "\n\nInput Size: " << n;
                cout << "\nSwaps: " << swaps;
                cout << "\nIterations: " << iterations;
                cout << "\nClock Time: " << timeTaken << " seconds";
            }
        }
        else if (choice != 5)
        {
            cout << "\nInvalid Choice!";
        }

    } while (choice != 5);

    return 0;
}
