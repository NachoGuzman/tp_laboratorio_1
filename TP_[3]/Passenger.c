#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "input.h"


Passenger* Passenger_new()
{
	Passenger* indice= (Passenger*) malloc(sizeof(Passenger)*1);
	if(indice != NULL)
	{
		indice->id = 0;
		indice->precio =0;
		strcpy(indice->nombre,"");
		strcpy(indice->apellido,"");
		strcpy(indice->codigoVuelo,"");
		strcpy(indice->tipoPasajero,"");
		strcpy(indice->estadoVuelo, "");
	}
	return indice;
}
Passenger* Passenger_newParametros(char* id,char* nombre,char* apellido, char* precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo)
{
 Passenger* pasajero = NULL;
 pasajero = Passenger_new();
 if(pasajero != NULL)
 {
	 Passenger_setId(pasajero,atoi(id));
	 Passenger_setNombre(pasajero,nombre);
	 Passenger_setApellido(pasajero,apellido);
	 Passenger_setCodigoVuelo(pasajero,codigoVuelo);
	 Passenger_setTipoPasajero(pasajero,tipoPasajero);
	 Passenger_setEstadoVuelo(pasajero,estadoVuelo);
	 Passenger_setPrecio(pasajero,atof(precio));

 }
 return pasajero;
}
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = 0;
	if(this != NULL)
	{
		this->id =id;
		retorno = 1;
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = 0;
	if(this!= NULL)
	{
		strcpy(this->nombre, nombre);
		retorno=1;
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = 0;
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = 0;
	if(this != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno=1;
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno=1;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;
	if(this != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno= 1;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno= 1;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;
	if(this != NULL)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = 0;
	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
 int retorno= 0;
 if(this != NULL)
 {
	 this->precio=precio;
	 retorno = 1;
 }
 return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = 0;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}
int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int retorno = 0;
	if(this != NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		retorno = 1;
	}
	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int retorno = 0;
	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		retorno = 1;
	}
	return retorno;
}

void Passenger_print(Passenger* pasajero)
{
    int auxiliarID;
    char auxiliarNombre[128];
    char auxiliarApellido[128];
    float auxiliarPrecio;
    char auxiliarTipoPasajero[128];
    char auxiliarCodigoVuelo[128];
    char auxiliarEstadoVuelo[128];

    if(pasajero!=NULL)
    {
        if(allGets(pasajero,&auxiliarID,auxiliarNombre,auxiliarApellido,auxiliarCodigoVuelo,&auxiliarPrecio,auxiliarTipoPasajero,auxiliarEstadoVuelo) == 1)
        {
            printf("%-5d %-15s %-15s %-13.2f %-16s %-16s %-16s\n" ,auxiliarID
                                                                ,auxiliarNombre
                                                                ,auxiliarApellido
                                                                ,auxiliarPrecio
                                                                ,auxiliarCodigoVuelo
                                                                ,auxiliarTipoPasajero
                                                                ,auxiliarEstadoVuelo);
        }else
        {
            printf("Error para mostrar el Pasajero");
        }
    }
}

int addPassenger ( int id, char *nombre, char *apellido, float precio, char *codigoVuelo, char* tipoPasajero, char *estadoVuelo,LinkedList* pArrayListPassenger)
{
	Passenger* pasajero;
	pasajero = Passenger_new();
	int retorno;
	int retornoDos=0;

	Passenger_setId(pasajero,id);
	Passenger_setNombre(pasajero, nombre);
	Passenger_setApellido(pasajero, apellido);
	Passenger_setPrecio(pasajero, precio);
	Passenger_setCodigoVuelo(pasajero, codigoVuelo);
	Passenger_setTipoPasajero(pasajero, tipoPasajero);
	Passenger_setEstadoVuelo(pasajero, estadoVuelo);

	printf("Porfavor, rellene los campos necesarios");
	printf("Confirma los datos de envio?\n"
			 	 	 "1-Si\n"
					 "2-No\n");
	scanf("%d",&retorno);
	if(retorno==1)
	{
		ll_add(pArrayListPassenger,pasajero);
		retornoDos=1;
	}
	else
	{
		Passenger_delete(pasajero);
	}
	return retornoDos;
}

int allGets(Passenger* unPasajero, int* id, char* nombre, char* apellido, char* codigoVuelo, float* precio, char* tipoPasajero, char* estadoVuelo)
{
    int retorno = 0;

    if(unPasajero != NULL && id != NULL && nombre != NULL && apellido != NULL && tipoPasajero != NULL && precio != NULL && codigoVuelo != NULL && estadoVuelo != NULL)
    {
        if(Passenger_getId(unPasajero, id) == 1 &&
		   Passenger_getNombre(unPasajero, nombre) == 1 &&
		   Passenger_getApellido(unPasajero, apellido) == 1 &&
		   Passenger_getTipoPasajero(unPasajero, tipoPasajero) == 1 &&
		   Passenger_getPrecio(unPasajero, precio) == 1 &&
		   Passenger_getCodigoVuelo(unPasajero, codigoVuelo) == 1 &&
		   Passenger_getEstadoVuelo(unPasajero, estadoVuelo) == 1)
		{
			retorno = 1;
		}
    }

    return retorno;
}

void Passenger_casoNombre(LinkedList* linkClon)
{
    int orden;

    utn_getInt(&orden,  "0) Orden ASCENDENTE\n"
						"1) Orden DESCENDENTE\n"
						"Ingrese opcion: \n",
						"0) Orden ASCENDENTE\n"
						"1) Orden DESCENDENTE\n"
						"ERROR opcion invalida, reingrese: \n",0,1,3);

    if(!ll_sort(linkClon,Passenger_compararApellido,orden))
    {
        if(orden == 1)
        {
            printf("Se ha ordenado la lista por nombre de A-Z");
        }else
        {
            printf("Se ha ordenado la lista por nombre de Z-A");
        }
    }
}

int Passenger_compararNombre(void* pasajero1, void* pasajero2)
{
    int resultado = -1;
    char nombre1[128];
    char nombre2[128];
    Passenger* pAux1 = NULL;
    Passenger* pAux2 = NULL;

    if(pasajero1!=NULL && pasajero2!=NULL)
    {
    	pAux1 = (Passenger*) pasajero1;
    	pAux2 = (Passenger*) pasajero2;

        if((!Passenger_getNombre(pAux1,nombre1)) && (!Passenger_getNombre(pAux2,nombre2)))
        {
            resultado = strcmp(nombre1,nombre2);
        }
    }

    return resultado;
}

void Passenger_casoApellido(LinkedList* linkClon)
{
    int orden;

    utn_getInt(&orden,  "0) Orden ASCENDENTE\n"
						"1) Orden DESCENDENTE\n"
						"Ingrese opcion: \n",
						"0) Orden ASCENDENTE\n"
						"1) Orden DESCENDENTE\n"
						"ERROR opcion invalida, reingrese: \n",0,1,3);

    if(!ll_sort(linkClon,Passenger_compararApellido,orden))
    {
        if(orden == 1)
        {
            printf("Se ha ordenado la lista por nombre de A-Z");
        }else
        {
            printf("Se ha ordenado la lista por nombre de Z-A");
        }
    }
}

int Passenger_compararApellido(void* pasajero1, void* pasajero2)
{
    int resultado = -1;
    char apellido1[128];
    char apellido2[128];
    Passenger* pAux1 = NULL;
    Passenger* pAux2 = NULL;

    if(pasajero1!=NULL && pasajero2!=NULL)
    {
    	pAux1 = (Passenger*) pasajero1;
    	pAux2 = (Passenger*) pasajero2;

        if((!Passenger_getApellido(pAux1,apellido1)) && (!Passenger_getApellido(pAux2,apellido2)))
        {
            resultado = strcmp(apellido1,apellido2);
        }
    }

    return resultado;
}
