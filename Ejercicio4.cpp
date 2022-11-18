#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

int withDrawCash(int *dollarsBills, int balance, int numb) // funcion con parametros
{

	int T[balance + 1]; // preparamos el arreglo T y agregar una celda extra para evitar no violar segmentos

	T[0] = 0; // inicamos nuestra primer celda del arreglo en 0, llenado manual

	for (int i = 1; i <= balance; i++) // recorremos el arreglo
	{

		T[i] = INT_MAX;		  // fijamos un limite maximo para nuestra variable i
		int result = INT_MAX; // fijamos un limite maximo para nuestro resultados

		for (int j = 0; j < numb; j++) // recorremos un segundo arreglo con el número de billetes a utilizar
		{
			if (i - dollarsBills[j] >= 0) // verificar que el valor en i sea mayor o igual a 0
			{
				result = T[i - dollarsBills[j]]; // el resultado se almacena en la variable result, dependiendo de la informacion se verifica que T sea el menor dato.
			}

			if (result != INT_MAX) // verificar que nuestro resultado no exeda el limite
			{
				T[i] = min(T[i], result + 1); // comparamos los datos almacenados en las posicione y vemos cual es el menor billete y si podemos dar cambio con ese
											  // almacenamos el dato en nuestro arreglo T[i]
			}
		}
	}

	return T[balance]; // retornamos la cantidad de billetes a entregar
}

int main()
{
	system("cls");							  // Limpieza de pantalla
	int dollarsBills[] = {1, 5, 10, 20, 100}; // guardamos las denominaciones de los billetes en una arreglo

	int balance;										// variable para cantidad de dinero a retirar
	cout << "Ingrese cantidad de billetes a retirar: "; // imprimir información
	cin >> balance;										// pedir cantidad de dinero a retirar

	if (balance >= 1 && balance <= pow(10, 9)) //
	{
		cout << "\nEl numero de billetes a entregar es: " << withDrawCash(dollarsBills, balance, 5); // Llamamos funcion y pasamos variables como parametros
																									 // imprimimos la cantidad minima de billetes que optendra al sacar su balance total.
	}
	else
	{
		cout << "\nNo se puede procesar el monto. "; // imprimir información
	}

	return 0; // retornando 0
}