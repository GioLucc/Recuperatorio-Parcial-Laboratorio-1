/*
 * RecolectionOrders.c
 *
 *  Created on: 23 oct. 2021
 *      Author: giova
 */


#include "RecolectionOrders.h"
#include "Nexus.h"


int initOrders (sOrders* ordersList, int len)
{
	int state = -1;

	if(ordersList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			ordersList[i].isEmpty = EMPTY;
		}
	}
	return state;
}

int freeOrderSpot (sOrders* ordersList, int len)
{
	int position;

	position = -1;

	if(ordersList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(ordersList[i].isEmpty == EMPTY)
			{
				position = i;
				break;
			}
		}
	}

	return position;
}

int newOrder (eClients* clientList, sOrders* ordersList, int len, int* uniqueOrderID)
{
	sOrders newOrder;
	int posToSync;

	*uniqueOrderID = *uniqueOrderID+1;

	posToSync = idAsk(clientList, len);
	newOrder.clientId = clientList[posToSync].clientId;
	newOrder.orderWeight = getValidInt("Ingrese el peso del pedido de recoleccion: ",
			"ERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR ", 100, 100000);
	newOrder.orderId = *uniqueOrderID;
	newOrder.status = PENDING;

	addOrder(ordersList,len,newOrder.clientId,newOrder.orderWeight,newOrder.orderId,newOrder.status);

	return 1;
}

int addOrder (sOrders* ordersList, int len, int clientId , int orderWeight, int orderId, int status)
{
	int pos;

	pos = freeOrderSpot(ordersList, len);

	ordersList[pos].clientId = clientId;
	ordersList[pos].orderWeight = orderWeight;
	ordersList[pos].orderId = orderId;
	ordersList[pos].status = PENDING;
	ordersList[pos].isEmpty = FULL;

	return 1;
}

int showOneOrder (sOrders ordersList)
{
	int state;

	state = -1;

	printf(" %10d | %10d | %d | %d |\n",
	ordersList.orderId,
	ordersList.orderWeight,
	ordersList.status,
	ordersList.isEmpty);

	state = 0;

	return state;
}

int showListOfOrders (sOrders* ordersList, int len)
{
	int state;

	state = -1;

	printf("\n|ID Orden | Peso| Status | IsEmpty |\n");
		printf("|____________|_____________|______________|______|\n");

	if(ordersList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(ordersList[i].isEmpty == FULL)
			{
				showOneOrder(ordersList[i]);

			}
		}
	}

	return state;
}

int arrayChargeOrders (sOrders* ordersList, eClients* clientList, int len, int* uniqueOrderID)
{
	int weight;
	int status;
	int pos;
	weight = 1333;


	for(int i = 0; i < 20; i ++)
	{
		*uniqueOrderID = *uniqueOrderID+1;

		pos = freeOrderSpot(ordersList, len);
		ordersList[pos].orderId = *uniqueOrderID;
		ordersList[pos].orderWeight = weight+=33;
		ordersList[pos].clientId = clientList[i].clientId;

//		if(i %2==0)
//		{
			status = PENDING;
//		}
//		else
//		{
//			status = COMPLETED;
//		}
		ordersList[pos].status = status;
		ordersList[pos].isEmpty = FULL;

	}

	return 1;

}

int idOrderAskForProcess(eClients* clientList, sOrders* ordersList, int clientsLen, int ordersLen)
{
	int enteredId;
	int positionToUse;
	eClients oneClient;

	if(ordersList != NULL && ordersLen > 0)
	{
		printf("\n|  ID Orden |         Peso|     Client ID |       Estado |\n");
			printf("|____________|_____________|______________|_____________|\n");

			for(int i = 0; i < ordersLen; i++)
			{
				if(ordersList[i].isEmpty == FULL && ordersList[i].status == PENDING)
				{
					oneClient = bringClients(clientList, clientsLen, ordersList[i].clientId);

					printf("| %10d | %10d | %10d | %10d  |\n",
					ordersList[i].orderId,
					ordersList[i].orderWeight,
					oneClient.clientId,
					ordersList[i].status);
				}
			}

		enteredId = getValidInt("Despues de haber visto la lista de los Id's de los clientes disponibles, a cual desea procesar?",
				"ERROR - (Has ingresado un ID no existente intentelo nuevamente) - ERROR", 1, 100);
	}

	positionToUse = orderIdValidation (ordersList, ordersLen, enteredId);

	 printf("%d", positionToUse);

	return positionToUse;
}

