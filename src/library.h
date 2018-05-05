/*
 * library.h
 *
 *  Created on: 5 mai 2018
 *      Author: louis
 */

#ifndef SRC_LIBRARY_H_
#define SRC_LIBRARY_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <zint.h>

// Resource pour manipulation des dossiers et des fichiers
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#if defined(_WIN32)
#include <direct.h>
#endif

#if defined(_WIN32)
	#define FILE_SEPARATOR_STR "\\"
#else
	#define FILE_SEPARATOR_STR "/"
#endif

#define CLEAR_STDIN { int c; while((c = getchar()) && (c != '\n')); }

#endif /* SRC_LIBRARY_H_ */
