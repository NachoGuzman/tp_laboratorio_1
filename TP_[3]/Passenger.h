/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[10];
	char estadoVuelo[20];


}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* id,char* nombre,char* apellido, char* precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo);

void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo);

void Passenger_print(Passenger* pasajero);
int allGets(Passenger* unPasajero, int* id, char* nombre, char* apellido, char* codigoVuelo, float* precio, char* tipoPasajero, char* estadoVuelo);
int addPassenger ( int id, char *nombre, char *apellido, float precio, char *codigoVuelo, char* tipoPasajero, char *estadoVuelo,LinkedList* pArrayListPassenger);

void Passenger_casoApellido(LinkedList* linkClon);
void Passenger_casoNombre(LinkedList* linkClon);
int Passenger_compararApellido(void* pasajero1, void* pasajero2);
int Passenger_compararNombre(void* pasajero1, void* pasajero2);


#endif /* PASSENGER_H_ */
