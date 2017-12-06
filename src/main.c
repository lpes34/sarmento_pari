/**
 *       @file  main.c
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
#define _MAIN_C_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h> 
#include <string.h>

#include <signal.h>
#include <sys/time.h>
#include <errno.h>
#include "myf.h"

/*Global variables */
//int bin_limitG = 128;
//IplImage *src_imageG = NULL, *dst_imageG = NULL;

int main( int argc, char *argv[])
{	
#if 0

//EX1
	PrintRedLine();
	HighLightText();
	printf("Texto destacado\n");
	ResetTextColors();
	printf("Texto normal\n");
	PrintRedLine();

#endif

#if 0
//EX2 a
	char *st=GenerateRandomString(100);
	if(st)
	{
		printf("string pedida: \n%s\n",st);
		PrintRedLine();
		ResetTextColors();
		PrintColorVowelsZ(st);
		free(st);
	}
	else
		printf("OUT OF MEMORY \n");

	
	


#endif

#if 0
//EX3
//EX2 a
	char *st=CreateRandomVowelStringX(200);
	if(st)
	{
		//printf("string pedida: \n%s\n",st);
		PrintRedLine();
		ResetTextColors();
		PrintColorVowelsZ(st);
		free(st);
	}
	else
		printf("OUT OF MEMORY \n");


#endif

#if 0
//EX2 a
	char *st=CreateRandomVowelStringX(200);
	if(st)
	{
		//printf("string pedida: \n%s\n",st);
		PrintRedLine();
		ResetTextColors();
		PrintColorVowelsZ(st);
		vStat *vs = CountLettersX(st);
		PrintLettersSatus(vs);
		free(st);
		free(vs);
	}
	else
		printf("OUT OF MEMORY \n");


#endif

#if 0
//ex4
	//char *str1= GenerateRandomString(9);
	char *str1;

	if(argc>1)
	{
		str1 = malloc(sizeof(argv[1]));
		strcpy(str1,argv[1]);
		printf("%s\n",str1);
		ReverseStringX(str1);
		printf("%s\n",str1);
		free(str1);
	}
#endif

#if 0

//EX4 b
	InterleaveStrings("abcde","123");

#endif

////////////////////////// AULA6


//EX1
#if 0
	MyInit();
	MyInit();
#endif

//Ex2
#if 0
	int (* ff)(int, int);  //ff é ponteiro para função que devolve double e aceita dois int

	//ff=(int(*)(int,int))(0x00ff00ff); 
	ff=AddN;//aponta para AddN
	int x = ff(3,5);
	printf ("3+5=%d\n",x);

	int (* opera[4])(int, int)={AddN, MulN, DivN, SubN}; //array de 4 ponteiros para funções


	char op[4]={'+', '*' , ':', '-'};
	int val1=6, val2=3;
	for(int n=0; n< 4; n++)
	printf("Operação %c: %d %c %d = %d\n",op[n], val1, op[n], val2, opera[n](val1, val2) );
#endif

//EX3

#if 0

	
        signal(SIGINT, vive); //ctrl+C
	signal(SIGTSTP,vive1);  //ctrl+Z, value = 20
	signal(SIGQUIT,vive2);  // ctrl+\, value = 3
	signal(SIGTERM,goodbye);  //value = 15  
	int i=0;
	while(1)
	{
		printf("%d\n",++i);
	usleep(50000);
	}


	
#endif


//4

#if 0

	//int k;

	char file_name[] = "baboon.jpg";
	src_imageG = cvLoadImage(file_name, 0);       /*0 for gray, -1 for color */
	//src_imageG = cvLoadImage(argc == 2 ? argv[1] : file_name, 0);   /*0 for gray, -1 for color */
	if(!src_imageG)
	{
		printf("Image was not loaded.\n");
		return -1;
	}

	dst_imageG = cvCloneImage(src_imageG);  //create a copy of the image

	cvNamedWindow(NAME_IMG_ORG, 0);
	cvNamedWindow(NAME_IMG_BIN, 0);

	//cvShowImage(NAME_IMG_ORG,src_imageG);
	//cvShowImage(NAME_IMG_BIN, dst_imageG);

	cvCreateTrackbar("Threshold", NAME_IMG_BIN, &bin_limitG, 255, MakeBinImg); //binarizar
	

	cvShowImage(NAME_IMG_ORG, src_imageG);


	MakeBinImg(0);  //to show the first image (the argument is dummy)

 
	cvWaitKey(0); //wait for a key to be pressed

	cvReleaseImage(&src_imageG);  //free image memory space
	cvReleaseImage(&dst_imageG);  //free image memory space

	return 0;


#endif

// EX7

#if 0
	char key;                                        //character to use below
	cvNamedWindow(NAME_IMG_ORG, 0);                  //Create (empty) window for camera
	cvNamedWindow(NAME_IMG_BIN, 0);                  //Create (empty) window for processed imag
	IplImage * frame;                                //aux image for data acquisition
	CvCapture *capture = cvCaptureFromCAM(0);        //Capture using 1st camera: i.e., no. 0
	if (!capture)
	{
		printf("camera not found\n");
		exit(0);
	}
	frame = cvQueryFrame(capture);              //Get image frames from capture
	int nChannels=1;                            // 1 for gray or 3 for RGB
	src_imageG = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, nChannels);//create image for graylevel (8 bits, 1 channel)
	dst_imageG = cvClone(src_imageG);              //create clone of source image
	cvCreateTrackbar("Threshold",NAME_IMG_BIN , &bin_limitG, 255, NULL); //create the trackbar
	while(1)                                          //Create infinite loop for live viewing
	{
		cvQueryFrame(capture);                    //Update frame. Its pointer does not change.
		cvShowImage(NAME_IMG_ORG, src_imageG);    //Show image 'src_imageG' on created window
		key = cvWaitKey(5);                       //Capture Keyboard stroke
		if(key == 27) break;                      //If you hit ESC key, the loop will break.
		if(nChannels == 1)
			cvCvtColor(frame, src_imageG, CV_BGR2GRAY);  //Convert frame into gray
		else
			cvCopy(frame, src_imageG, NULL);   //copy frame as it is

		cvCopy(src_imageG, dst_imageG, NULL);   //copy src into dst and ready to process

		MakeBinImg(0);    //Your own function to process the image
	}

	cvReleaseCapture(&capture);              //Release capture device.
	cvReleaseImage(&dst_imageG);             //Release image (free pointer when no longer used)
	cvReleaseImage(&src_imageG);             //Release image (free pointer when no longer used).
	cvReleaseImage(&frame);                  //Release image (free pointer when no longer used).
	cvDestroyWindow(NAME_IMG_ORG);           //Destroy Window
	cvDestroyWindow(NAME_IMG_BIN);           //Destroy Window
	return 0;