int idOrderAsk(sOrders* ordersList, int len)
{
	int enteredId;
	int positionToUse;

	if(ordersList != NULL && len > 0)
	{
		showListOfOrders(ordersList, len);

		enteredId = getValidInt("Despues de haber visto la lista de los Id's de los clientes disponibles, a cual desea crearle un pedido?",
				"ERROR - (Has ingresado un ID no existente intentelo nuevamente) - ERROR", 1, 100);
	}

	positionToUse = orderIdValidation (ordersList, len, enteredId);

	 printf("%d", positionToUse);

	return positionToUse;
}

int orderIdValidation (sOrders* ordersList, int len, int enteredId)
{
	int pos;

	pos = -1;

		if(ordersList != NULL && len > 0)
		{
			for(int i = 0; i < len; i++)
			{
				if(enteredId == ordersList[i].orderId && ordersList[i].isEmpty == FULL)
				{
					pos = i;
					break;
				}
			}
		}
		if(pos == -1)
		{
			printf("Lamentamos informale que ese id no existe!");
			idOrderAsk(ordersList, len);
		}

		 printf("%d", pos);

	return pos;
}

int processingOrder (eClients* clientList ,sOrders* ordersList, int clientsLen, int ordersLen)
{
	int posOrderToProcess;
	int weightOfOrder;
	int processingOrder;

	posOrderToProcess = idOrderAskForProcess(clientList, ordersList, 100, 1000);

	weightOfOrder = ordersList[posOrderToProcess].orderWeight;

	do
	{
		printf("\n Gracias por facilitarnos esos datos, este pedido pesa: %d!\n\n"
				"Porfavor seleccione una sola vez la opcion de reciclaje entre las siguientes:  \n"
				"1 - HDPE: Polietileno de alta densidad "
				"(Envases para lácteos, perfumes, detergentes líquidos, etc.)\n"
				"2 - LDPE: Polietileno de baja densidad "
				"(Bolsas de congelación de alimentos, tapas flexibles o bolsas debasura.)\n "
				"3 - PP: Polipropileno "
				"(Plásticos utilizados en la industria automovilística y en la construcción.)\n"
				"4 - Desechar el resto\n\n"
				"\t\t\t\t\t\t\t !WARNING¡ Todos los desechos que no recicle quedara en el sector desechos !WARNING¡\n\n"
				, weightOfOrder);

		processingOrder = getValidInt("Porfavor ingrese la cantidad de kilos de cada tipo de residuos con mucha precaucion: ","Error", 1, 4);


		switch(processingOrder)
		{
			case 1:
				if(weightOfOrder > 0)
				{
					ordersList[posOrderToProcess].HDPE = getValidInt("Cuanto de este pedido de recoleccion le corresponde a HDPE?\n",
							"ERROR - (El minimo de basura es  y el maximo ) - ERROR ", 1, weightOfOrder);

					weightOfOrder = weightOfOrder - ordersList[posOrderToProcess].HDPE;
					printf("%d", weightOfOrder);

				}
			break;

			case 2:
				if(weightOfOrder > 0)
				{
					ordersList[posOrderToProcess].LDPE = getValidInt("Cuanto de este pedido de recoleccion le corresponde a LDPE?\n",
							"El minimo de basura es %d y el maximo %d ", 1, weightOfOrder);
					weightOfOrder = weightOfOrder - ordersList[posOrderToProcess].LDPE;
					printf("%d", weightOfOrder);

				}
			break;

			case 3:
				if(weightOfOrder > 0)
				{
					ordersList[posOrderToProcess].PP = getValidInt("Cuanto de este pedido de recoleccion le corresponde a PP?\n",
							"El minimo de basura es %d y el maximo %d ", 1, weightOfOrder);
					weightOfOrder = weightOfOrder - ordersList[posOrderToProcess].LDPE;

					printf("%d", weightOfOrder);
				}
			break;

			case 4:
				ordersList[posOrderToProcess].desechableThrash = weightOfOrder;
			break;
		}



		printf("HDPE : %d - LDPE : %d - PP : %d - desechableThrash: %d",
				ordersList[posOrderToProcess].HDPE,
				ordersList[posOrderToProcess].LDPE,
				ordersList[posOrderToProcess].PP,
				ordersList[posOrderToProcess].desechableThrash);

		ordersList[posOrderToProcess].status = COMPLETED;

	}while(processingOrder != 4);

	return 1;

}


