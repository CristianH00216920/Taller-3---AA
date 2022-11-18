Funcion withDrawCash( *dollarBills, balance, numb) // funcion con parametros

	Definir T[balance + 1 ] como Entero // preparamos el arreglo T y agregar una celda extra para evitar no violar segmentos
	
	T[0] = 0 // inicamos nuestra primer celda del arreglo en 0, llenado manual
	
	Para i = 1 Hasta <= balance Con Paso 1 Hacer // recorremos el arreglo
	
		T[i] = INT_MAX;		  // fijamos un limite maximo para nuestra variable i
		Definir result como Entero = INT_MAX; // fijamos un limite maximo para nuestro resultados
		
		Para j = 0 Hasta < numb Con Paso 1 Hacer // recorremos un segundo arreglo con el número de billetes a utilizar
		
			Si i - dollarBills[j] >= 0 Entonces // verificar que el valor en i sea mayor o igual a 0
				result = T[i - dollarBills[j]] // el resultado se almacena en la variable result, dependiendo de la informacion se verifica que T sea el menor dato.
			Fin si
			
			Si result != INT_MAX Entonces // verificar que nuestro resultado no exeda el limite
				T[i] = min(T[i], result + 1) // comparamos los datos almacenados en las posicione y vemos cual es el menor billete y si podemos dar cambio con ese
				// almacenamos el dato en nuestro arreglo T[i]
			Fin Si
			
		Fin Para
		
	Fin Para
	
	retornar T[balance] // retornamos la cantidad de billetes a entregar
	
Fin Funcion



Algoritmo Ejercicio4
	
	Dimension dollarBills[1, 5, 10, 20, 100] // guardamos las denominaciones de los billetes en una arreglo
	
	Definir balance Como Entero // variable para cantidad de dinero a retirar
	Escribir ("Ingrese la cantidad de billetes a retirar: ")
	leer balance // pedir cantidad de dinero a retirar
	
	Si balance >= 1 && balance <= pow(10, 9) Entonces
		Escribir ("El numero de billetes a entregar: "), withDrawCash(dollarBills, balance, 5) // Llamamos funcion y pasamos variables como parametro
		// imprimimos la cantidad minima de billetes que optendra al sacar su balance total.
	SiNo
		Escribir ("No se puede procesar el monto. ")
	Fin Si
	
FinAlgoritmo

