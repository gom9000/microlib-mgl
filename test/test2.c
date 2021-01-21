/*-----------------------------------------------------------------------------
* File            : test.c
* Autore          : Alessandro Fraschetti
* Funzione        : Test delle funzioni della libreria MGL
* Parametri in    :
* Parametri out   :
* Note            :
*-----------------------------------------------------------------------------*/


#include <stdio.h>
#include "mgl.h" 


int main(void) {
	COLOR _bgcolor, _fgcolor;
	int ch, ch2, flag;


    /* salva le attuali proprietà dello schermo */
    _bgcolor = getBackgroundColor();
	_fgcolor = getForegroundColor();

    ch = ' ';
    while (ch != '0') {
		fillScreen(ch);
		setCursorPosition(9, 12);
   	    printf("Un carattere qualsiasi per modificare il riempimento");
		setCursorPosition(9, 13);
		printf("dello schermo (0 per terminare):");
		printf("\n(%d,%d)", getCursorPositionX(),getCursorPositionY());
	    ch = pause();
	}

    ch = ch2 = '0';
	flag = 0;
    while (ch != '9') {
		if (ch == 'a') flag = (flag?0:8);
		else ch2 = ch;
		setBackgroundColor(ch2|flag);
		clearScreen();
		setCursorPosition(7, 12);
   	    printf("Un numero qualsiasi per modificare il colore di background");
		setCursorPosition(7, 13);
		printf("dello schermo (9 per terminare):");
		setCursorPosition(7, 14);
		printf("a per %s la funzione bright sul colore selezionato", (flag?"disattivare":"attivare"));
	    ch = pause();
	}

	ch = ch2 = '0';
	flag = 0;
    while (ch != '9') {
		if (ch == 'a') flag = (flag?0:8);
		else ch2 = ch;
		setForegroundColor(ch2|flag);
		clearScreen();
		setCursorPosition(7, 13);
   	    printf("Un numero qualsiasi per modificare il colore di foreground");
		setCursorPosition(7, 14);
		printf("dello schermo (9 per terminare):");
		setCursorPosition(7, 15);
		printf("a per %s la funzione bright sul colore selezionato", (flag?"disattivare":"attivare"));
	    ch = pause();
	}


    setBackgroundColor(BLACK);
    setForegroundColor(RED|BRIGHT);
	clearScreen();

    printf("\n\n");

    setForegroundColor(BLUE|BRIGHT);
    setBackgroundColor(WHITE);

    printf(".------. .------. .------. .------.\n");
    printf("|7.--. | |8.--. | |K.--. | |A.--. |\n");
    printf("| (\\/) | | :(): | | :/\\: | | :/\\: |\n");
    printf("| :\\/: | | ()() | | :\\/: | | (__) |\n");
    printf("| '--'7| | '--'8| | '--'K| | '--'A|\n");
    printf("`------' `------' `------' `------'\n");

    setBackgroundColor(BLACK);

    printf("\n\n");

    setForegroundColor(GREEN|BRIGHT);



    /* ripristina le originali proprietà dello schermo */
    setBackgroundColor(_bgcolor);
    setForegroundColor(_fgcolor);

    return 0;
}
