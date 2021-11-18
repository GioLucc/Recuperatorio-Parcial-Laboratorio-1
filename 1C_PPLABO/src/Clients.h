/*
 * Employees.h
 *
 *  Created on: 19 oct. 2021
 *      Author: giova
 */

#ifndef CLIENTS_H_
#define CLIENTS_H_
#include "BasicFunctions.h"
#define FULL 0
#define EMPTY 1

struct
{
	char companyName[20];
	char cuit[14];
	char adress[20];
	char locality[20];
	int clientId;
	int orderStatus;
	int isEmpty;

}typedef eClients;

int initClients (eClients* clientList, int len);
int freeClientSpot (eClients* clientList, int len);
int newClient (eClients* clientList, int len, int* uniqueID);
int addClient (eClients* clientList, int len, char companyName [], char cuit [], char adress [], char locality [], int id);
int modifyClient (eClients* clientList, int len);
int idAsk(eClients* clientList, int len);
int idValidation (eClients* clientList, int len, int enteredId);
int showOneClient (eClients clientList);
int showListOfClients (eClients* clientList, int len);
int withdrawalClient (eClients* clientList, int len);
int arrayCharge (eClients* clientList, int len, int* uniqueID);
int initOrdersQueue (eClients* clientList, int len);




#endif /* CLIENTS_H_ */
