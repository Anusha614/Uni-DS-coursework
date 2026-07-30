#include <iostream>
using namespace std;


struct Polynomial
{
    int coef;
    int exp;
};

int main()
{
    Polynomial p1[10], p2[10], sum[20];
    int n1, n2, k = 0;

   
    cout << "Enter number of terms in first polynomial: ";
    cin >> n1;

    cout << "Enter coefficient and exponent:\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> p1[i].coef >> p1[i].exp;
    }

    cout << "\nEnter number of terms in second polynomial: ";
    cin >> n2;

    cout << "Enter coefficient and exponent:\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> p2[i].coef >> p2[i].exp;
    }

  
    for (int i = 0; i < n1; i++)
    {
        sum[k] = p1[i];

        for (int j = 0; j < n2; j++)
        {
            if (p1[i].exp == p2[j].exp)
            {
                sum[k].coef = p1[i].coef + p2[j].coef;
                p2[j].coef = 0;   
                break;
            }
        }
        k++;
    }

   
    for (int i = 0; i < n2; i++)
    {
        if (p2[i].coef != 0)
        {
            sum[k] = p2[i];
            k++;
        }
    }

 
    cout << "\nResultant Polynomial:\n";

    for (int i = 0; i < k; i++)
    {
        if (sum[i].coef != 0)
        {
            cout << sum[i].coef << "x^" << sum[i].exp;

            if (i != k - 1)
                cout << " + ";
        }
    }

    cout << endl;

    return 0;
}