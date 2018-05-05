/*
 * menu.c
 *
 *  Created on: 5 mai 2018
 *      Author: louis
 */
#include "menu.h"

// Menu principal de l'application avec entréede donnée
void mainLoop(){
	int end = 1;
	int choise = 0;
	char * id = NULL;
	id = malloc(sizeof(char) * 100);
	if(id == NULL){
		printf("Erreur l'allocation a echoué ! \n");
		exit(EXIT_FAILURE);
	}
	printf("Binvenue dans le générateur de code barre CODE 128 ");
	printf("\n");
	checkDirectoryExist();

	while(end == 1){
		printf("Pour créer un code barre entrée 1");
		printf("\n");
		printf("Pour quiter l'application entrée 0 : ");
		scanf("%d", &choise);
		printf("\n");
		CLEAR_STDIN;


		if(choise != 0 &&choise != 1){
			printf("Erreur mauvaise entrée de donnée ! \n");
			free(id);
			exit(EXIT_FAILURE);
		}
		switch(choise){
			case 0:
				free(id);
				exit(EXIT_SUCCESS);
				break;

			case 1:
				printf("Entrée l'id de l'utilisateur : ");
				fgets(id, 50, stdin);
				id[strlen(id) - 1] = '\0';
				CLEAR_STDIN;
				generateBarcode(id);
				break;
		}
	}
	free(id);
	return;
}

// Génération d'un code barre à partir de l'id de User cible

void generateBarcode(char * idE){
	struct zint_symbol * my_symbol = NULL;
	char * filename = NULL;
	char * id = NULL;

	// Création du symbole
	my_symbol = ZBarcode_Create();
	// Génération du nom du fichier code barre
	filename = generateFilename(idE);
	id = malloc(sizeof(char) * 50);
	if(id == NULL){
		printf("Erreur l'allocation a échoué ! \n");
		exit(EXIT_FAILURE);
	}

	// Set du nom fichier dans le symbole
	strcpy(my_symbol->outfile, filename);
	// Set de l'affichage du contenu du code barre (false)
	my_symbol->show_hrt = 0;
	strcpy(id, START_ID);
	strcat(id, idE);

	// Généartion du code barre en CODE 128
	ZBarcode_Encode(my_symbol, (uint8_t*) id, 0);

	// Sauvegarde du code en image
	ZBarcode_Print(my_symbol, 0);

	// Libération de la mémoire
	free(filename);
	free(id);
	ZBarcode_Delete(my_symbol);
	return;
}

// Génération du nom du fichier
char * generateFilename(char * id){
	char * filename = NULL;
	filename = malloc(sizeof(char) * 100);
	if(filename == NULL){
		printf("Erreur l'allocation a échoué ! \n");
		exit(EXIT_FAILURE);
	}
	strcpy(filename, START_FILE);
	strcat(filename, FILE_SEPARATOR_STR);
	strcat(filename, id);
	strcat(filename, END_FILE);
	return filename;

}

void checkDirectoryExist(){
	DIR* dir = opendir(START_FILE);

	if (dir){
		// Si oui
		closedir(dir);

	}else if (ENOENT == errno){
		// Sinon
#if defined(_WIN32)
		_mkdir(START_FILE);
#else
		mkdir(START_FILE, 0700);
#endif

	}else{
		// Erreur
		printf("Erreur à l'ouverture/creation du dossier Passage ! \n");
		exit(EXIT_FAILURE);

	}
}
