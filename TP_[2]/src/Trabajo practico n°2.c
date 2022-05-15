
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"

#define tam 2000


int main(void) {

	int inicializar;
	int opcion;
	int id = 0;
	setbuf(stdout, NULL);
	int cant = 0;
	Passenger pasajeros[tam];
	int respuesta;

	inicializar = InitPassenger(pasajeros, tam);

	do
		{
			printf("\nOpcion 1 = Ingrese pasajero nuevo");
			printf("\nOpcion 2 = Modificar pasajero"); //PEDIR EL ID Y LLAMAR A LA FUNCION
			printf("\nOpcion 3 = Dar de baja un pasajero"); // PEDIR EL ID Y LLAMAR A LA FUNCION
			printf("\nopcion 4 = Informar"); //LLAMAR A TODOS LOS METODOS DE ORDENAMIENTO SOLICITADOS E IMPRIMIR LOS ARREGLOS
			printf("\nOpcion 5 = Carga forzada");
			printf("\nOpcion 6 = Salir \n\n");
			scanf("%d" , &opcion);

			switch (opcion)
			{
			case 1:


				id++;
				printf("\nIngrese el nombre del pasajero");
				char nombre[51];
				scanf("%s", &nombre[51]);

				printf("\nIngrese el apellido del pasajero");
				char apellido[51];
				scanf("%s", &apellido[51]);

				printf("\nIngrese el precio de su pasaje");
				float precio;
				scanf("%f", &precio);

				printf("\nIngrese el tipo de pasajero");
				int passengerType;
				scanf("%d",&passengerType);

				printf("\ningrese su codigo de vuelo");
				char flyCode[10];
				scanf("%s",&flyCode[10]);
				cant++;
				int x = AddPassenger(pasajeros, cant, id, nombre, apellido, precio, passengerType, flyCode);
				if(x == 1)
				{
					printf("\nUSUARIO AGREGADO CORRECTAMENTE\n\n");
				}
				else
				{
					printf("\nERROR\n");
				}

			break;
			case 2:
				id++;
				printf("\nIngrese el nombre del pasajero");

				scanf("%s", &nombre[51]);

				printf("\nIngrese el apellido del pasajero");

				scanf("%s", &apellido[51]);

				printf("\nIngrese el precio de su pasaje");

				scanf("%f", &precio);

				printf("\nIngrese el tipo de pasajero");

				scanf("%d",&passengerType);

				printf("\ningrese su codigo de vuelo");

				scanf("%s",&flyCode[10]);
				cant++;
				x = updatePassenger(pasajeros, cant, id, nombre, apellido, precio, passengerType, flyCode);
				if(x == 1)
				{
					printf("\nUSUARIO CAMBIADO CORRECTAMENTE\n\n");
				}
				else
				{
					printf("\nERROR\n");
				}


			break;
			case 3:
					printf("\nIngrese su Id porfavor");
					scanf("%d",&id);
					int z = RemovePassenger(pasajeros, cant, id);
					if(z == 1)
					{
						RemovePassenger(pasajeros, cant, id);
						printf("\nPasajero removido correctamente");
					}
					else
					{
						printf("\nError, vuelva a intentar");
					}
			break;
			case 4:
					printf("\nOpcion 1= ordenar apellidos y tipo de pasajero");
					printf("\nOpcion 2= ordenar por codigo de vuelo y estado de vuelo");
					scanf("%i",&respuesta);
					switch(respuesta)
					{
					case 1:
					printf("\nopcion 1= ordenar de manera descendente");
					printf("\nopcion 2= ordenar de manera ascendente");
					int orden;
					scanf("%i",&orden);
					if(orden == 1)
					{
						SortPassengers(pasajeros, cant, 1);
						PrintPassenger(pasajeros, cant);
					}
					else
					{
						if(orden == 2)
						{
							SortPassengers(pasajeros, cant, 0);
							PrintPassenger(pasajeros, cant);
						}
						else
						{
							printf("\nError, ingrese un numero valido");
						}
					}
					break;
					case 2:
						printf("\nopcion 1= ordenar de manera ascendente");
						printf("\nopcion 2= ordenar de manera descendete");
						scanf("%i",&orden);
						if(orden == 1)
						{
							SortPassengersByCode(pasajeros, cant, 1);
							PrintPassenger(pasajeros, cant);
						}
						else
						{
							if(orden == 2)
							{
								SortPassengersByCode(pasajeros, cant, 0);
								PrintPassenger(pasajeros, cant);
							}
							else
							{
								printf("\nError, ingrese un numero valido");
							}
						}
					break;



			break;
					}
			break;
			case 5:
				cant = 4;
				cargaForzada(pasajeros, cant);


			break;
			case 6:
				printf("\nGracias por usar mi programa, esta saliendo del programa.");
			break;
			default:
				printf("\nNo es una respuesta valida\n\n");
				system("pause");
			break;

			}
		}while(opcion != 6);



	return EXIT_SUCCESS;
}

