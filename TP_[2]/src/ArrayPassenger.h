/*
 * ArrayPassenger.h
 *
 *  Created on: 12 may. 2022
 *      Author: User
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[10];
int typePassenger;
int statusFlight;
int isEmpty;
}
typedef Passenger;



int InitPassenger(Passenger list[], int len); // Inicializa a todos los pasajeros
int AddPassenger(Passenger list[],int len,int id,char name[],char lastName[],float price,int typePassenger,char flyCode[]); //Se utiliza para agregar a los pasajeros a la lista
int updatePassenger(Passenger list[],int len,int id,char name[],char lastName[],float price,int typePassenger,char flyCode[]); //Se utiliza para cambiar alguno de los datos dados por quien usa la aplicacion
int RemovePassenger(Passenger list[], int len, int id);//se utiliza para remover a un pasajero dando su ID
int SortPassengers(Passenger list[],int len, int order);//ordena a los pasajeros por apellido y tipo de pasajero
int PrintPassenger(Passenger list[], int length);//muestra la lista de pasajeros
int SortPassengerByCode(Passenger list[], int len, int order);//muestra a los pasajeros por su codigo y su estado de vuelo
void cargaForzada (Passenger listaDePasajeros[], int tam);//ingresa automaticamente datos estandar de 4 pasajeros para poder probar de manera rapida la aplicacion


#endif /* ARRAYPASSENGER_H_ */