#endif


// Aula7
// EX1 e 2
#if 0
{
        //ShowAndProcessWebcam(imBIN);
        //ShowAndProcessWebcam(imCANNY);
        //ShowAndProcessWebcam(imERODE);
        ShowAndProcessWebcam(imROTATE);

        
}

#endif

//EX3
#if 0
int LARG=400;
int ALT=400;

IplImage *tabuleiro = cvCreateImage(cvSize(LARG, ALT), IPL_DEPTH_8U, 3);
        cvZero(tabuleiro);      //force initial image to black, otherwise value unknown
        cvNamedWindow(NAME_IMG_TAB, 0);
        

        for(int l = 0; l < tabuleiro->height; l += tabuleiro->height / 8)
                cvLine(tabuleiro, cvPoint(0,l), cvPoint(tabuleiro->width,l), CV_RGB(255, 255, 255), 1, 8, 0 );

        for(int l = 0; l < tabuleiro->width; l += tabuleiro->width / 8)
                cvLine(tabuleiro, cvPoint(l,0), cvPoint(l,tabuleiro->height), CV_RGB(255, 255, 255), 1, 8, 0 );
        /*...*/





//EX4
#if 0


DrawPiece(tabuleiro, 4, 4, 1);
DrawPiece(tabuleiro, 5, 4, 1);
DrawPiece(tabuleiro, 4, 5, 2);
DrawPiece(tabuleiro, 5, 5, 2);
#endif

cvShowImage(NAME_IMG_TAB, tabuleiro);
cvSetMouseCallback(NAME_IMG_TAB, myActionOnMouseClick, (void *) tabuleiro);
char k;
do
{
 k=cvWaitKey(0);
}
while(k != 'q');
cvReleaseImage(&tabuleiro); 
#endif


//Aula8
#if 0


        //...
        int r=InitTimer( RespondAlarm );  //Prepare timer and set RespondAlarm as the callback to be executed
        if (! r ) return 0;               //failed in creating the timer
        while(1);                         //enter an endless loop
        return 0;

