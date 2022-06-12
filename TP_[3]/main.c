#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
	int opcion;
	int banderaTexto=0;
	int banderaBinario=0;
	int retorno;
	int id = 1000;
	LinkedList* listaPasajeros = ll_newLinkedList();

	do
	{
		printf("\nOpcion 1= Carga de datos de pasajero (modo texto)");
		printf("\nOpcion 2= Carga de datos de pasajero (modo binario)");
		printf("\nOpcion 3= Alta de pasajero");
		printf("\nOpcion 4= Modificar pasajero");
		printf("\nOpcion 5= Dar baja de pasajero");
		printf("\nOpcion 6= Listar pasajeros");
		printf("\nOpcion 7= Ordenar pasajeros");
		printf("\nOpcion 8= Guardar datos de pasajero (modo texto)");
		printf("\nOpcion 9= Guardar datos de pasajero (modo binario)");
		printf("\nOpcion 10= salir\n\n");
		printf("Ingrese la opcion;");
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			printf("caso 1");
				if(banderaTexto == 0)
				{
					printf("entro if");
					retorno= controller_loadFromText("data.csv",listaPasajeros);
					if(retorno == 1)
					{
						printf("\nLos datos han sido cargados exitosamente\n");
						banderaTexto = 1;
					}
					else
					{
						printf("\nhubo un error al cargar los datos\n");
					}
				}
				else
				{
					printf("\nLos datos ya habian sido cargados anteriormente\n");
				}
		break;
		case 2:
			if(banderaBinario == 0)
			{
				retorno= controller_loadFromBinary("data.bin",listaPasajeros);
				if(retorno == 1)
				{
					printf("\nLos datos han sido cargados exitosamente\n");
					banderaBinario = 1;
				}
				else
				{
					printf("\nhubo un error al cargar los datos\n");
				}
			}
			else
			{
				printf("\nLos datos ya habian sido cargados anteriormente\n");
			}
		break;
		case 3:
			retorno = controller_addPassenger(listaPasajeros, &id);
			if(retorno == 1)
			{
				controller_saveAsText("data.csv",listaPasajeros);
			}
			else
			{
				printf("\nhubo un error al hacer la alta del pasajero\n");
			}
		break;
		case 4:
			controller_editPassenger(listaPasajeros);
		break;
		case 5:
			controller_removePassenger(listaPasajeros);
		break;
		case 6:
			if(banderaTexto == 1 || banderaBinario == 1)
			{
				controller_ListPassenger(listaPasajeros);
				printf("Los datos han sido cargados exitosamente");
			}
			else
			{
				printf("\nNo se han cargado los datos aun, porfavor, intente cargarlos\n");
				system("pause");
			}
		break;
		case 7:
			controller_sortPassenger(listaPasajeros);
		break;
		case 8:
			retorno = controller_saveAsText("data.csv",listaPasajeros);
			if(retorno == 1)
			{
				printf("los datos en texto han sido guardados exitosamente");
			}
			else
			{
				printf("\nhubo un error al guardar los datos\n");
			}
		break;
		case 9:
			controller_saveAsBinary("data.bin",listaPasajeros);
			if(retorno == 1)
			{
				printf("los datos en binario han sido guardados exitosamente");
			}
			else
			{
				printf("\nhubo un error al guardar los datos\n");
			}
		break;
		case 10:
			printf("\nGracias por usar mi programa, esta saliendo del programa.\n");
		break;
		default:
			printf("\nNo es una respuesta valida\n");
			system("pause");
		break;

		}


	}while(opcion != 10);
	return 0;
}
