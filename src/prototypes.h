/*File generated automatically in osboxes by luis on qua dez  6 12:08:15 WET 2017*/
#ifdef __cplusplus
extern "C" {
#endif
/* myf.c */
GdkPixbuf *pari_ConvertOpenCv2Gtk (IplImage * image, int dst_w, int dst_h);
void pari_PerformImageAcquisition (CvCapture * capt);
void pari_ProcessUserOperations (IplImage * src_imageG, IplImage * dst_imageG);
void pari_RefreshDrawingArea (char *widgetName, IplImage * img);
CvCapture *pari_StartImageAcquisition ();
/* callback.c */
gboolean on_drawingarea1_expose_event (GtkWidget * widget, GdkEvent * event, gpointer user_data);
gboolean pari_UpdateImageAreas (gpointer data);
/* main.c */
int main (int argc, char *argv[]);
#ifdef __cplusplus
}
#endif
