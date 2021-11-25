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

int LOC_init (sLocality* localitiesList, int localitiesLen);
int LOC_hardcodeLocalities (sLocality* localitiesList, int len, int* uniqueLocalityID);
int LOC_freeSpot (sLocality* localitiesList, int localitiesLen);
int LOC_newLocality(sLocality* localitiesList, int len, int* uniqueLocalityID);
int LOC_withdrawal (sLocality* localitiesList, int localitiesLen);
int LOC_idAsk(sLocality* localitiesList, int localitiesLen);
int LOC_idValidation (sLocality* localitiesList, int localitiesLen, int enteredId);
int LOC_chargeLocalitiesList(sLocality* localitiesList, int* uniqueLocalityID, int localitiesLen, char auxLocality []);
int LOC_search (sLocality* localitiesList, int localitiesLen, char auxLocality [], int* uniqueLocalityID);
int LOC_printOneLocality(sLocality localitiesList);
int LOC_printListOfLocalities(sLocality* localitiesList, int len);
sLocality LOC_getOneFromId(sLocality* localitiesList, int localitiesLen, int id);


#endif /* LOCALITY_H_ */
