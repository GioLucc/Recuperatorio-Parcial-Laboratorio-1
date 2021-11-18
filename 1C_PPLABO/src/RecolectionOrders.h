/*
 * RecolectionOrders.h
 *
 *  Created on: 23 oct. 2021
 *      Author: giova
 */

#ifndef RECOLECTIONORDERS_H_
#define RECOLECTIONORDERS_H_

#define FULL 0
#define EMPTY 1
#define COMPLETED 0
#define PENDING 1


#include "BasicFunctions.h"
#include "Clients.h"
struct
{
	// IDs
	int orderId;
	int clientId;

	// Orders Characteristics
	int orderWeight;
	int HDPE;
	int LDPE;
	int PP;
	int desechableThrash;

	// Data status
	int status;
	int isEmpty;

}typedef sOrders;

int initOrders (sOrders* ordersList, int len);
int freeOrderSpot (sOrders* ordersList, int len);
int newOrder (eClients* clientList ,sOrders* ordersList, int len, int* uniqueOrderID);
int addOrder (sOrders* ordersList, int len, int clientId , int orderWeight, int orderId, int status);
int showOneOrder (sOrders ordersList);
int showListOfOrders (sOrders* ordersList, int len);
int arrayChargeOrders (sOrders* ordersList, eClients* clientList, int len, int* uniqueOrderID);
int processingOrder (eClients* clientList ,sOrders* ordersList,int clientsLen,int ordersLen);
int idOrderAsk(sOrders* ordersList, int len);
int idOrderAskForProcess(eClients* clientList, sOrders* ordersList, int clientsLen, int ordersLen);
int orderIdValidation (sOrders* ordersList, int len, int enteredId);


#endif /* RECOLECTIONORDERS_H_ */
