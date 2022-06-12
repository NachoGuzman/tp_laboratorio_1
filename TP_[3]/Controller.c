#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "input.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	FILE* pArchivo;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			parser_PassengerFromText(pArchivo, pArrayListPassenger);
			retorno=1;

		}
		else
		{
			printf("No se ha podido validar el archivo");
		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	FILE*pArchivo;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "rb");
		if(pArchivo != NULL)
		{
			parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
			retorno=1;
		}
		else
		{
			printf("No se ha podido validar el archivo");
		}
		fclose(pArchivo);
	}

    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* id)
{
	int idAuxiliar;
	int retorno = 0;
	char nombre[128];
	char apellido[128];
	float precio;
	char tipoPasajero[128];
	char codigoVuelo[128];
	char estadoVuelo[128];
	Passenger*auxPasajero = NULL;

	if(pArrayListPassenger!=NULL && id!= NULL)
	{
		auxPasajero=Passenger_new();

		if(auxPasajero!=NULL)
		{
			idAuxiliar=*id;
			idAuxiliar+=1;

			printf("tu numero de ID seria:%d", idAuxiliar);
			if(!(utn_getString(nombre, "Ingrese el nombre", "Error, reingresar",128,3))&&
				!(utn_getString(apellido,"Ingrese el apellido","Error, reingresar",128,3))&&
				!(utn_getString(tipoPasajero,"Ingrese el tipo de pasajero","Error, reingresar",128,3))&&
				!(utn_getString(estadoVuelo,"Ingrese su estado de vuelo", "Error, reingresar",128,3))&&
				!(utn_getFloat(&precio, "Ingrese el precio de su vuelo","Error, reingresar",1,10000000,3))&&
				!(utn_getChar(codigoVuelo,"Ingrese el codigo de su vuelo","Error, reingresar",128,3)))
			{
				addPassenger(idAuxiliar,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo,pArrayListPassenger);
				retorno = 1;
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int confirmacion = 0;
	int id;
	int index;
	int len;
	int opcion;
	char auxNombre[128];
	char auxApellido[128];
	float auxprecio;
	char auxCodigoVuelo[128];
	char auxTipoPasajero[128];
	Passenger* pasajero;
	//Passenger auxPasajero;

	if(pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);
		controller_ListPassenger(pArrayListPassenger);
		utn_getInt(&id, "Ingrese ID a modificar: \n", "ERROR ID no encontrado, reingrese: \n",1,len,3);
		for(int i = 0;i<len;i++)
		{
			pasajero = (Passenger*) ll_get(pArrayListPassenger,i);
			if(id == pasajero->id)
			{
				index = i;
				break;
			}
		}
		if(index!=-1)
		{
			Passenger_print(pasajero);
			do
			{
				utn_getInt(&opcion, "1) Modificar Nombre\n"
									"2) Modificar Apellido\n"
									"3) Modificar Precio\n"
									"4) Modificar Tipo de pasajero\n"
									"5) Modificar Codigo de vuelo\n"
									"6) Salir\n"
									"Ingrese opcion: \n",
									"1) Modificar Nombre\n"
									"2) Modificar Apellido\n"
									"3) Modificar Precio\n"
									"4) Modificar Tipo de pasajero\n"
									"5) Modificar Codigo de vuelo\n"
									"6) Salir\n"
									"ERROR opcion invalida, reingrese: \n",1,6,3);
				switch(opcion)
				{
					case 1:
						utn_getString(auxNombre, "Ingrese el nuevo nombre", "Error, reingresar",128,3);
						strcpy(pasajero->nombre, auxNombre);
						Passenger_print(pasajero);

						printf("Confirma los cambios?\n"
										 "1-Si\n"
										 "2-No\n");
						scanf("%d",&confirmacion);
						if(confirmacion==1)
						{
							Passenger_setNombre(pasajero,auxNombre);
							retorno=1;
						}else
						{
							printf("No se modifico el nombre\n");
						}
					break;
					case 2:
						utn_getString(auxApellido, "Ingrese el nuevo apellido", "Error, reingresar",128,3);
						strcpy(pasajero->apellido, auxApellido);
						Passenger_print(pasajero);

						printf("Confirma los cambios?\n"
										 "1-Si\n"
										 "2-No\n");
						scanf("%d",&confirmacion);
						if(confirmacion==1)
						{
							Passenger_setApellido(pasajero,auxApellido);
							retorno=1;
						}else
						{
							printf("No se modifico el apellido\n");
						}
					break;
					case 3:
						utn_getFloat(&auxprecio, "Ingrese el nuevo precio", "Error, reingresar",1,1000000,3);
						pasajero->precio = auxprecio;
						Passenger_print(pasajero);

						printf("Confirma los cambios?\n"
										 "1-Si\n"
										 "2-No\n");
						scanf("%d",&confirmacion);
						if(confirmacion==1)
						{
							Passenger_setPrecio(pasajero,auxprecio);
							retorno=1;
						}else
						{
							printf("No se modifico el precio\n");
						}
					break;
					case 4:
						utn_getString(auxTipoPasajero, "Ingrese el nuevo tipo de pasajero", "Error, reingresar",128,3);
						strcpy(pasajero->tipoPasajero, auxTipoPasajero);
						Passenger_print(pasajero);

						printf("Confirma los cambios?\n"
										 "1-Si\n"
										 "2-No\n");
						scanf("%d",&confirmacion);
						if(confirmacion==1)
						{
							Passenger_setTipoPasajero(pasajero,auxTipoPasajero);
							retorno=1;
						}else
						{
							printf("No se modifico el apellido\n");
						}
					break;
					case 5:
						utn_getChar(auxCodigoVuelo, "Ingrese el nuevo codigo de vuelo", "Error, reingresar",128,3);
						strcpy(pasajero->codigoVuelo, auxCodigoVuelo);
						Passenger_print(pasajero);

						printf("Confirma los cambios?\n"
										 "1-Si\n"
										 "2-No\n");
						scanf("%d",&confirmacion);
						if(confirmacion==1)
						{
							Passenger_setCodigoVuelo(pasajero,auxCodigoVuelo);
							retorno=1;
						}else
						{
							printf("No se modifico el apellido\n");
						}
					break;
					case 6:
						printf("Saliendo de la modificacion...");
					break;
				}
			}while(opcion!=6);
		}else
		{
			printf("No se encontro el pasajero");
		}
	}

    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int opcion;
	int index = -1;
	int len;
    Passenger* Aux;
	if(pArrayListPassenger!=NULL)
		{
		len = ll_len(pArrayListPassenger);
		controller_ListPassenger(pArrayListPassenger);
		utn_getInt(&opcion,"Ingrese el id a dar de baja porfavor", "Error, reingresar",1,len,3);
		for(int i = 0;i<len;i++)
		{
			Aux = (Passenger*) ll_get(pArrayListPassenger,i);
			if(opcion == Aux->id)
			{
				index = i;
				break;
			}
		}
		if(index != -1)
		{
		printf("Se eliminara:\n");
		Passenger_print(Aux);
		ll_remove(pArrayListPassenger,index);
		}
		else
		{
			printf("No se encontro el pasajero\n");
		}
		retorno = 1;
	}




    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int size;
	size=ll_len(pArrayListPassenger);
	Passenger* nuevoPasajero=NULL;
	    if(pArrayListPassenger != NULL)
	    {
	        printf("===============================================================================================\n");
	        printf("                   				     LISTA DE PASAJERO                                \n");
	        printf("===============================================================================================\n");
	        printf("ID  |    NOMBRE   |   APELLIDO   | PRECIO | COD DE VUELO | TIPO DE PASAJERO | ESTADO DE VUELO |\n");
	        for(int i=0; i<size;i++)
	        {
	        nuevoPasajero = (Passenger*)ll_get(pArrayListPassenger,i);
	        if(nuevoPasajero!=NULL)
	        	{
	        		Passenger_print(nuevoPasajero);
	        	}
	        }
	        retorno = 1;
	    }
	    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int opcion;
	LinkedList* linkClon;

	if(pArrayListPassenger)
	{
		linkClon = ll_clone(pArrayListPassenger);
		if(linkClon!=NULL)
		{
			do
			{
				utn_getInt(&opcion, "1) Ordenar por Nombre\n"
									"2) Ordenar Apellido\n"
									"3) Salir\n"
									"Ingrese opcion: \n",
									"1) Ordenar Nombre\n"
									"2) Ordenar Apellido\n"
									"3) Salir\n"
									"ERROR opcion invalida, reingrese: \n",1,3,3);
				switch(opcion)
				{
					case 1:
						Passenger_casoNombre(linkClon);
						printf("Espere al ordenamiento...");
						controller_ListPassenger(linkClon);
					break;
					case 2:
						Passenger_casoApellido(linkClon);
						printf("Espere al ordenamiento...");
						controller_ListPassenger(linkClon);
					break;
					case 3:
						printf("Saliendo del Ordenamiento...");
						ll_deleteLinkedList(linkClon);
					break;
				}
			}while(opcion!=3);
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int i;
	int longitud;
	int id;
	char nombre[50];
	char apellido[50];
	char tipoPasajero[20];
	char codigoVuelo[10];
	char estadoVuelo[20];
	float precio;
	int precioEntero;
	FILE* pArchivo;
	Passenger* pasajero = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path,"w");
		longitud = ll_len(pArrayListPassenger);
		if(pArchivo != NULL && longitud > 0)
		{
			fprintf(pArchivo,"ID,Nombre,Apellido,Precio,Codigo,Tipo,Estado\n");
			for(i = 0; i<longitud;i++)
			{
				pasajero = (Passenger*) ll_get(pArrayListPassenger,i);
				if(pasajero != NULL)
				{
					if(allGets(pasajero,&id,nombre,apellido,codigoVuelo,&precio,tipoPasajero,estadoVuelo) == 1)
					{
						precioEntero =(int)precio;
						fprintf(pArchivo,"%d,%s,%s,%d,%s,%s,%s\n\n",id,nombre,apellido,precioEntero,codigoVuelo,tipoPasajero,estadoVuelo);
						retorno = 1;
					}
					else
					{
						Passenger_delete(pasajero);
					}
				}
			}
		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int longitud;
	FILE* pFile;
	Passenger* pasajero = NULL;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "wb");
		longitud = ll_len(pArrayListPassenger);
		if(pFile != NULL && longitud > 0)
		{
			for(int i = 0; i<longitud;i++)
			{
				pasajero = (Passenger*) ll_get(pArrayListPassenger,i);
				if(pasajero != NULL)
				{
					fwrite(pasajero,sizeof(Passenger),1,pFile);
					retorno = 1;
				}
			}
		}
		fclose(pFile);
	}
    return retorno;
}

