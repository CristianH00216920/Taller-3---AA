#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

int coinExchange(int *coins, int target, int coinsNumb)
{

	int T[target + 1];

	T[0] = 0;

	for (int i = 1; i <= target; i++)
	{

		T[i] = INT_MAX;
		int result = INT_MAX;

		for (int c = 0; c < coinsNumb; c++)
		{
			if (i - coins[c] >= 0)
			{
				result = T[i - coins[c]];
			}

			if (result != INT_MAX)
			{
				T[i] = min(T[i], result + 1);
			}
		}
	}

	return T[target];
}

int main()
{
	int coins[] = {1, 5, 10, 20, 100}; // denomination of dollars, arrays for values to use.

	int target; // amoung of dollars that will be withdraw
	cout << "Ingrese cantidad de dolares: ";
	cin >> target;

	if (target >= 1 && target <= pow(10, 9))
	{
		int coin = coinExchange(coins, target, 5);
		cout << "El numero de monedas minimo es: " << coin;
	}
	else
	{
		cout << "\nNo se puede procesar el monto. ";
	}

	return 0;
}