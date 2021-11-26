/*
 * parser.h
 *
 *  Created on: 5 nov. 2021
 *      Author: PCNEW
 */

#ifndef PARSER_H_
#define PARSER_H_


int parser_PerroFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_PerroFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
#endif /* PARSER_H_ */