#endif

// 1c)
#if 0
src_imageG = cvCreateImage(cvSize(300, 80), IPL_DEPTH_8U, 3); //notice that src_imageG is a global variable
        cvZero(src_imageG);                     //force initial to black, otherwise unknown!
        cvNamedWindow(NAME_IMG_ORG, 1);
        cvShowImage(NAME_IMG_ORG, src_imageG);
        InitTimer(RespondAlarm);                //Actions upon SIGALRM
        cvWaitKey(0);                           //Endless loop untill keyboard is pressed
        cvReleaseImage(&src_imageG);            //release memory allocated by cvCreateImage()
        cvDestroyWindow(NAME_IMG_ORG);          //Destroy Window
#endif

#if 0
int pid = fork();
        //from this point process can check where does it come from: parent or child!
        if(pid == -1)
        {
                printf("Could not fork(). Exiting\n");  //still the parent but failed to fork
                return -1;
        }
        if(pid == 0)  /* This is the child */
        {
                printf("I am the child\n");
		signal(SIGINT, CTRLChandler);
                ChildMain();
        }
        else  /* This is the parent */
        {
               printf("I am the parent\n");
               ParentMain();
        }
#endif

//Ex3
#if 0


int ret = fork();
        int parent_pid;

        if(ret == -1)
        {
                printf("Could not fork(). Exiting\n");
                return -1;
        }
        if(ret == 0)            /* The child */
        {
                signal(SIGUSR1, ChildUSR1handler);
                signal(SIGUSR2, ChildUSR2handler);
                MessageFromChild("I am the child\n");
                parent_pid = getppid();
                usleep(200000); //Must give time to operating system to register signal, otherwise process exits prematurely if it receives it earlier
                ChildMain2(parent_pid);
        }
        else/* The parent */
        {
                signal(SIGUSR1, ParentUSR1handler);
                signal(SIGUSR2, ParentUSR2handler);
                usleep(200000); //idem as above
                MessageFromParent("I am the parent\n");
                ParentMain2(ret);
        }

#endif

//Aula9 
// EX1
#if 0

        int pid = fork();
        int s_id;
        if(pid == -1) { printf("Could not fork(). Exiting\n"); return -1; }

        if(pid == 0)            /* The child */
        {
                MessageFromChild("I am the child\n");
                ChildMain3();
                MessageFromChild("CHILD ended\n");
        }
        else /* The parent */
        {
                MessageFromParent("I am the parent\n");
                s_id = ParentMain3();                       //Get s_id from return value to know the id to destroy the shared mem
                if(s_id > 0) shmctl(s_id, IPC_RMID, NULL);  //Allow elimination of shared memory (elemina a memória quando o último de sair)
                //if you comment the previous line the shared memory is not cleared from system!

                MessageFromParent("PARENT ended\n");
        }

        return 0;
#endif


#if 0
  int n, fd;

    fd=OpenPort("/dev/ttyUSB0", "Ola");
    if(fd == -1) { printf("Error. Could not open port\n"); exit(1); }
    ReadPortUntilChar(fd);
    close(fd);

#endif
//Aula 10 e 11
#if 1

	gtk_init(&argc, &argv);

        /* load the interface after a configuration file*/
        builderG = gtk_builder_new();
        gtk_builder_add_from_file(builderG, "mydr2.glade", NULL);

        /* connect the signals in the interface */
        gtk_builder_connect_signals(builderG, NULL);

        /* get main window Widget ID and connect special signals */
        GtkWidget *t = GTK_WIDGET(gtk_builder_get_object(builderG, "window1"));
        if(t)
        {
                g_signal_connect(G_OBJECT(t), "delete_event", G_CALLBACK(pari_delete_event), NULL);
        }

        // use signal to catch SIGINT  (CTRL-C) - optional
        signal(SIGINT, InterceptCTRL_C);

	p_InitTimer();
        /* start the event loop */
        
        g_timeout_add(30, (GSourceFunc) pari_UpdateImageAreas, (gpointer) NULL);
        captureG=pari_StartImageAcquisition();

        /* start the event loop */
        gtk_main();

        cvReleaseCapture(&captureG);             //Release capture device.
        cvReleaseImage(&dst_imageG);             //Release image (free pointer when no longer used)
        cvReleaseImage(&src_imageG);             //Release image (free pointer when no longer used).

        return 0;

#endif



}
