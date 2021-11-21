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

int showClientsWithPendingOrders (eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders); // 6
int showPedingOrdersWithClientsInfo (eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders); // 7
int showCompleteOrdersWithWeight (eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders); // 8
int showPendingOrdersByLocality (sLocality* localitiesList, eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders, int* uniqueLocalityID); // 9
int averagePPRecicledByClient (eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders); // 10
int clientWithMostPendingOrders (eClients* clientList, sOrders* ordersList, int lenClients, int lenOrders);


eClients bringClients(eClients* clientList,int lenClients, int id);
int deliverOrders (sOrders* ordersList,int ordersLen, int id);
sOrders bringOrders(sOrders* ordersList, int lenOrders, int id);
int getAveragePP (sOrders* ordersList, int lenOrders, int id);
