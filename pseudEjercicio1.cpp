Funcion changeValues(*a, *b)//funcion con parametros

	definir temp Como Entero
	
	temp = *a //cambio de variables, usando una temporal
    *a = *b // cambiando valores
    *b = temp // dejando variable temporal
	
Fin Funcion

Funcion max_1d_mult(*A, n)

	Definir int Mult[n + 1] como entro // preparamos el arreglo Mult y agregar una celda extra para evitar no violar segmentos
	
	Definir s = 1, smax = A[0], smin = A[0] Como Entero //declaramos variables a usar y arreglos
	
	Para i = 1 Hasta < n Con Paso 1 Hacer
		
		Si A[i - 1] < 0 Entonces //validamos cuando encontremos un numero negativo
			acciones_por_verdadero
		Fin Si
		
		smax = max(A[i - 1], smax * A[i - 1]); //buscando el valor mas alto y multiplicando por el valor guardado en A
        smin = min(A[i - 1], smin * A[i - 1]); //buscando el valor mas minimo y multiplicando por el valor guardado en B
        s = max(s, smax);  //buscar valor maximo de nuestra suma y variable
        Mult[i] = s; //asignando valor de arreglo a nuestra variable
		
	Fin Para
	
	int prodMax = Mult[n]; // asignar valor final a nueva variable
    return prodMax; // retornando valor maximo del producto
	
Fin Funcion



Algoritmo Ejercicio1
	
	Definir n Como Entero //declaramos variable
	
	Mientras n < 1 | n > 100 Hacer //validar que no funcione cuando ingresemos un numero menor a 1 ó mayor a 100
		Escribir ("Ingrese el tamaño del arreglo: ") 
        leer n; //pedimos tamaño del arreglo
	Fin Mientras
	
	Dimension A[n] //llenando el arreglo
	
	Para i = 0 Hasta < n Con Paso 1 Hacer
		Mientras A[i] > 99999 Hacer //validar que los datos no tengan mas de 5 digitos
			Escribir ("Ingrese el elemento " ), i+1 ,(" del arreglo: ")
			leer A[i] //llenar filas de nuestro arreglo principa
		Fin Mientras
		
	Fin Para
	
	Escribir ("El resultado máximo es: " ), max_1d_mult(A, n); // imprimir resultado, funcion por parametros
	
FinAlgoritmo







