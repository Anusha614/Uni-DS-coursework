#include <iostream>
using namespace std;

//input a matrix
void inputMatrix(int A[10][10], int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];
}

//matrix addition
void addMatrix(int A[10][10], int B[10][10], int r1, int c1, int r2, int c2)
{
    if (r1 != r2 || c1 != c2)
    {
        cout << "Addition not possible!\n";
        return;
    }

    cout << "\nAddition of Matrices:\n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            cout << A[i][j] + B[i][j] << " ";
        cout << endl;
    }
}

//matrix subtraction
void subtractMatrix(int A[10][10], int B[10][10], int r1, int c1, int r2, int c2)
{
    if (r1 != r2 || c1 != c2)
    {
        cout << "Subtraction not possible!\n";
        return;
    }

    cout << "\nSubtraction of Matrices:\n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            cout << A[i][j] - B[i][j] << " ";
        cout << endl;
    }
}

//matrix multiplication
void multiplyMatrix(int A[10][10], int B[10][10], int r1, int c1, int r2, int c2)
{
    if (c1 != r2)
    {
        cout << "Multiplication not possible!\n";
        return;
    }

    int C[10][10];

    cout << "\nMultiplication of Matrices:\n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];

            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

//transpose
void transposeMatrix(int A[10][10], int r, int c)
{
    cout << "\nTranspose of First Matrix:\n";
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
            cout << A[j][i] << " ";
        cout << endl;
    }
}

//upper triangle matrix
void upperTriangular(int A[10][10], int r, int c)
{
    if (r != c)
    {
        cout << "Upper triangular matrix is possible only for a square matrix.\n";
        return;
    }

    cout << "\nUpper Triangular Matrix:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i <= j)
                cout << A[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    int A[10][10], B[10][10];
    int r1, c1, r2, c2;
    int choice;

    cout << "Enter rows and columns of First Matrix: ";
    cin >> r1 >> c1;

    cout << "Enter elements of First Matrix:\n";
    inputMatrix(A, r1, c1);

    cout << "Enter rows and columns of Second Matrix: ";
    cin >> r2 >> c2;

    cout << "Enter elements of Second Matrix:\n";
    inputMatrix(B, r2, c2);

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Matrix Addition\n";
        cout << "2. Matrix Subtraction\n";
        cout << "3. Matrix Multiplication\n";
        cout << "4. Transpose of First Matrix\n";
        cout << "5. Upper Triangular Matrix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addMatrix(A, B, r1, c1, r2, c2);
            break;

        case 2:
            subtractMatrix(A, B, r1, c1, r2, c2);
            break;

        case 3:
            multiplyMatrix(A, B, r1, c1, r2, c2);
            break;

        case 4:
            transposeMatrix(A, r1, c1);
            break;

        case 5:
            upperTriangular(A, r1, c1);
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}