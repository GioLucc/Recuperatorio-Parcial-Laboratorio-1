/*
 * Employees.h
 *
 *  Created on: 19 oct. 2021
 *      Author: giova
 */

#ifndef CLIENTS_H_
#define CLIENTS_H_
#include "BasicFunctions.h"
#include "Locality.h"
#define FULL 0
#define EMPTY 1

struct
{
	char companyName[20];
	char cuit[14];
	char adress[20];
	int localityId;
	int clientId;
	int orderStatus;
	int isEmpty;

}typedef eClients;

int initClients (eClients* clientList, int len);
int freeClientSpot (eClients* clientList, int len);
int newClient (eClients* clientList, sLocality* localitiesList, int len, int* uniqueID, int* uniqueLocalityID);
int addClient (eClients* clientList, int len, char companyName [], char cuit[], char adress [], int localityId, int id);
int modifyClient (eClients* clientList, sLocality* localitiesList, int len, int* uniqueLocalityID);
int idAsk(eClients* clientList, sLocality* localitiesList, int len);
int idValidation (eClients* clientList, sLocality* localitiesList, int len, int enteredId);
int showOneClient (eClients clientList);
int showListOfClients (eClients* clientList, int len);
int withdrawalClient (eClients* clientList, sLocality* localitiesList, int len);
int arrayCharge (eClients* clientList, int len, int* uniqueID);
int initOrdersQueue (eClients* clientList, int len);
eClients CLI_getOneFromId(eClients* clientList, int clientsLen, int id);
int CLI_createRandomClients(eClients* clientList ,int clientsLen,int *uniqueID);






#endif /* CLIENTS_H_ */
