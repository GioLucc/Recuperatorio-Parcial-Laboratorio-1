/*
 * BasicFunctions.h
 *
 *  Created on: 19 oct. 2021
 *      Author: giova
 */

#ifndef BASICFUNCTIONS_H_
#define BASICFUNCTIONS_H_
#define MAX 100
#define MAX2 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printMenu(void);
void printSubMenu(void);
void printInformsMenu (void);
int getValidInt(char mensaje [], char error [], int min, int max);
int OnlyIntegrersValidation(char integrer[], char mensaje[],char error [], int min, int max);
int getString(char mensaje[],char str[]);
int OnlyCharacterValidation(char str[]);
int askForAdress (char message [], char str[]);
int getStringVerificado(char mensaje[], char mensajeError[], char *input);
int argentinianCuitValidation (char mensaje[], char mensajeError[], char *input);
int getValidLocality(char mensaje[], char mensajeError[], char *input);
int OnlyCharacterValidation(char str[]);
void FormartearCadena(char str[]);


#endif /* BASICFUNCTIONS_H_ */
