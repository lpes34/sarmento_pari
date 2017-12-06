/**
 *       @file  myf.h
 *      @brief  Breve Descrição
 *
 * Descrição mais detalhada do ficheiro que até poderiam incluir links para imagens etc.
 *
 *     @author  luis, sarmento@ua.pt
 *
 *   @internal
 *     Created  27-set-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, luis
 *
 * =====================================================================================
 */

typedef int byte;   // cria um novo tipo chamado byte que é o mesmo que int


typedef struct 
{
	double r; /**< @brief Parte real do tipo complexo */
	double i; /**< @brief Parte imaginaria do tipo complexo */
} complexo; //complexo é o novo tipo de variavel. r i sao os campos do novo tipo de variavel

typedef struct
{
	int horas; /**< @brief horas do tempo */
	int minutos; /**< @brief minutos do tempo */
	int segundos; /**< @brief segundos do tempo */
}tempo;
typedef struct { int totA, totE, totI, totO, totU, totY;} vStat;

//#include <cv.h>
//#include <highgui.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <termios.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <cairo.h>

#define MAXFFBUFFER 1000
typedef struct {
  int count;
  double x[MAXFFBUFFER];
  double y[MAXFFBUFFER];
} free_form;

#ifdef _MAIN_C_
	int bin_limitG = 128;
	//IplImage *src_imageG = NULL, *dst_imageG = NULL;
	int escapeG=0;

	int count_childG=0;
	int count_parentG=0;
	int pid_childG;

	GtkBuilder *builderG;	
	double xoffG;
	double yoffG;
	free_form ffG={0};   //init count to zero. Do not affect x and y.
	double fontSizeFactorG=1;
#else
	extern int bin_limitG;
	//extern IplImage *src_imageG, *dst_imageG;
	extern int escapeG;

	extern int count_childG;
	extern int count_parentG;
	extern int pid_childG;

	extern GtkBuilder *builderG;
	extern double xoffG;
	extern double yoffG;
	extern free_form ffG;
	extern double fontSizeFactorG;
#endif



typedef enum {imBIN, imCANNY, imERODE, imROTATE} im_operation;


#define NAME_IMG_ORG "ImagemOriginal"
#define NAME_IMG_BIN "ImagemBinarizada"
#define NAME_IMG_TAB "ImagemTabuleiro"
#define NAME_IMG_PRC "ImagemProcessada"


#define SHM_SIZE 128 /**< 128 bytes for shared memory */
#define PARENTDELAY 300000   /**<parent period in us*/
#define CHILDDELAY 900000    /**<child delay in us*/

#include "prototypes.h"
