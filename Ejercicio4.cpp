#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

int withDrawCash(int *dollarsBills, int balance, int numb)
{

    int T[balance + 1];

    T[0] = 0;

    for (int i = 1; i <= balance; i++)
    {

        T[i] = INT_MAX;
        int result = INT_MAX;

        for (int j = 0; j < numb; j++)
        {
            if (i - dollarsBills[j] >= 0)
            {
                result = T[i - dollarsBills[j]];
            }

            if (result != INT_MAX)
            {
                T[i] = min(T[i], result + 1);
            }
        }
    }

    return T[balance];
}

int main()
{
    int dollarsBills[] = {1, 5, 10, 20, 100}; // denomination of dollars, arrays for values to use.

    int balance; // amoung of dollars that will be withdraw
    cout << "Ingrese cantidad de dolares: ";
    cin >> balance;

    if (balance >= 1 && balance <= pow(10, 9))
    {
        int dollar = withDrawCash(dollarsBills, balance, 5);
        cout << "El numero de monedas minimo es: " << dollar;
    }
    else
    {
        cout << "\nNo se puede procesar el monto. ";
    }

    return 0;
}