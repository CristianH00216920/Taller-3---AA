Funcion max_1d_Range_Sum( *A , n) // funcion con parametros, tamaño y arreglo A

	M[n+1], S = 0 como Entero // preparamos el arreglo M y agregar una celda extra para evitar no violar segmentos, asignamos nuestro acumular S
	
	M[0] = 0 // inicamos nuestra primer celda del arreglo en 0, llenado manual
	
	Para i=1 Hasta <= n Con Paso 1 Hacer
	
		S = max(S + A[i - 1], A[i - 1]); // comparar sumatoria actual mas el dato actual para deteminar nuevo valor de la sumatoria
        M[i] = max(S, M[i - 1]); // comparar sumatoria con datos actual de M, para modificar informacion en M[i]
		
		Si M[i] % 2 == 0 Entonces // validar que los valores sumados hasta el momento sea divisible por 2
			Escribir ("El valor sumando es divisible entre 2")
			retornar M[i] // retornar los primeros valores sumados (par) que sea divisible por 2
		Fin Si
		
	Fin Para
	
	Escribir ("El valor sumando no es divisible entre 2")
	retornar M[n] // retornar el total de la sumatoria
	
Fin Funcion


Algoritmo Ejercicio2
	
	Definir n Como Entero // variable que almacena el tamaño del arreglo
	
	Mientras n < 1 or n > 100 Hacer // si el tamaño del arreglo es menor a 1 o mayor a 100, se vuelve a pedir el tamaño del arreglo
		Escribir ("Ingrese el tamaño del arreglo: ")
		leer n // se almacena el tamaño del arreglo
	Fin Mientras
	
	Dimension  A[n] // arreglo de tamano "n"
	
	Para i=0 Hasta < n Con Paso 1 Hacer // recorremos el arreglo para hacer su llenado
	
		Mientras A[i] < 1 or A[i] > 100 Hacer // si el datos el menor a 1 o mayor a 100, se vuelve a pedir hasta ingresar el correcto
			Escribir ("Ingrese el elemento "), i+1, (" del arreglo:")
			leer A[i] // llenamos el arreglo pidiendo datos por datos
		Fin Mientras
		
	Fin Para
	
	Escribir ("El valor sumado es: "), max_1d_Range_Sum(A, n) // imprimimos el valor sumado por medio de nuestra funcion y pasamos los parametro a utilizar
	
FinAlgoritmo







