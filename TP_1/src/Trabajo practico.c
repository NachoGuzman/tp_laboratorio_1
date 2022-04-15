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

	setbuf(stdout, NULL);

	do
	{
		printf("\nOpcion 1 = Ingrese los kilometros");
		printf("\nOpcion 2 = Ingresar el coste del viaje");
		printf("\nOpcion 3 = Calculo de los costos");
		printf("\nopcion 4 = Informe de resultados");
		printf("\nOpcion 5 = Carga forzada de datos");
		printf("\nOpcion 6 = Salir \n\n");
		scanf("%d" , &opcion);

		switch (opcion)
		{
		case 1:
			x = pedirNumero ("\nIngrese los kilometros\n\n");
		break;
		case 2:
			y = pedirNumero ("\nIngrese el precio de aerolineas\n\n");
			z = pedirNumero ("\nIngrese el precio de latam\n\n");
		break;
		case 3:
			if (x < 1 || z < 1 || y < 1)
			{
				printf("No se han cargado todos los datos, porfavor reingresar \n");
				system("pause");
			}
			else
			{
				printf("\nLos datos han sido cargados, los calculos ya se han realizado\n");

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
			if (x < 1 || z < 1 || y < 1)
			{
					printf("No se han cargado todos los datos, porfavor reingresar \n");
					system("pause");
			}
			else
			{
				printf("Los precios de latam son: \n");
				printf("El valor de debito es %f  \n", tarjetaDeDebitoZ);
				printf("El valor de credito es %f  \n", tarjetaDeCreditoZ);
				printf("El valor de bitcoin es %f  \n", bitcoinCostoZ);
				printf("El valor unitario es %f  \n\n", precioUnitarioZ);

				printf("los precios de Aerolinea son: \n");
				printf("el valor de debito es %f  \n", tarjetaDeDebitoY);
				printf("el valor de credito es %f  \n", tarjetaDeCreditoY);
				printf("el valor de bitcoin es %f  \n", bitcoinCostoY);
				printf("el valor unitario es %f  \n", precioUnitarioY);

				printf("\nla diferencia de precio entre aerolinea y latam es %f \n ", diferenciaPrecio);
			}
		break;
		case 5:
			cargaForzada5();
		break;
		case 6:
			printf("\nGracias por usar mi programa, esta saliendo del programa.");
		break;
		default:
			printf("No es una respuesta valida\n\n");
			system("pause");
		break;


		}
	}while(opcion != 6);
	return 0;


}






