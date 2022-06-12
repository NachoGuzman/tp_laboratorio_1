#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	char id[128];
	char nombre[128];
	char apellido[128];
	char precio[128];
	char tipoPasajero[128];
	char codigoVuelo[128];
	char estadoVuelo[128];
	int validacion;
	Passenger* unPasajero= NULL;


	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);

		while(!feof(pFile))
			{
				validacion=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
				if(validacion == 7)
				{
					unPasajero=Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
					if(unPasajero!=NULL)
					{
						ll_add(pArrayListPassenger,unPasajero);
						retorno = 0;
					}

				}
			}
	}


    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger*unPasajero= NULL;
    int retorno = 0;

    if(pFile != NULL && pArrayListPassenger != NULL)
    {
    	while(!feof(pFile))
    	{
    		unPasajero = Passenger_new();
    		if(unPasajero != NULL)
    		{
    			if(fread(unPasajero, sizeof(Passenger),1,pFile)!=0)
    			{
    				ll_add(pArrayListPassenger, unPasajero);
    				retorno= 1;
    			}
    		}
    	}
    }
    return retorno;
}
