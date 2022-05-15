#include "ArrayPassenger.h"
#define LLENO 0
#define VACIO 1
//boolean = true,false
//en c boolean = true = 1, false = 0

//////////////////////////////////////////////////////////////////

int InitPassenger(Passenger list[], int len)
{
	for (int i = 0; i<len; i++)
	{
		list[i].isEmpty = VACIO;
		list[i].statusFlight = VACIO;
	}
	return 0;

}

//////////////////////////////////////////////////////////////////

int AddPassenger(Passenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[])
{
	Passenger p;

	for(int i = 0; i<10; i++)
	{
		p.flycode[i] = flyCode[i];
	}

	for(int i = 0; i<10; i++)
	{
		p.name[i] = name[i];
	}
	for(int i = 0; i<10; i++)
	{
		p.lastName[i] = lastName[i];
	}

		p.id = id;
		p.price = price;
		p.typePassenger = typePassenger;
		p.isEmpty = LLENO;

	int flag = 1;
	int pos;
	int i = 0;
	int response = 0;
	while(flag == 1)
	{
		if(list[i].isEmpty == VACIO)
		{
			pos = i;
			flag = 0;
			response = 1;
		}
		i++;
	}
	list[pos] = p;


	return response;
}

//////////////////////////////////////////////
int updatePassenger(Passenger list[],int len, int id,char name[],char lastName[],float price,int typePassenger,char flyCode[]){

	Passenger p;

		for(int i = 0; i<10; i++)
		{
			p.flycode[i] = flyCode[i];
		}

		for(int i = 0; i<10; i++)
		{
			p.name[i] = name[i];
		}
		for(int i = 0; i<10; i++)
		{
			p.lastName[i] = lastName[i];
		}

			p.id = id;
			p.price = price;
			p.typePassenger = typePassenger;
			p.isEmpty = LLENO;

		int flag = 1;
		int pos;
		int i = 0;
		int response = 0;

		while(flag == 1)
		{
			if(list[i].id == id)
			{
				pos = i;
				flag = 0;
				response = 1;
			}
			i++;
		}
		list[pos] = p;


		return response;

}


///////////////////////////////////////////////////////////////////

int RemovePassenger(Passenger list[], int len, int id)
{
	int response = 0;
	for(int i = 0; i<len ; i++)
	{
		if(list[i].id == id)
		{
			list[i].isEmpty = VACIO;
			response = 1;
			break;
		}

	}

	return response;
}

////////////////////////////////////////////////////////////////////

int SortPassengers(Passenger list[],int len, int order)
{
	int retorno =1;
	Passenger aux;

	retorno = order;

if(order == 1)
{
	for(int i = 0; i < len-1; i++)
				{
					for(int j = i+1; j<len; j++)
					{
						if(strcmp(list[i].lastName,list[j].lastName)<0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
}
else if(order == 0)
{


		for(int i = 0; i < len-1; i++)
			{
				for(int j = i+1; j<len; j++)
				{
					if(strcmp(list[i].lastName,list[j].lastName) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					else if(strcmp(list[i].lastName, list[j].lastName) == 0)
											{


									if(list[i].typePassenger > list[j].typePassenger)
										{
										aux = list[i];
										list[i] = list[j];
										list[j] = aux;
										}
									else if(list[i].typePassenger < list[j].typePassenger)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
											}

				}
			}

}
else
{
	retorno = -1;
}




	return retorno;
}

///////////////////////////////////////////////////////////////////////

int PrintPassenger(Passenger list[], int length)
{
	for(int i = 0; i<length; i++)
	{
		if(list[i].isEmpty == 0)
		{
			printf(" --------------------------------------- \n");
				printf("ID: %i \n", list[i].id);
				printf("Nombre: %s \n", list[i].name);
				printf("Apellido: %s \n", list[i].lastName);
				printf("Precio: %.2f \n", list[i].price);
				printf("Codigo de vuelvo: %s \n", list[i].flycode);
				printf("Tipo de pasajero: %i \n", list[i].typePassenger);
				printf("\n");
		}

	}
	return 0;
}
///////////////////////////////////////////////////////////////////////

int SortPassengersByCode(Passenger list[], int len, int order)
{
	int retorno =1;
		Passenger aux;

		retorno = order;

	if(order == 1)
	{
		for(int i = 0; i < len-1; i++)
		{
			for(int j = i+1; j<len; j++)
			{
				if(list[i].statusFlight < list[j].statusFlight)
				{
					aux = list[i];
					list[i] = list[j];
					list[j] = aux;
				}
				if(list[i].statusFlight == list[j].statusFlight)
				{

					if(strcmp(list[i].flycode,list[j].flycode)<0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;

					}
					else {
						if(strcmp(list[i].flycode,list[j].flycode) > 0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
	}
	else if(order == 0)
	{


			for(int i = 0; i < len-1; i++)
			{
				for(int j = i+1; j<len; j++)
				{
					if(list[i].statusFlight > list[j].statusFlight)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					if(list[i].statusFlight == list[j].statusFlight)
					{


						if(strcmp(list[i].flycode,list[j].flycode)<0)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;

						}
						else {
							if(strcmp(list[i].flycode,list[j].flycode) > 0)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
					}
				}

	}
	else
	{
		retorno = 0;
	}
	return retorno;

}

///////////////////////////////////////////////////////////////////////

void cargaForzada (Passenger listaDePasajeros[], int tam)

{

    int id[] = {1000,1001,1002,1003};
    char name[][51]={"Arturo","Matias","Ignacio","Olivia"};
    char lastName[][51]= {"Guzman","Heisenberg","Guzman","Biscuit"};
    float price[]={50000,25000,600,30000};
    char flycode[][10]={"X5RY1","48WEC5","A54XZ","D6C4W"};
    int typePassenger[]={1,2,1,2};
    int statusFlight[]={1,3,2,1};
    int estado[]={0,0,0,0};

    for(int i=0;i<tam;i++)
    {
        listaDePasajeros[i].id=id[i];
        strcpy(listaDePasajeros[i].name,name[i]);
        strcpy(listaDePasajeros[i].lastName,lastName[i]);
        listaDePasajeros[i].price=price[i];
        strcpy(listaDePasajeros[i].flycode,flycode[i]);
        listaDePasajeros[i].typePassenger=typePassenger[i];
        listaDePasajeros[i].statusFlight=statusFlight[i];
        listaDePasajeros[i].isEmpty=estado[i];
    }

    printf("se cargo exitosamente\n");
    system("pause");

}











