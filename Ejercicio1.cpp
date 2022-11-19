#include <iostream>

using namespace std;

int changeValues(int *a, int *b) //funcion con parametros
{
    int temp = *a; //cambio de variables, usando una temporal
    *a = *b; // cambiando valores
    *b = temp; // dejando variable temporal
}

int max_1d_mult(int *A, int n)
{
    int Mult[n + 1]; // preparamos el arreglo Mult y agregar una celda extra para evitar no violar segmentos
    int s = 1, smax = A[0], smin = A[0]; //declaramos variables a usar y arreglos
    for (int i = 1; i <= n; i++)// recorremos el arreglo
    {
        if (A[i - 1] < 0) //validamos cuando encontremos un numero negativo
        {
            changeValues(&smax, &smin); //llamando funcion para cambiar valores
        }
        smax = max(A[i - 1], smax * A[i - 1]); //buscando el valor mas alto y multiplicando por el valor guardado en A
        smin = min(A[i - 1], smin * A[i - 1]); //buscando el valor mas minimo y multiplicando por el valor guardado en B
        s = max(s, smax);  //buscar valor maximo de nuestra suma y variable
        Mult[i] = s; //asignando valor de arreglo a nuestra variable
    }
    int prodMax = Mult[n]; // asignar valor final a nueva variable
    return prodMax; // retornando valor maximo del producto
}


int main(void){
   int n; //declaramos variable
    
    do
    {  
        cout << "Ingrese el tamaño del arreglo: ";
        cin >> n; //pedimos tamaño del arreglo
    } while (n < 1 || n > 100);  //validar que no funcione cuando ingresemos un numero menor a 1 ó mayor a 100
    int A[n];  //llenando el arreglo

    for (int i = 0; i < n; i++) //recorrer celdas del arreglo
    {
        do
        { 
            cout << "Ingrese el elemento " << i << " del arreglo: ";
            cin >> A[i]; //llenar filas de nuestro arreglo principal
        } while (A[i] > 99999); //validar que los datos no tengan mas de 5 digitos
    }

    cout << "El resultado máximo es: " << max_1d_mult(A, n); // imprimir resultado, funcion por parametros

    return 0;
}