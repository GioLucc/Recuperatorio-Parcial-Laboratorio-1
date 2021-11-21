/*
 * Nexus.c
 *
 *  Created on: 21 oct. 2021
 *      Author: giova
 */

#include "Nexus.h"

eClients bringClients(eClients* clientList, int lenClients, int id)
{
	eClients oneClient;

		for(int i = 0; i < lenClients; i++)
		{
			if(clientList[i].clientId == id && clientList[i].isEmpty == FULL)
			{
				strcpy(oneClient.companyName , clientList[i].companyName);
				strcpy(oneClient.cuit , clientList[i].cuit);
				strcpy(oneClient.adress , clientList[i].adress);
				oneClient.localityId = clientList[i].localityId;
				oneClient.clientId = clientList[i].clientId;
				break;
			}
		}

	return oneClient;

}

sOrders bringOrders(sOrders* ordersList, int lenOrders, int id)
{
	sOrders oneOrder;

	oneOrder.isEmpty = EMPTY;

	for(int i = 0; i < lenOrders; i++)
	{
		if(ordersList[i].status == COMPLETED
		&& ordersList[i].clientId == id)
		{
			oneOrder.HDPE = ordersList[i].HDPE;
			oneOrder.LDPE = ordersList[i].LDPE;
			oneOrder.PP = ordersList[i].PP;
			oneOrder.desechableThrash = ordersList[i].desechableThrash;
			oneOrder.clientId = ordersList[i].clientId;
			oneOrder.orderId = ordersList[i].orderId;
			oneOrder.isEmpty = FULL;
			break;
		}
	}

	return oneOrder;
}

int deliverOrders (sOrders* ordersList, int ordersLen, int id)
{
	int contadorPendingOrders;

	contadorPendingOrders = 0;

		for(int i = 0; i < ordersLen; i++)
		{
			if(ordersList[i].isEmpty == FULL && ordersList[i].clientId == id && ordersList[i].status == PENDING)
			{
				contadorPendingOrders++;
			}
		}

	return contadorPendingOrders;
}

int showClientsWithPendingOrders (eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders) // 6
{
	int contadorPedidospPendientes;
	int state;

	state = -1;
	contadorPedidospPendientes = 0;

	printf("\n|ID Cliente |  Nombre de la compañia | Cuit | Direccion | Localidad|PEDIDOS|\n");
		printf("|____________|_____________|______________|______|______________|________|\n");

	       for(int i = 0; i < lenClients; i++)
	       {
	    	   if(clientList != NULL && clientList[i].isEmpty == FULL)
	    	   {
	    		   contadorPedidospPendientes = deliverOrders (ordersList, lenOrders, clientList[i].clientId);

	    		    printf(" %10d | %10s | %10s | %10s | %10d | %10d |\n",
					clientList[i].clientId,
					clientList[i].companyName,
					clientList[i].cuit,
					clientList[i].adress,
					clientList[i].localityId,
					contadorPedidospPendientes);
	    	   }
	       }
	       contadorPedidospPendientes = 0;

	return state;
}

int showPedingOrdersWithClientsInfo (eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders) // 7
{
	int state;
	eClients auxClient;

	state = -1;

		printf("\n|      Cuit |        Direccion |        Peso |\n");
			printf("|____________|_____________|______________|\n");

		for(int i = 0; i < lenOrders; i++)
		{
			if(ordersList[i].status == PENDING && ordersList[i].isEmpty == FULL)
			{
				auxClient = bringClients(clientList, MAX, ordersList[i].clientId);

				printf("| %10s | %10s | %10d |\n",
				auxClient.cuit,
				auxClient.adress,
				ordersList[i].orderWeight);

				state = 0;
			}
		}

	return state;
}


int showCompleteOrdersWithWeight (eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders) // 8
{
	int state;
	eClients oneClient;

	state = -1;

	printf("\n|Cuit |  Direccion | Cantidad HDPE | Cantidad LDPE | Cantidad PP | Cantidad no reciclable|\n");
		printf("|____________|_____________|______________|______|______________|________|\n");

		for(int i = 0; i < lenOrders; i++)
		{
			if(ordersList[i].isEmpty == FULL && ordersList[i].status == COMPLETED)
			{
				oneClient = bringClients(clientList, lenClients, ordersList[i].clientId);

					printf("%10s  | %10s  |  %10d | %10d  | %10d  |  %10d |\n" ,
					oneClient.cuit,
					oneClient.adress,
					ordersList[i].HDPE,
					ordersList[i].LDPE,
					ordersList[i].PP,
					ordersList[i].desechableThrash);
					state = 0;
			}
		}

	return state;
}

int showPendingOrdersByLocality (sLocality* localitiesList, eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders, int* uniqueLocalityID) // 9
{
	int state;
	char locality[MAX];
	int ordersByLocalityCounter;
	int localityFoundId;

	ordersByLocalityCounter = 0;

	state = -1;

		getValidLocality("\n\t\t\t\t\t\t\tIngrese la localidad de donde quiere filtrar sus pedidos: ",
		"\t\t\t\t\t\tERROR - (RE-Ingrese la localidad de donde quiere filtrar sus pedidos) - ERROR : \n",
		locality);

		FormartearCadena(locality);

		localityFoundId = LOC_search(localitiesList, lenClients, locality, uniqueLocalityID);

		if(localityFoundId != 0)
		{
			printf("La localidad que has elegido para  filtar los pedidos es %s", locality);

			printf("\n| Localidad | Pedidos Pendientes |\n");
				printf("|____________|______________|\n");

			for(int i = 0; i < lenClients; i++)
			{
				if(clientList[i].isEmpty == FULL && clientList[i].localityId == localityFoundId)
				{
					ordersByLocalityCounter+= deliverOrders(ordersList, lenOrders, clientList[i].clientId);
				}
			}
			printf("| %10s | %10d |\n",
			locality,
			ordersByLocalityCounter);

			state = 0;
		}
		else
		{
			printf("\nEsa localidad no existe, intente agregandola\n"
					"Volviendo al menu principal");

			return EXIT_SUCCESS;
		}

	return state;
}


int getAveragePP (sOrders* ordersList, int lenOrders, int id)
{
	int ppAcumulator;
	int ppAverageResults;
	int clientsCounter;

	clientsCounter = 0;
	ppAcumulator = 0;

	for(int i = 0; i < lenOrders; i++)
	{
		if(ordersList[i].isEmpty == FULL && ordersList[i].status == COMPLETED
		&& ordersList[i].clientId == id)
		{
			clientsCounter++;
			ppAcumulator += ordersList[i].PP;
		}
	}

	if(clientsCounter > 0)
	{
		ppAverageResults = ppAcumulator / clientsCounter;
	}

	return ppAverageResults;
}


int averagePPRecicledByClient (eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders)
{
	int state;
	int ppAverageResults;
	state = -1;

	printf("\n| Nombre de Cliente | Promedio de PP reciclado |\n");
		printf("|____________|______________|\n");

	for(int i = 0; i < lenClients; i++)
	{
		if(clientList[i].isEmpty == FULL)
		{
			ppAverageResults = getAveragePP(ordersList, lenOrders, clientList[i].clientId);

			printf("| %10s | %10d |\n",
			clientList[i].companyName,
			ppAverageResults);
		}
	}

	state = 0;

	return state;
}

