/*
 * Employees.c
 *
 *  Created on: 19 oct. 2021
 *      Author: giova
 */

#include "Clients.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int initClients (eClients* clientList, int len)
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

int freeClientSpot (eClients* clientList, int len)
{
	int position;

	position = -1;

	if(clientList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(clientList[i].isEmpty == EMPTY)
			{
				position = i;
				break;
			}
		}
	}

	return position;
}

int newClient (eClients* clientList, sLocality* localitiesList, int len, int* uniqueID, int* uniqueLocalityID)
{
	int state;
	eClients newClient;
	char auxLocality[MAX];
	int auxIdlocality;


	state = -1;
	*uniqueID = *uniqueID+1;

		getStringVerificado("\n\t\t\t\t\t\t\tIngrese el nombre de su compañia :) : ","\t\t\t\t\t\tERROR - (RE-Ingrese el nombre de su compañia) - ERROR : \n", newClient.companyName);
		getStringVerificado("\n\t\t\t\t\t\t       Ingrese el cuit de su compañia :) : ","\t\t\t\t\t\tERROR - (RE-Ingrese el cuit de su compañia) - ERROR : \n", newClient.cuit);
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
		}
		else
		{
			printf("\n\nNo existe esa localidad vuelva al menu y creela");
		}
		newClient.clientId = *uniqueID;
		state = 0;

		addClient(clientList, len, newClient.companyName, newClient.cuit, newClient.adress, newClient.localityId, newClient.clientId);

	return state;
}

int addClient (eClients* clientList, int len, char companyName [], char cuit[], char adress [], int localityId, int id)
{
	int pos;

	pos = freeClientSpot(clientList, len);

	printf("%d", pos);

	strcpy(clientList[pos].companyName, companyName);
	strcpy(clientList[pos].cuit, cuit);
	strcpy(clientList[pos].adress, adress);
	clientList[pos].localityId = localityId;
	clientList[pos].clientId = id;
	clientList[pos].isEmpty = FULL;

	return 1;
}

int idAsk(eClients* clientList, int len)
{
	int enteredIdToRemove;
	int positionToUse;

	if(clientList != NULL && len > 0)
	{
		showListOfClients(clientList, len);

		enteredIdToRemove = getValidInt("Despues de haber visto la lista de los Id's disponibles, cual desea modificar?",
				"ERROR - (El id ingresado no existe  intentelo nuevamente) - ERROR", 1, 100);
	}

	positionToUse = idValidation(clientList, len, enteredIdToRemove);

	 printf("%d", positionToUse);

	return positionToUse;
}

int idValidation (eClients* clientList, int len, int enteredId)
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
		}
		if(pos == -1)
		{
			printf("Lamentamos informale que ese id no existe");
			idAsk(clientList, len);
		}

		 printf("%d", pos);

	return pos;
}

int modifyClient (eClients* clientList, int len)
{
	int positionToUse;
	int option;

	positionToUse = idAsk(clientList, len);

	 printf("%d", positionToUse);

	 option = getValidInt("Please enter the option you want to modify { 1 - Adress - 2 - Locality }: ",
			 "ERROR - (That option to modify doesn't exist try again) - ERROR",1,2);

	switch(option)
	{
		case 1:
			askForAdress("Ingrese la direccion de su compañia", clientList[positionToUse].adress);
		break;

		case 2:
			/*
			getStringVerificado("Ingrese la localidad residente de su compañia ",
					"REIngrese el nombre de su compañia ",
					clientList[positionToUse].localityId);
					*/
		break;
	}

	return 1;
}

int withdrawalClient (eClients* clientList, int len)
{
	int state;
	int positionToUse;

	state = -1;

	positionToUse = idAsk(clientList, len);

	if(clientList != NULL && len > 0)
	{
		if(clientList[positionToUse].isEmpty == FULL)
		{
			clientList[positionToUse].isEmpty = EMPTY;
		}
	}

	return state;
}

int showOneClient (eClients clientList)
{
	int state;

	state = -1;

	printf(" %10d | %10s | %10s | %10s | %10d |\n",
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

	printf("\n|ID Cliente |  Nombre de la compañia | Cuit | Direccion | Localidad|PEDIDOS|\n");
		printf("|____________|_____________|______________|______|______________|________|\n");

	if(clientList != NULL && len > 0)
	{
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

int arrayCharge (eClients* clientList, int len, int* uniqueID)
{
	for(int i = 0; i < 20; i ++)
	{
		int pos;
		*uniqueID = *uniqueID+1;

		pos = freeClientSpot(clientList, len);

		strcpy(clientList[pos].companyName, "Alberto");
		strcpy(clientList[pos].cuit, "44-4444444-44");
		strcpy(clientList[pos].adress, "Tu Mama 44");
		clientList[pos].localityId = 1; // 1 momentaneo
		clientList[pos].clientId = *uniqueID;
		clientList[pos].isEmpty = FULL;

	}

	return 1;

}

int initOrdersQueue (eClients* clientList, int len)
{
	if(clientList != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
			}
		}
	return 1;
}
