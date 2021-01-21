/*-----------------------------------------------------------------------------
* File            : test.c
* Autore          : Alessandro Fraschetti
* Funzione        : Test delle funzioni della libreria MGL
* Parametri in    :
* Parametri out   :
* Note            :
*-----------------------------------------------------------------------------*/


#include <conio.h>
#include <stdio.h>
#include "mgl.h" 


int main(void) {

	char s[40], ch=0,key=0;
	int i = 0, jj = 0;
	int textmodes[] = {0x00, 0x01, 0x07, 0x02, 0x03, 0xFF};
	int graphmodes[] = {0x05, 0x04, 0x0D, 0x13, 0x06, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0xFF};
/*    int allmodes[] = {0x00, 0x01, 0x07, 0x02, 0x03, 0x05, 0x04, 0x0D, 0x13, 0x06, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0xFF}; */
    int extramodes[] = {0x111, 0x103, 0xFF};


    i = 0;
	while (extramodes[i] != 0xFF) {
		MGL_setExtraVideoMode(extramodes[i]);
		sprintf(s, "modo=%x,page=%d,cols=%d", MGL_video.mode, MGL_video.activepage, MGL_video.text.cols); jj=0;
        MGL_writeString(s, MGL_WHITE, MGL_BLACK, MGL_video.activepage);
		i++;

		ch = MGL_readKey(&key);
	}

    i = 0;
	while (textmodes[i] != 0xFF) {
		MGL_setVideoMode(textmodes[i]);

        MGL_clearScreen(MGL_BLUE|MGL_BRIGHT);

        MGL_setCursorPosition(0, 1, MGL_video.activepage);
		sprintf(s, "modo=%2x,page=%d,cols=%d,colors=%d,ch1=%x,ch2=%x", MGL_video.mode, MGL_video.activepage, MGL_video.text.cols, MGL_video.colors, ch, key); jj=0;
        MGL_writeString(s, MGL_BROWN|MGL_BRIGHT, MGL_BLACK, MGL_video.activepage);

        MGL_setCursorPosition(MGL_video.text.cols-2, MGL_video.text.rows-10, MGL_video.activepage);
		MGL_writeString("stringa", MGL_WHITE, MGL_RED, MGL_video.activepage); 

        MGL_setCursorPosition(MGL_video.text.cols-2, MGL_video.text.rows-1, MGL_video.activepage);
		MGL_writeString("stringa", MGL_GREEN|MGL_BRIGHT, MGL_CYAN, MGL_video.activepage); 

		MGL_setCursorPosition(0, 8, MGL_video.activepage); MGL_writeChar('*', MGL_BLUE, MGL_BLACK, MGL_video.activepage);
        MGL_setCursorPosition(0, 9, MGL_video.activepage); MGL_writeChar('*', MGL_GREEN, MGL_BLUE, MGL_video.activepage);
        MGL_setCursorPosition(0,10, MGL_video.activepage); MGL_writeChar('*', MGL_RED, MGL_GREEN, MGL_video.activepage);
        MGL_setCursorPosition(0,11, MGL_video.activepage); MGL_writeChar('*', MGL_MAGENTA, MGL_RED, MGL_video.activepage);
        MGL_setCursorPosition(0,12, MGL_video.activepage); MGL_writeChar('*', MGL_CYAN, MGL_MAGENTA, MGL_video.activepage);
        MGL_setCursorPosition(0,13, MGL_video.activepage); MGL_writeChar('*', MGL_YELLOW, MGL_CYAN, MGL_video.activepage);
        MGL_setCursorPosition(0,14, MGL_video.activepage); MGL_writeChar('*', MGL_WHITE, MGL_YELLOW, MGL_video.activepage);

        MGL_setCursorPosition(1, 8, MGL_video.activepage); MGL_writeChar('*', MGL_BLUE|MGL_BRIGHT, MGL_BLACK|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1, 9, MGL_video.activepage); MGL_writeChar('*', MGL_GREEN|MGL_BRIGHT, MGL_BLUE|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1,10, MGL_video.activepage); MGL_writeChar('*', MGL_RED|MGL_BRIGHT, MGL_GREEN|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1,11, MGL_video.activepage); MGL_writeChar('*', MGL_MAGENTA|MGL_BRIGHT, MGL_RED|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1,12, MGL_video.activepage); MGL_writeChar('*', MGL_CYAN|MGL_BRIGHT, MGL_MAGENTA|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1,13, MGL_video.activepage); MGL_writeChar('*', MGL_YELLOW|MGL_BRIGHT, MGL_CYAN|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1,14, MGL_video.activepage); MGL_writeChar('*', MGL_WHITE|MGL_BRIGHT, MGL_YELLOW|MGL_BRIGHT, MGL_video.activepage);
		i++;

		ch = MGL_readKey(&key);
	}

    i = 0;
	while (graphmodes[i] != 0xFF) {
		MGL_setVideoMode(graphmodes[i]);

        MGL_clearScreen(MGL_BLUE|MGL_BRIGHT);

        MGL_setCursorPosition(0, 1, MGL_video.activepage);
		sprintf(s, "modo=%2x,page=%d,cols=%d,colors=%d,ch1=%x,ch2=%x", MGL_video.mode, MGL_video.activepage, MGL_video.text.cols, MGL_video.colors, ch, key); jj=0;
		MGL_writeString(s, MGL_BROWN|MGL_BRIGHT, MGL_BLACK, MGL_video.activepage);

        MGL_setCursorPosition(MGL_video.text.cols-2, MGL_video.text.rows-10, MGL_video.activepage);
		MGL_writeString("stringa", MGL_WHITE, MGL_RED, MGL_video.activepage); 

        MGL_setCursorPosition(MGL_video.text.cols-2, MGL_video.text.rows-1, MGL_video.activepage);
		MGL_writeString("stringa", MGL_GREEN|MGL_BRIGHT, MGL_CYAN, MGL_video.activepage); 

		MGL_setCursorPosition(0, 8, MGL_video.activepage); MGL_writeChar('*', MGL_BLUE, MGL_BLACK, MGL_video.activepage);
        MGL_setCursorPosition(0, 9, MGL_video.activepage); MGL_writeChar('*', MGL_GREEN, MGL_BLUE, MGL_video.activepage);
        MGL_setCursorPosition(0,10, MGL_video.activepage); MGL_writeChar('*', MGL_RED, MGL_GREEN, MGL_video.activepage);
        MGL_setCursorPosition(0,11, MGL_video.activepage); MGL_writeChar('*', MGL_MAGENTA, MGL_RED, MGL_video.activepage);
        MGL_setCursorPosition(0,12, MGL_video.activepage); MGL_writeChar('*', MGL_CYAN, MGL_MAGENTA, MGL_video.activepage);
        MGL_setCursorPosition(0,13, MGL_video.activepage); MGL_writeChar('*', MGL_YELLOW, MGL_CYAN, MGL_video.activepage);
        MGL_setCursorPosition(0,14, MGL_video.activepage); MGL_writeChar('*', MGL_WHITE, MGL_YELLOW, MGL_video.activepage);

        MGL_setCursorPosition(1, 8, MGL_video.activepage); MGL_writeChar('*', MGL_BLUE|MGL_BRIGHT, MGL_BLACK|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1, 9, MGL_video.activepage); MGL_writeChar('*', MGL_GREEN|MGL_BRIGHT, MGL_BLUE|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1,10, MGL_video.activepage); MGL_writeChar('*', MGL_RED|MGL_BRIGHT, MGL_GREEN|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1,11, MGL_video.activepage); MGL_writeChar('*', MGL_MAGENTA|MGL_BRIGHT, MGL_RED|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1,12, MGL_video.activepage); MGL_writeChar('*', MGL_CYAN|MGL_BRIGHT, MGL_MAGENTA|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1,13, MGL_video.activepage); MGL_writeChar('*', MGL_YELLOW|MGL_BRIGHT, MGL_CYAN|MGL_BRIGHT, MGL_video.activepage);
        MGL_setCursorPosition(1,14, MGL_video.activepage); MGL_writeChar('*', MGL_WHITE|MGL_BRIGHT, MGL_YELLOW|MGL_BRIGHT, MGL_video.activepage);
		i++;

        for (jj=0; jj<100; jj++) {
	        MGL_writePixel(jj,jj, MGL_CYAN, MGL_video.activepage);
	        MGL_writePixel(jj+3,jj, MGL_CYAN|MGL_BRIGHT, MGL_video.activepage);
		}

        MGL_writePixel(MGL_video.graphic.cols-1, MGL_video.graphic.rows-1, MGL_WHITE, MGL_video.activepage);

		MGL_setCursorPosition(0, 4, MGL_video.activepage);
        MGL_writeChar('#', MGL_getPixel(3, 0, MGL_video.activepage), MGL_getPixel(0, 0, MGL_video.activepage), MGL_video.activepage);

		ch = MGL_readKey(&key);
	}

	
	MGL_setVideoMode(3);

	return 0;
}
