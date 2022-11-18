#include <iostream>

using namespace std;

int max_1d_range_mult(int* A, int n)
{
    int M[n + 1], mult = 1; // M es la matriz de resultados y mult es la variable que guarda la multiplicacion
    int Max[n + 1];         // Max es la matriz que guarda los valores maximos de cada fila
    int Min[n + 1];         // Min es la matriz que guarda los valores minimos de cada fila
    M[0] = 1;
    for (int i = 0; i < n; i++)
    {
        mult = A[i];     // Se multiplica el valor de la matriz A por la variable mult
        M[i + 1] = mult; // Se guarda el valor de la multiplicacion en la matriz M
        if (mult > 0)    // Separamos los valores de las respuestas de las multiplicaciones en base a si son positivos o negativos
        {
            Max[i + 1] = mult; // Si es positivo, se guarda en la matriz Max
            Min[i + 1] = 1;
        }
        else
        {
            Max[i + 1] = 1;
            Min[i + 1] = mult; // Si es negativo, se guarda en la matriz Min
        }
    }

    return M[n]; // Se retorna el valor de la matriz M
}

int main(void)
{
    int n; // Variable que almacena el tamaño del arreglo

    // Utilizamos una estructura de Do-while para que el usuario ingrese un tamaño de arreglo válido (mayor a 0 y menor a 100)
    do
    {
        cout << "Ingrese el tamaño del arreglo: ";
        cin >> n;               // Se almacena el tamaño del arreglo
    } while (n < 1 || n > 100); // Si el tamaño del arreglo es menor a 1 o mayor a 100, se vuelve a pedir el tamaño del arreglo
    int A[n];                   // Arreglo de tamaño n

    for (int i = 0; i < n; i++) // Llenamos el arreglo
    {
        do
        { // Si es mayor a 5 digitos
            cout << "Ingrese el elemento " << i + 1 << " del arreglo: ";
            cin >> A[i];
        } while (A[i] > 99999); // Si el elemento del arreglo es mayor a 5 digitos, se vuelve a pedir el elemento del arreglo
    }

    cout << "El resultado máximo es: " << max_1d_range_mult(A, n) << ".\n";

    return 0;
}