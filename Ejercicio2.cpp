#include <iostream>

using namespace std;

int max_1d_range_sum(int *A, int n) // funcion con parametros, tamaño y arreglo A
{
    int M[n + 1], S = 0; // preparamos el arreglo M y agregar una celda extra para evitar no violar segmentos, asignamos nuestro acumular S

    M[0] = 0; // inicamos nuestra primer celda del arreglo en 0, llenado manual

    for (int i = 1; i <= n; i++) // vamos a llenar los datos comenzando desde la posicion i+1
    {
        S = max(S + A[i - 1], A[i - 1]); // comparar sumatoria actual mas el dato actual para deteminar nuevo valor de la sumatoria
        M[i] = max(S, M[i - 1]);         // comparar sumatoria con datos actual de M, para modificar informacion en M[i]

        if (M[i] % 2 == 0) // validar que los valores sumados hasta el momento sea divisible por 2
        {
            system("cls");                                // limpieza pantalla
            cout << "El valor sumado es divible entre 2"; // imprimir información
            return M[i];                                  // retornar el primer valor sumado par que sea divisible por 2
        }
    }

    system("cls");

    cout << "El valor sumado no es divible entre 2"; // imprimir información
    return M[n];                                     // retornar el total de la sumatoria
}

int main(void)
{
    system("cls"); // limpieza de pantalla
    int n;         // variable que almacena el tamaño del arreglo

    do
    {
        cout << "Ingrese el tamaño del arreglo: "; // imprimir información
        cin >> n;                                  // se almacena el tamaño del arreglo
    } while (n < 1 || n > 100);                    // si el tamaño del arreglo es menor a 1 o mayor a 100, se vuelve a pedir el tamaño del arreglo
    int A[n];                                      // arreglo de tamano "n"

    for (int i = 0; i < n; i++) // recorremos el arreglo para hacer su llenado
    {
        do
        { //
            cout << "Ingrese el elemento " << i+1 << " del arreglo: ";
            cin >> A[i];                  // llenamos el arreglo pidiendo datos por datos
        } while (A[i] < 1 || A[i] > 100); // si el datos el menor a 1 o mayor a 100, se vuelve a pedir hasta ingresar el correcto
    }

    cout << "\nEl valor sumado es: " << max_1d_range_sum(A, n); // imprimimos el valor sumado por medio de nuestra funcion y pasamos los parametro a utilizar
}
 