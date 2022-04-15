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

int main(void)
{
	setbuf(stdout, NULL);

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

	do
	{
		printf("Opcion 1 = Ingrese los kilometros \n");
		printf("Opcion 2 = Ingresar el coste del viaje \n");
		printf("Opcion 3 = Calculo de los costos \n");
		printf("opcion 4 = Informe de resultados \n");
		printf("Opcion 5 = Carga forzada de datos \n");
		printf("Opcion 6 = Salir \n\n");
		scanf("%d" , &opcion);

		switch (opcion)
		{
		case 1:
			x = pedirNumero ("\nIngrese los kilometros\n");
		break;
		case 2:
			y = pedirNumero ("Ingrese el precio de aerolineas");
			z = pedirNumero ("Ingrese el precio de latam");
		break;
		case 3:
			if (x == 0 || z == 0 || y == 0)
			{
				printf("No se han cargado todos los datos, porfavor reingresar \n");
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
					printf("No se han cargado todos los datos, porfavor reingresar \n");
					system("pause");
			}
			else
			{
				printf("Los precios de latam son \n");
				printf("El valor de debito es %f  \n", tarjetaDeDebitoZ);
				printf("El valor de credito es %f  \n", tarjetaDeCreditoZ);
				printf("El valor de bitcoin es %f  \n", bitcoinCostoZ);
				printf("El valor unitario es %f  \n", precioUnitarioZ);
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






