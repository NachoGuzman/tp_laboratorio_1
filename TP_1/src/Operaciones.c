
#include "Funcion.h"
#include <stdio.h>
#include <stdlib.h>

float pedirNumero (char mensaje[])

{
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;

}
float tarjetaDebitoCalcular (float precioBruto)
{
	float precioFinal;
	precioFinal = precioBruto-(precioBruto*10/100);
	return precioFinal;
}

float tarjetaCreditoCalcular (float precioBruto)
{
	float precioFinal;
	precioFinal = precioBruto + (precioBruto * 25 / 100);
	return precioFinal;
}

float bitcoinCalcular (float precioBruto)
{
	float precioFinal;
	precioFinal = precioBruto / 4606954.55;
	return precioFinal;
}

float precioUnitarioCalcular (float precioBruto, int x)
{
	float precioFinal;
	precioFinal = precioBruto / x;
	return precioFinal;
}

float diferenciaPrecioTotal (float y, float z)
{
	float precioFinal;
	if (y > z)
	{
		precioFinal = y - z;
	}
	else
	{
		precioFinal = z - y;
	}
	return precioFinal;
}

void cargaForzada5 (void)
{
	float tarjetaDeDebitoZ;
	float tarjetaDeCreditoZ;
	float bitcoinCostoZ;
	float precioUnitarioZ;


	float tarjetaDeDebitoY;
	float tarjetaDeCreditoY;
	float bitcoinCostoY;
	float precioUnitarioY;

	float x;
	float y;
	float z;

	float diferenciaPrecio;

	x= 7090;
	y= 162965;
	z= 159339;

	tarjetaDeDebitoZ= tarjetaDebitoCalcular (z);
	tarjetaDeCreditoZ= tarjetaCreditoCalcular (z);
	bitcoinCostoZ = bitcoinCalcular (z);
	precioUnitarioZ = precioUnitarioCalcular (z,x);

	tarjetaDeDebitoY= tarjetaDebitoCalcular (y);
	tarjetaDeCreditoY= tarjetaCreditoCalcular (y);
	bitcoinCostoY = bitcoinCalcular (y);
	precioUnitarioY = precioUnitarioCalcular (y,x);

	diferenciaPrecio= diferenciaPrecioTotal (y,z);


	printf("\nLos precios de Aerolinea son: \n");
	printf("El valor de debito es: %f  \n", tarjetaDeDebitoY);
	printf("El valor de credito es: %f  \n", tarjetaDeCreditoY);
	printf("El valor de bitcoin es: %f  \n", bitcoinCostoY);
	printf("El valor unitario es: %f  \n\n", precioUnitarioY);

	printf("Los precios de Latam son: \n");
	printf("El valor de debito es: %f  \n", tarjetaDeDebitoZ);
	printf("El valor de credito es: %f  \n", tarjetaDeCreditoZ);
	printf("El valor de bitcoin es: %f  \n", bitcoinCostoZ);
	printf("El valor unitario es: %f  \n\n", precioUnitarioZ);

	printf("la diferencia de precio entre aerolinea y latam es: %f \n", diferenciaPrecio);
}
