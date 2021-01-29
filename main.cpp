#include <iostream>
#include <random>
#include <time.h>
#include <string>

using namespace std;

// Ariel Fernando Reyes ---- Castellanos 11921023
void sumatoria_recu(int num, int i, double z) // creacion del metodo recursivo para la sumatoria 
{
	if (num>=i)
	{
		double parte_arriba = 0; 
		double parte_abajo = 0;
		double div = 0;
		// las variables de arriba son para las partes de la division (p1/p2)
		parte_arriba = (2 * i) - 1;
		parte_abajo = i * (i + 1);
		div = (parte_arriba) / (parte_abajo); // se efectua la division
		z = z + div; // acumulan y suman las respuestas 
		i++;
		sumatoria_recu(num, i, z); // se hace el metodo recursivo
	}
	else if (i >= num) // y cuando i llegue al valor de m se parara 
	{
		cout << " Resp//  " << z << '\n'; // se imprime 
	}
}
//

void orden_arre(int arr[], bool band, int tam) // metodo recursivo para ordenar el arreglo 
{

	if (band ==true)  // usaremos una bandera para el metodo de ordenamiento
	{
		int aus = 0;
		band = false; 
		for (int j = 0; j < tam - 1; j++)
		{
			if (arr[j] > arr[j + 1]) // se ve que valor es mayor a cual y si lo es se cambia usando la variable de auxilio aus 
			{
				aus = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aus;
				band = true;
			}
		}
		//
		orden_arre(arr, band, tam);
	}
	else // el else es para cuando de recorrer se imprima 
	{
		for (int i = 0; i < tam; i++) 
		{
			cout << "{" << arr[i] << "}";
		}
	}
}

int main()
{
    cout<<'\n';
	srand(time(NULL));

	int opc = 1;

	while (opc != 4) // creacion del menu con respuesta de usuario 
	{
		cout << "............MENU............." << endl;
		cout << "1................. Ejercicio 1 Tabla" << endl;
		cout << "2.................Ejercicio 2 Ordenar Recursivo" << endl;
		cout << "3.................Ejercicio 3 Sumatoria Recursivo" << endl;
		cout << "4................. salir" << endl;
		cout << "Ingrese la opcion que desea: " << endl;
		cin >> opc;

		switch (opc)
		{
		case 2:
		{

			int ar[20];
			cout << "Desorde= "; // llanamos e imprimimos la matriz con numeros aleatorios 
			for (int i = 0; i < 20; i++)
			{
				ar[i] = 1 + (rand() % 90);
				cout << "[" << ar[i] << "]";
			}

			cout << '\n';

			cout << "Orden=";
			orden_arre(ar, true, 20); // aca imprimimos el arreglo ordenado 
		}
		break;

		case 3:
		{

			int uno = 0;
			int dos = 1;
			double resp = 0;

			cout << "ponga el valor de x:";
			cin >> uno; // el usuario ingresa el valor de 
			while (uno <= 0) // validacion 
			{
				cout << "Ingrese un valor mayor que 0:";
				cin >> uno;
			}
			sumatoria_recu(uno, dos, resp); // se imprime el resultado 
		}

		break;

		case 1:
		{

			cout << "Escriba la cadena: ";
			string cadena; 

			cin >> cadena;
			int res = 0;
			int tam; 
			tam = cadena.length(); 

			for (int i = 0; i < tam; i++){ // for para recorrer toda la cadena que el usuario ingrese 
			/*Luego solo son puras validacion por segun la posicion de arreglo y lo que exita en el
			y si en la posicion cadena[0] hay una 'A', y la posicion 3 cifras mayor que esa el resultado sera 0
			*/

				if (cadena[i] == 'A' && i == 1)
				{

					res = 0;
					if (cadena[i - 1] == '0' && cadena[i + 3] == '1')
					{
						res = 0;
					}
					else
					{
						res = 1;
					}
					if (cadena[i - 1] == '0' && cadena[i + 3] == '0')
					{
						res = 0;
					}
					else
					{
						res = 1;
					}
					if (cadena[i - 1] == '1' && cadena[i + 3] == '0')
					{
						res = 0;
					}

					else
					{
						res = 1;
					}
				}
				else if (cadena[i] == 'O' && i == 1)
				{
					if (res == '0' && cadena[i + 2] == '0')
					{
						res = 0;
					}
					else
					{
						res = 1;
					}
				}
				else if (cadena[i] == 'A')
				{

					if (res == 1 && cadena[i + 3] == '0')
					{
						res = 0;
					}
					else
					{
						res = 1;
					}

					if (res == 0 && cadena[i + 3] == '1')
					{
						res = 0;
					}
					else
					{
						res = 1;
					}

					if (res == 0 && cadena[i + 3] == '0')
					{
						res = 0;
					}
					else
					{
						res = 1;
					}

					if (cadena[i] == 'O')
					{
						if (res == 0 && cadena[i + 2] == '0')
						{
							res = 0;
						}
						else
						{
							res = 1;
						}
					}
				}
			}

			if (res == 0)
			{
				cout << "FALSO" << endl;
			}
			else
			{
				cout << "VERDADERO" << endl;
			}

			break;
		}
		}
	}
	return 0;
}

