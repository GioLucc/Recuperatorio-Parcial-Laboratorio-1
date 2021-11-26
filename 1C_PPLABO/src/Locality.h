/*
 * Locality.h
 *
 *  Created on: 18 nov. 2021
 *      Author: giova
 */

#ifndef LOCALITY_H_
#define LOCALITY_H_
#include "BasicFunctions.h"
#define FULL 0
#define EMPTY 1

struct
{
	char locality[MAX];
	int localityId;
	int isEmpty;

}typedef sLocality;

/// @fn int LOC_init(sLocality*, int)
/// @brief Inicia el vector de localidades en EMPTY.
///
/// @param localitiesList
/// @param localitiesLen
/// @return 0 si pudo -1 si no pudo.
int LOC_init (sLocality* localitiesList, int localitiesLen);

/// @fn int LOC_hardcodeLocalities(sLocality*, int, int*)
/// @brief Harcodea localidades
///
/// @param localitiesList
/// @param len
/// @param uniqueLocalityID
/// @return0 si pudo -1 si no pudo.
int LOC_hardcodeLocalities (sLocality* localitiesList, int len, int* uniqueLocalityID);

/// @fn int LOC_freeSpot(sLocality*, int)
/// @brief Busca un lugar libre en el vector para crear una nueva localidad.
///
/// @param localitiesList
/// @param localitiesLen
/// @return 0 si pudo -1 si no pudo.
int LOC_freeSpot (sLocality* localitiesList, int localitiesLen);

/// @fn int LOC_newLocality(sLocality*, int, int*)
/// @brief Pide todos los datos para una nueva localidad y se los pasa LOC_chargeLocalitiesList
///
/// @param localitiesList
/// @param len
/// @param uniqueLocalityID
/// @return 0 si pudo -1 si no pudo.
int LOC_newLocality(sLocality* localitiesList, int len, int* uniqueLocalityID);

/// @fn int LOC_withdrawal(sLocality*, int)
/// @brief Da de baja logica una localidad.
///
/// @param localitiesList
/// @param localitiesLen
/// @return 0 si pudo -1 si no pudo.
int LOC_withdrawal (sLocality* localitiesList, int localitiesLen);

/// @fn int LOC_idAsk(sLocality*, int)
/// @brief Pide un id para dar de baja una localidad.
///
/// @param localitiesList
/// @param localitiesLen
/// @return La posicion si existe o -1 si no existe.
int LOC_idAsk(sLocality* localitiesList, int localitiesLen);

/// @fn int LOC_idValidation(sLocality*, int, int)
/// @brief Valida si existe un id para dar de baja una localidad.
///
/// @param localitiesList
/// @param localitiesLen
/// @param enteredId
/// @return La posicion si existe o -1 si no existe.
int LOC_idValidation (sLocality* localitiesList, int localitiesLen, int enteredId);

/// @fn int LOC_chargeLocalitiesList(sLocality*, int*, int, char[])
/// @brief Alta de nueva localidad
///
/// @param localitiesList
/// @param uniqueLocalityID
/// @param localitiesLen
/// @param auxLocality
/// @return 0 si la pudo crear o -1 si no pudo crearla.
int LOC_chargeLocalitiesList(sLocality* localitiesList, int* uniqueLocalityID, int localitiesLen, char auxLocality []);
int LOC_search (sLocality* localitiesList, int localitiesLen, char auxLocality [], int* uniqueLocalityID);
int LOC_printOneLocality(sLocality localitiesList);
int LOC_printListOfLocalities(sLocality* localitiesList, int len);
sLocality LOC_getOneFromId(sLocality* localitiesList, int localitiesLen, int id);


#endif /* LOCALITY_H_ */
