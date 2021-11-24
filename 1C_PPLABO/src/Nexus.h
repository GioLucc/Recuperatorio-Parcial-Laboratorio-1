/*
 * Nexus.h
 *
 *  Created on: 21 oct. 2021
 *      Author: giova
 */

// Acá van todos los .h

#ifndef NEXUS_H_
#define NEXUS_H_

#include "BasicFunctions.h"
#include "Clients.h"
#include "Locality.h"
#include "RecolectionOrders.h"



#endif /* NEXUS_H_ */

int showClientsWithPendingOrders (eClients* clientList, sOrders* ordersList,sLocality* localitiesList, int clientsLen, int lenOrders, int localitiesLen); // 6
int showPedingOrdersWithClientsInfo (eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders); // 7
int showCompleteOrdersWithWeight (eClients* clientList, sOrders* ordersList, sPlastics* plasticList, int clientsLen, int ordersLen); // 8
int showPendingOrdersByLocality (sLocality* localitiesList, eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders, int* uniqueLocalityID); // 9
int averagePPRecicledByClient (eClients* clientList, sOrders* ordersList,sPlastics* plasticList, int clientsLen, int ordersLen); // 10
int clientWithMostOrders (eClients* clientList, sLocality* localitiesList,sOrders* ordersList, int clientsLen, int ordersLen, int status); // 11 12 13
int printPlasticRecicledByLocality(eClients* clientList, sLocality* localitiesList,sOrders* ordersList, sPlastics* plasticList, int clientsLen, int ordersLen, int* uniqueLocalityID); // 14
int CLI_printOneClientWithLocality(eClients clientList, sLocality* localitiesList, int clientsLen, int localitiesLen);
int CLI_printClientsListWithLocalities(eClients* clientList, sLocality* localitiesList, int clientsLen, int localitiesLen);


eClients bringClients(eClients* clientList,int lenClients, int id);
int deliverOrders (sOrders* ordersList,int ordersLen, int id);
sOrders bringOrders(sOrders* ordersList, int ordersLen, int id);
sPlastics bringPlasticTypes (sPlastics* plasticList, int plasticLen, int id);
int ppAcumulator (sPlastics* plasticList,int lenPlastic, int id); // 10
int countClientsByOrder (sOrders* ordersList, sPlastics* plasticsList,int ordersLen, int id);
