/*
 * Plastics.h
 *
 *  Created on: 22 nov. 2021
 *      Author: giova
 */

#ifndef PLASTICS_H_
#define PLASTICS_H_
#define FULL 0
#define EMPTY 1
#include "BasicFunctions.h"

struct
{
	int orderId;
	int HDPE;
	int LDPE;
	int PP;
	int desechableThrash;
	int isEmpty;

}typedef sPlastics;

int PLA_initArray (sPlastics* plasticsList, int plasticsLen);
int PLA_freeArraySpot (sPlastics* plasticsList, int plasticsLen);
int PLA_processPlastics (sPlastics* plasticsList, int plasticsLen, int id, int weightOrder);



#endif /* PLASTICS_H_ */
