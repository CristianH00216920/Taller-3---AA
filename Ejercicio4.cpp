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
	system("cls");
	int dollarsBills[] = {1, 5, 10, 20, 100};

	int balance;
	cout << "Ingrese cantidad de billetes a retirar: ";
	cin >> balance;

	if (balance >= 1 && balance <= pow(10, 9))
	{
		int dollar = withDrawCash(dollarsBills, balance, 5);
		cout << "\nEl numero de billetes a entregar es: " << dollar;
	}
	else
	{
		cout << "\nNo se puede procesar el monto. ";
	}

	return 0;
}