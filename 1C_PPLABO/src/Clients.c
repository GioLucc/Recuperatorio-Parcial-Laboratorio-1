/*
 * Employees.c
 *
 *  Created on: 19 oct. 2021
 *      Author: giova
 */

#include "Clients.h"
#include "Nexus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int initClients (eClients* clientList, int len) ///
{
	int state = -1;

	if(clientList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			clientList[i].isEmpty = EMPTY;
		}
	}
	return state;
}

int freeClientSpot (eClients* clientList, int len) ///
{
	int position;

	position = -1;

	if(clientList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(clientList[i].isEmpty == EMPTY)
			{
				position = i; ///
				break;
			}
		}
	}

	return position;
}

int newClient (eClients* clientList, sLocality* localitiesList, int len, int* uniqueID, int* uniqueLocalityID) //
{
	int state;
	eClients newClient;
	char auxLocality[MAX];
	int auxIdlocality;

	state = -1;
	*uniqueID = *uniqueID+1;

	if(clientList != NULL && localitiesList != NULL && len > 0)
	{
		getStringVerificado("\n\t\t\t\t\t\t\tIngrese el nombre de su compañia :) : ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese el nombre de su compañia) - ERROR : \n", newClient.companyName);
		getStringVerificado("\n\t\t\t\t\t\t       Ingrese el cuit de su compañia :) : ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese el cuit de su compañia) - ERROR : \n", newClient.cuit);
		askForAdress("\n\t\t\t\t\t\t    Ingrese la direccion de su compañia :) : ", newClient.adress);
		LOC_printListOfLocalities(localitiesList, MAX);
		getValidLocality("\n\t\t\t\t\t\t\tIngrese la localidad de su compañia :) : ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese la localidad de su compañia) - ERROR : \n",
		auxLocality);

		FormartearCadena(auxLocality);

		auxIdlocality = LOC_search(localitiesList, MAX, auxLocality, uniqueLocalityID);

		if(auxIdlocality != 0)
		{
			newClient.localityId = auxIdlocality;
			printf("\n\n\t\t\t\t\t\t Localidad asignada correctamente");
		}
		else
		{
			printf("\n\n\t\t\t\t\t\tNo existe esa localidad vuelva al menu y creela");
			return EXIT_SUCCESS;
		}

		newClient.clientId = *uniqueID;
		state = 0;

		addClient(clientList, len, newClient.companyName, newClient.cuit, newClient.adress, newClient.localityId, newClient.clientId);
	}

	return state;
}

int addClient (eClients* clientList, int len, char companyName [], char cuit[], char adress [], int localityId, int id) ///
{
	int pos;

	if(clientList != NULL && len > 0)
	{
		pos = freeClientSpot(clientList, len);

		strcpy(clientList[pos].companyName, companyName);
		strcpy(clientList[pos].cuit, cuit);
		strcpy(clientList[pos].adress, adress);
		clientList[pos].localityId = localityId;
		clientList[pos].clientId = id;
		clientList[pos].isEmpty = FULL;
	}

	return 1;
}

int idAsk(eClients* clientList, sLocality* localitiesList, int len)
{
	int enteredIdToRemove;
	int positionToUse;

	if(clientList != NULL && len > 0)
	{
		CLI_printClientsListWithLocalities(clientList, localitiesList, 100, 100);

		enteredIdToRemove = getValidInt("\n\n\t\t\t\t\t\t\tDespues de haber visto la lista de los Id's disponibles, cual desea elegir?",
				"\n\n\t\t\t\t\tERROR - (El id ingresado no existe  intentelo nuevamente) - ERROR", 1, 100);

		positionToUse = idValidation(clientList, localitiesList, len, enteredIdToRemove);
	}

	return positionToUse;
}

int idValidation (eClients* clientList, sLocality* localitiesList, int len, int enteredId)
{
	int pos;

	pos = -1;

	if(clientList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(enteredId == clientList[i].clientId && clientList[i].isEmpty == FULL)
			{
				pos = i;
				break;
			}
		}
		if(pos == -1)
		{
			printf("\t\t\t\t\tLamentamos informale que ese id no existe");
			idAsk(clientList, localitiesList, len);
		}
	}
	return pos;
}

int modifyClient (eClients* clientList, sLocality* localitiesList, int len, int* uniqueLocalityID) //
{
	int positionToUse;
	int option;
	char auxLocality[MAX];
	int newLocalityId;

	if(clientList != NULL && len > 0)
	{
		positionToUse = idAsk(clientList, localitiesList, len);

		 option = getValidInt("\n\n\t\t\tIngrese la opcion que desea llevar a cabo para modificar { 1 - Direccion - 2 - Localidad }: ",
				 "\n\n\t\t\tERROR - (That option to modify doesn't exist try again) - ERROR",1,2);
		switch(option)
		{
			case 1:
				askForAdress("\n\t\t\t\t\t\t\t\t\tIngrese la direccion de su compañia: ", clientList[positionToUse].adress);
			break;
			case 2:
				LOC_printListOfLocalities(localitiesList, MAX);
				getValidLocality("\n\t\t\t\t\t\t\t\tIngrese la localidad de su compañia :) : ",
						"\t\t\t\t\t\tERROR - (RE-Ingrese la localidad de su compañia) - ERROR : \n",
						auxLocality);

						FormartearCadena(auxLocality);

						newLocalityId = LOC_search(localitiesList, MAX, auxLocality, uniqueLocalityID);

						if(newLocalityId != 0)
						{
							clientList[positionToUse].localityId = newLocalityId;
						}
						else
						{
							printf("\n\n\t\t\t\t\tNo existe esa localidad vuelva al menu y creela");
							return EXIT_SUCCESS;
						}
			break;
		}
	}
	return 1;
}

