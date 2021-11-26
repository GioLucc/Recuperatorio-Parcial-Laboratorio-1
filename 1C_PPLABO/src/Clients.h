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

/// @fn int initClients(eClients*, int)
/// @brief Inicia el array de clientes en empty.
///
/// @param clientList
/// @param len
/// @return -1 si no se logro, 0 si se pudo.
int initClients (eClients* clientList, int len);

/// @fn int freeClientSpot(eClients*, int)
/// @brief Busca lugar libre para un nuevo cliente.
///
/// @param clientList
/// @param len
/// @return devuelve -1 si no se pudo conseguir, o la posicion libre.
int freeClientSpot (eClients* clientList, int len);

/// @fn int newClient(eClients*, sLocality*, int, int*, int*)
/// @brief Pide y valida los datos para la creación de un nuevo cliente.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @param uniqueID
/// @param uniqueLocalityID
/// @return -1 si no se logro, 0 si se pudo.
int newClient (eClients* clientList, sLocality* localitiesList, int len, int* uniqueID, int* uniqueLocalityID);

/// @fn int addClient(eClients*, int, char[], char[], char[], int, int)
/// @brief Alta de cliente, obtiene una posision libre y carga todos los datos de los parametros en esa posicion.
///
/// @param clientList
/// @param len
/// @param companyName
/// @param cuit
/// @param adress
/// @param localityId
/// @param id
/// @return devuelve 1 si se pudo crear.
int addClient (eClients* clientList, int len, char companyName [], char cuit[], char adress [], int localityId, int id);

/// @fn int modifyClient(eClients*, sLocality*, int, int*)
/// @brief Pide ingresar el id de el cliente que quiere modificar y permite cambia dirección y localidad.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @param uniqueLocalityID
/// @return devuelve 1 si pudo hacerlo satisfactoriamente.
int modifyClient (eClients* clientList, sLocality* localitiesList, int len, int* uniqueLocalityID);

/// @fn int idAsk(eClients*, sLocality*, int)
/// @brief Pide un id mostrando la lista de clientes existentes.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @return La posicion para usar.
int idAsk(eClients* clientList, sLocality* localitiesList, int len);

/// @fn int idValidation(eClients*, sLocality*, int, int)
/// @brief Se fija si la posicion recibida por parametros existe.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @param enteredId
/// @return -1 si no existe, la posicion si existe.
int idValidation (eClients* clientList, sLocality* localitiesList, int len, int enteredId);

/// @fn int showOneClient(eClients)
/// @brief muestra un cliente.
///
/// @param clientList
/// @return -1 si no se logro, 0 si se pudo.
int showOneClient (eClients clientList);

/// @fn int showListOfClients(eClients*, int)
/// @brief muestra la lista de clientes existentes si es que existen.
///
/// @param clientList
/// @param len
/// @return -1 si no se logro, 0 si se pudo.
int showListOfClients (eClients* clientList, int len);

/// @fn int withdrawalClient(eClients*, sLocality*, int)
/// @brief Da de baja logica un cliente.
///
/// @param clientList
/// @param localitiesList
/// @param len
/// @return devuelve -1 si no se pudo dar de baja, 0 si se pudo dar de baja.
int withdrawalClient (eClients* clientList, sLocality* localitiesList, int len);


int arrayCharge (eClients* clientList, int len, int* uniqueID);
int initOrdersQueue (eClients* clientList, int len);
eClients CLI_getOneFromId(eClients* clientList, int clientsLen, int id);
int CLI_createRandomClients(eClients* clientList ,int clientsLen,int *uniqueID);


#endif /* CLIENTS_H_ */
