/**
 *       @file  primo.c
 *      @brief  Breve Descrição
 *
 * Descrição mais detalhada do ficheiro que até poderiam incluir links para imagens etc.
 *
 *     @author  luis, email@ua.pt
 *
 *   @
nal
 *     Created  20-set-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, luis
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>		//para o usleep()
#include <sys/time.h>		//header file para gettimeofday e struct timeval
#include <sys/timeb.h>
#include <string.h>
#include "pcolor.h"
#include <signal.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#include "myf.h"





void pari_delete_event(GtkWidget *window,GdkEvent *event, gpointer data)
{
	g_print("You should not use the OS to force leave!\n");
	gtk_main_quit();
}

void InterceptCTRL_C(int a)
{
	g_print("Sair por CTRL-C\n");
	gtk_main_quit();
}

/**
 * @brief  Manage button 3 click with the intention to leave application
 *    Either shows a message or exits
 *
 * @param  w - The Widget ID
 * @param user_data - Custom data with the ID of another widget to check. In this case the switch1
 * @return void
 */
void on_button3_clicked(GtkWidget * widget, gpointer user_data)
{
  gboolean a=gtk_switch_get_active( GTK_SWITCH(user_data)); //user_data points to switch
  if (a == FALSE)
        printf("Must enable the Quit switch before leaving\n");
  else
        gtk_main_quit();
}

/**
 * @brief  Function to process the text from entry and label
 *
 * @param widget - the one that originated the call
 * @param user_data - Custom data with a widget ID to fetch some info
 * @return void
 */
void on_button1_clicked(GtkWidget *widget, gpointer user_data)
{
#if 1
  GtkEntry *ts = GTK_ENTRY(user_data);
  GtkLabel *lbl= GTK_LABEL(gtk_builder_get_object(builderG,"label3")); //Get some specific label ID to change it
  if(ts)
  {
        const char* tss = gtk_entry_get_text(ts); //get the text from entry1 widget
	ReverseString((char*)tss);
        printf("Text available in entry1: %s\n", tss);
        gtk_label_set_text(lbl, tss);   //set entry text in "label2" widget
	//gtk_entry_set_text(ts,tss); //reverse entry content
	gtk_widget_hide( GTK_WIDGET(ts) );
	gtk_widget_show( GTK_WIDGET(ts) );
  }
#endif
}

#if 0
void ReverseString(char *str)
{
  int n;
  char c;
  char *t1 = str;                       //aux pointer to manage input string up to middle
  char *t2 = str + strlen(str) - 1;     //aux pointer to manage input string after the middle
  for(n = 0; n < strlen(str) >> 1; n++) //perform a loop until the middle of the string
  {
        c = *t1;        // save current char of first half of string
        *t1++ = *t2;    // copy char from second half of string into first half
        *t2-- = c;      // copy saved char into second half of string
  }
}

#endif

void ReverseString(char *str)
{
  char c, *t1, *t2;
  for(t1 = str, t2 = str + strlen(str); t1 < t2;) //notice that 3rd param of for is empty
      c = *t1, *t1++ = *--t2, *t2 = c;
}



