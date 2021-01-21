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

int pause(void);

int pause(void) {
    return getch();
}


int main(void) {

	char s[40];
	int i = 0, jj, kk;
	int textmodes[] = {0x00, 0x01, 0x07, 0x02, 0x03, 0xFF};
	int graphmodes[] = {0x05, 0x04, 0x0D, 0x13, 0x06, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0xFF};

    while (textmodes[i] != 0xFF) {
		MGL_setVideoMode(textmodes[i]);

		setForegroundTextColor(WHITE); setBackgroundTextColor(BLACK); clearScreen();
		setForegroundTextColor(BLUE|BRIGHT); setCursorPosition(0, 0); writeSmallLogo();

        sprintf(s, "modo=%x,text=%dx%d,graph=%dx%d", video.mode,video.text.cols,video.text.rows,video.graphic.cols,video.graphic.rows);
        setCursorPosition(0, 5); setForegroundTextColor(WHITE); setBackgroundTextColor(BLACK); writeString(s);

		sprintf(s, "%s,%s", video.graphicmode? "graphic" : "text",video.monochrome? "monochrome" : "color");
        setCursorPosition(0, 6); setForegroundTextColor(WHITE); setBackgroundTextColor(BLACK); writeString(s);

        setCursorPosition(0, 8); setForegroundTextColor(BLUE); setBackgroundTextColor(WHITE);    writeString("BLUE   ");
        setCursorPosition(0, 9); setForegroundTextColor(GREEN); setBackgroundTextColor(BLUE);   writeString("GREEN  ");
        setCursorPosition(0,10); setForegroundTextColor(RED); setBackgroundTextColor(GREEN);     writeString("RED    ");
        setCursorPosition(0,11); setForegroundTextColor(MAGENTA); setBackgroundTextColor(RED); writeString("MAGENTA");
        setCursorPosition(0,12); setForegroundTextColor(CYAN); setBackgroundTextColor(MAGENTA);    writeString("CYAN   ");
        setCursorPosition(0,13); setForegroundTextColor(YELLOW); setBackgroundTextColor(CYAN);  writeString("YELLOW ");
        setCursorPosition(0,14); setForegroundTextColor(WHITE); setBackgroundTextColor(YELLOW);   writeString("WHITE  ");

        setCursorPosition(7, 8); setForegroundTextColor(BLUE|BRIGHT); setBackgroundTextColor(WHITE|BRIGHT);    writeString("BLUE   ");
        setCursorPosition(7, 9); setForegroundTextColor(GREEN|BRIGHT); setBackgroundTextColor(BLUE|BRIGHT);   writeString("GREEN  ");
        setCursorPosition(7,10); setForegroundTextColor(RED|BRIGHT); setBackgroundTextColor(GREEN|BRIGHT);     writeString("RED    ");
        setCursorPosition(7,11); setForegroundTextColor(MAGENTA|BRIGHT); setBackgroundTextColor(RED|BRIGHT); writeString("MAGENTA");
        setCursorPosition(7,12); setForegroundTextColor(CYAN|BRIGHT); setBackgroundTextColor(MAGENTA|BRIGHT);    writeString("CYAN   ");
        setCursorPosition(7,13); setForegroundTextColor(YELLOW|BRIGHT); setBackgroundTextColor(CYAN|BRIGHT);  writeString("YELLOW ");
        setCursorPosition(7,14); setForegroundTextColor(WHITE|BRIGHT); setBackgroundTextColor(YELLOW|BRIGHT);   writeString("WHITE  ");

        for (jj=0; jj<100; jj++)
            writePixel(2+jj, 16+jj, jj%video.colors);

	    setCursorPosition(video.text.cols-2,video.text.rows-1);
	    writeString("Alex");
*/
/*
		setCursorPosition(0, 0); writeChar('*');
		setCursorPosition(video.text.cols-1, 0); writeChar('*');
		setCursorPosition(0, video.text.rows-1); writeChar('*');
		setCursorPosition(video.text.cols-1, video.text.rows-1); writeChar('*');
		setCursorPosition(0, video.text.rows/2); writeString(s);
		setCursorPosition(video.text.cols-2, video.text.rows-1); writeString("alex");
*/
/*
		i++;
		pause();
    }

    i = 0;
    while (graphmodes[i] != 0xFF) {
		video = setVideoMode(graphmodes[i]);

		setForegroundTextColor(WHITE); setBackgroundTextColor(BLACK); clearScreen();
		setForegroundTextColor(BLUE); setCursorPosition(0, 2); writeSmallLogo();

        sprintf(s, "modo=%x,text=%dx%d,graph=%dx%d", video.mode,video.text.cols,video.text.rows,video.graphic.cols,video.graphic.rows);
        setCursorPosition(0, 5); setForegroundTextColor(WHITE); setBackgroundTextColor(BLACK); writeString(s);

		sprintf(s, "%s,%s", video.graphicmode? "graphic" : "text",video.monochrome? "monochrome" : "color");
        setCursorPosition(0, 6); setForegroundTextColor(WHITE); setBackgroundTextColor(BLACK); writeString(s);

        setCursorPosition(0, 8); setForegroundTextColor(BLUE); setBackgroundTextColor(WHITE);    writeString("BLUE   ");
        setCursorPosition(0, 9); setForegroundTextColor(GREEN); setBackgroundTextColor(BLUE);   writeString("GREEN  ");
        setCursorPosition(0,10); setForegroundTextColor(RED); setBackgroundTextColor(GREEN);     writeString("RED    ");
        setCursorPosition(0,11); setForegroundTextColor(MAGENTA); setBackgroundTextColor(RED); writeString("MAGENTA");
        setCursorPosition(0,12); setForegroundTextColor(CYAN); setBackgroundTextColor(MAGENTA);    writeString("CYAN   ");
        setCursorPosition(0,13); setForegroundTextColor(YELLOW); setBackgroundTextColor(CYAN);  writeString("YELLOW ");
        setCursorPosition(0,14); setForegroundTextColor(WHITE); setBackgroundTextColor(YELLOW);   writeString("WHITE  ");

        setCursorPosition(7, 8); setForegroundTextColor(BLUE|BRIGHT); setBackgroundTextColor(WHITE|BRIGHT);    writeString("BLUE   ");
        setCursorPosition(7, 9); setForegroundTextColor(GREEN|BRIGHT); setBackgroundTextColor(BLUE|BRIGHT);   writeString("GREEN  ");
        setCursorPosition(7,10); setForegroundTextColor(RED|BRIGHT); setBackgroundTextColor(GREEN|BRIGHT);     writeString("RED    ");
        setCursorPosition(7,11); setForegroundTextColor(MAGENTA|BRIGHT); setBackgroundTextColor(RED|BRIGHT); writeString("MAGENTA");
        setCursorPosition(7,12); setForegroundTextColor(CYAN|BRIGHT); setBackgroundTextColor(MAGENTA|BRIGHT);    writeString("CYAN   ");
        setCursorPosition(7,13); setForegroundTextColor(YELLOW|BRIGHT); setBackgroundTextColor(CYAN|BRIGHT);  writeString("YELLOW ");
        setCursorPosition(7,14); setForegroundTextColor(WHITE|BRIGHT); setBackgroundTextColor(YELLOW|BRIGHT);   writeString("WHITE  ");

	    setCursorPosition(video.text.cols-2,video.text.rows-1);
	    writeString("Alex");

        for (jj=0; jj<100; jj++)
            writePixel(jj, jj, jj%video.colors);

        for (jj=0; jj<5; jj++)
			for (kk=0; kk<video.graphic.cols-10; kk++)
                writePixel(kk, jj, kk%video.colors);

/*
		setCursorPosition(0, 0); writeChar('*');
		setCursorPosition(video.text.cols-1, 0); writeChar('*');
		setCursorPosition(0, video.text.rows-1); writeChar('*');
		setCursorPosition(video.text.cols-1, video.text.rows-1); writeChar('*');
		setCursorPosition(0, video.text.rows/2); writeString(s);
		setCursorPosition(video.text.cols-2, video.text.rows-1); writeString("alex");

		i++;
		pause();
    }

/*
    setVideoMode(0);
	video = getVideoMode();
	setForegroundTextColor(BLUE);
	setBackgroundTextColor(RED);
	fillScreen('x');
	setCursorPosition(video.text.cols-2,video.text.rows-1);

	writeString("Alex");
	setCursorPosition(3,5);
	setForegroundTextColor(GREEN);
	setBackgroundTextColor(MAGENTA);
	writeChar('*');

	pause();

    setVideoMode(1);
	video = getVideoMode();
	setForegroundTextColor(GREEN);
	setBackgroundTextColor(RED);
	fillScreen('x');
	setCursorPosition(video.text.cols-2,video.text.rows-1);
	writeString("Alex");
	pause();

    setVideoMode(2);
	video = getVideoMode();
	setForegroundTextColor(BLUE);
	setBackgroundTextColor(RED);
	fillScreen('x');
	setCursorPosition(video.text.cols-2,video.text.rows-1);
	writeString("Alex");
	pause();

    setVideoMode(3);
	video = getVideoMode();
	setForegroundTextColor(BLUE);
	setBackgroundTextColor(RED);
	fillScreen('x');
	setCursorPosition(video.text.cols-2,video.text.rows-1);
	writeString("Alex");
	pause();

    setVideoMode(4);
	video = getVideoMode();
	setForegroundTextColor(BLUE);
	setBackgroundTextColor(RED);
	fillScreen('x');
	setCursorPosition(video.text.cols-2,video.text.rows-1);
	writeString("Alex");
	pause();

    setVideoMode(5);
	video = getVideoMode();
	setForegroundTextColor(BLUE);
	setBackgroundTextColor(RED);
	fillScreen('x');
	setCursorPosition(video.text.cols-2,video.text.rows-1);
	writeString("Alex");
	pause();

    setVideoMode(6);
	video = getVideoMode();
	setForegroundTextColor(BLUE);
	setBackgroundTextColor(RED);
	fillScreen('x');
	setCursorPosition(video.text.cols-2,video.text.rows-1);
	writeString("Alex");
	pause();

    setVideoMode(7);
	video = getVideoMode();
	setForegroundTextColor(BLUE);
	setBackgroundTextColor(RED);
	fillScreen('x');
	setCursorPosition(video.text.cols-2,video.text.rows-1);
	writeString("Alex");
	pause();


    setVideoMode(3);
*/
}