int withdrawalClient (eClients* clientList, sLocality* localitiesList, int len) //
{
	int state;
	int positionToUse;

	state = -1;

	if(clientList != NULL && len > 0)
	{
		positionToUse = idAsk(clientList, localitiesList, len);

			if(clientList[positionToUse].isEmpty == FULL)
			{
				clientList[positionToUse].isEmpty = EMPTY; /// Baja logica
			}
	}

	return state;
}

int showOneClient (eClients clientList)
{
	int state;

	state = -1;

		printf("\t\t\t\t\t %10d | %10s | %10s | %10s | %10d |\n",
		clientList.clientId,
		clientList.companyName,
		clientList.cuit,
		clientList.adress,
		clientList.localityId);

		state = 0;

	return state;
}

int showListOfClients (eClients* clientList, int len)
{
	int state;

	state = -1;

	if(clientList != NULL && len > 0)
	{
		printf("\n\t\t\t\t\t|ID Cliente |  Nombre de la compañia | Cuit | Direccion | Localidad|PEDIDOS|\n");
		printf("\t\t\t\t\t|____________|_____________|______________|______|______________|________|\n");

		for(int i = 0; i < len; i++)
		{
			if(clientList[i].isEmpty == FULL)
			{
				showOneClient(clientList[i]);
			}
		}
	}

	return state;
}

/*
int arrayCharge (eClients* clientList, int len, int* uniqueID)
{
	if(clientList != NULL && len > 0)
	{
		for(int i = 0; i < 20; i ++)
		{
			int pos;
			*uniqueID = *uniqueID+2;

			pos = freeClientSpot(clientList, len);

			strcpy(clientList[pos].companyName, "Alberto");
			strcpy(clientList[pos].cuit, "44-4444444-44");
			strcpy(clientList[pos].adress, "Presidente Vigias 44");
			clientList[pos].localityId = *uniqueID;
			clientList[pos].clientId = *uniqueID;
			clientList[pos].isEmpty = FULL;
		}
	}

	return 1;
}
*/

eClients CLI_getOneFromId(eClients* clientList, int clientsLen, int id)
{
	eClients foundClientId;

	if(clientList != NULL && clientsLen > 0)
	{
		for(int i = 0; i < clientsLen; i++)
		{
			if(clientList[i].isEmpty == FULL
			&& clientList[i].localityId == id)
			{
				foundClientId = clientList[i];
				break;
			}
		}
	}
	return foundClientId;
}

int CLI_createRandomClients(eClients* clientList ,int clientsLen,int *uniqueID)
{
	int state;

	state = -1;

	if(clientList != NULL && clientsLen > 0)
	{
		char companyName [][MAX] =  {
		"Coca Cola", "Aguas Beyse", "Ivess","Avalos e Hijos",
		"El Noble", "Termolab","San Patricia", "Pepsico",
		"La Chancha", "Aguas German", "Don Mariano",
		"Gianni el Noble"};

		char cuit [][MAX] = {
				"20-25789963-6", "27-32654787-9",
				"27-42512245-0", "20-45412573-6",
				"21-48512245-6", "27-43212245-0",
				"27-23512245-0", "22-25753854-8",
				"20-25789963-6", "26-25789963-1",
				"27-42512245-0", "20-45412573-6"};

		char adress [][MAX] = {"Ricardo Fort 234", "Argelia 4588",
				"Andres Baranda 582", "Estrada 1258", "Zeballos 3030",
				"V.Ocampo 254", "Madariaga 854", "Carlos Calvo 3334"
				,"Av. Rivadavia 1999", "Scarafilo Escaloneta 44",
				"Presidente Peron 854", "Av. 9 de Julio 854"};

		int idLocalidades[]={1,2,3,4,5,6,4,5,8,9,6,4,2,15,12,20,25,10};

		for (int i = 0; i < 12; i++)
		{
			if(clientList[i].isEmpty == EMPTY)
			{
				strcpy((clientList + i)->companyName, *(companyName + i));
				(clientList + i)->localityId = *(idLocalidades +i);
				(clientList + i)->clientId = *uniqueID = *uniqueID+1;
				strcpy((clientList + i)->cuit , *(cuit +i));
				strcpy((clientList + i)->adress , *(adress +i));
				(clientList + i)->isEmpty = FULL;
			}
		}
	}
	return state;
}
