#include <iostream>

using namespace std;

int max_1d_range_sum(int *A, int n)
{
    int M[n + 1], S = 0;

    M[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        S = max(S + A[i - 1], A[i - 1]);
        M[i] = max(S, M[i - 1]);

        if (M[i] % 2 == 0)
        {
            system("cls");
            cout << "El valor sumado es divible entre 2";
            return M[i];
        }
    }

    system("cls");
    cout << "El valor sumado no es divible entre 2";
    return M[n];
}

int main()
{
    system("cls");
    int n;

    do
    {
        cout << "Ingrese el tamaño del arreglo: ";
        cin >> n;
    } while (n < 1 || n > 100);
    int A[n];

    for (int i = 0; i < n; i++)
    {
        do
        { //
            cout << "Ingrese el elemento " << i << " del arreglo: ";
            cin >> A[i];
        } while (A[i] < 1 || A[i] > 100);
    }

    cout << "\nEl valor sumado es: " << max_1d_range_sum(A, n);
    return 0;
}
