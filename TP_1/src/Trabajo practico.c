/*
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funcion.h"
float x;
float y;
float z;
int opcion;


float tarjetaDeDebitoZ;
float tarjetaDeCreditoZ;
float bitcoinCostoZ;
float precioUnitarioZ;


float tarjetaDeDebitoY;
float tarjetaDeCreditoY;
float bitcoinCostoY;
float precioUnitarioY;

float diferenciaPrecio;


int main(void)
{
	setbuf(stdout, NULL);

	do
	{
		printf("opcion 1 = Ingrese los kilometros \n");
		printf("opcion 2 = Ingresar el coste del viaje \n");
		printf("opcion 3 = Calculo de los costos \n");
		printf("opcion 4 = informe de resultados \n");
		printf("opcion 5 = Carga forzada de datos \n");
		printf("opcion 6 = salir \n");
		scanf("%d" , &opcion);

		switch (opcion)
		{
		case 1:
			x = pedirNumero ("ingrese los kilometros");
		break;
		case 2:
			y = pedirNumero ("ingrese el precio de aerolineas");
			z = pedirNumero ("ingrese el precio de latam");
		break;
		case 3:
			if (x == 0 || z == 0 || y == 0)
			{
				printf("no se han cargado todos los datos, porfavor reingresar \n");
				system("pause");
			}
			else
			{
				tarjetaDeDebitoZ= tarjetaDebitoCalcular (z);
				tarjetaDeCreditoZ= tarjetaCreditoCalcular (z);
				bitcoinCostoZ = bitcoinCalcular (z);
				precioUnitarioZ = precioUnitarioCalcular (z,x);

				tarjetaDeDebitoY= tarjetaDebitoCalcular (y);
				tarjetaDeCreditoY= tarjetaCreditoCalcular (y);
				bitcoinCostoY = bitcoinCalcular (y);
				precioUnitarioY = precioUnitarioCalcular (y,x);

				diferenciaPrecio= diferenciaPrecioTotal (y,z);
			}
		break;
		case 4:
			if (x == 0 || z == 0 )
			{
					printf("no se han cargado todos los datos, porfavor reingresar \n");
					system("pause");
			}
			else
			{
				printf("los precios de latam son \n");
				printf("el valor de debito es %f  \n", tarjetaDeDebitoZ);
				printf("el valor de credito es %f  \n", tarjetaDeCreditoZ);
				printf("el valor de bitcoin es %f  \n", bitcoinCostoZ);
				printf("el valor unitario es %f  \n", precioUnitarioZ);
			}
			if(x == 0 || y == 0)
			{
				printf("no se han cargado todos los datos, porfavor reingresar \n");
				system("pause");
			}
			else
			{
				printf("los precios de Aerolinea son \n");
				printf("el valor de debito es %f  \n", tarjetaDeDebitoY);
				printf("el valor de credito es %f  \n", tarjetaDeCreditoY);
				printf("el valor de bitcoin es %f  \n", bitcoinCostoY);
				printf("el valor unitario es %f  \n", precioUnitarioY);

			}
			printf("la diferencia de precio entre aerolinea y latam es %f \n ", diferenciaPrecio);
		break;
		case 5:
			cargaForzada5();
		break;
		case 6:
			printf("Gracias por usar mi programa, esta saliendo del programa");
		break;
		default:
			printf("No es una respuesta valida");
			system("pause");
		break;


		}
	}while(opcion != 6);
	return 0;


}






