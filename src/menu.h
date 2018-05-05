/*
 * menu.h
 *
 *  Created on: 5 mai 2018
 *      Author: louis
 */

#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include "library.h"
#define START_FILE "Image"
#define END_FILE ".png"
#define START_ID "id="

void mainLoop();
void generateBarcode(char *);
void checkDirectoryExist();
char * generateFilename(char *);

#endif /* SRC_MENU_H_ */
