/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 * @(#)mgl.h  1.0  1999/05/02
 *   ________        _________________.________
 *  /  _____/  ____ /   _____/   __   \   ____/
 * /   \  ___ /  _ \\_____  \\____    /____  \
 * \    \_\  (  <_> )        \  /    //       \
 *  \______  /\____/_______  / /____//______  /
 *         \/              \/               \/
 *
 * Autore....: Alessandro Fraschetti
 * Libreria..: Micro Graphics Library
 * Descriz...: header file della libreria
 * Note......: libreria di routines per la gestione minimale della grafica a
 *             caratteri ed a pixel.
 *
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#ifndef _MGL_H_
#define _MGL_H_

#ifdef __cplusplus
extern "C" {
#endif 



/*
 * Tipi predefiniti della libreria
 */
typedef unsigned int MGL_COLOR;


/* costanti colori standard */
#define MGL_BLACK      0
#define MGL_BLUE       1
#define MGL_GREEN      2
#define MGL_RED        4
#define MGL_MAGENTA    MGL_BLUE  | MGL_GREEN
#define MGL_CYAN       MGL_BLUE  | MGL_RED
#define MGL_BROWN      MGL_GREEN | MGL_RED
#define MGL_YELLOW     MGL_BROWN
#define MGL_WHITE      MGL_BLUE  | MGL_GREEN | MGL_RED
#define MGL_BRIGHT     8


/* costanti modi video standard */
#define MGL_TEXT40x25x16BW       0x00
#define MGL_TEXT40x25x16         0x01

#define MGL_TEXT80x25x2          0x07
#define MGL_TEXT80x25x16BW       0x02
#define MGL_TEXT80x25x16         0x03

#define MGL_GRAPH320x200x4BW     0x05
#define MGL_GRAPH320x200x4       0x04
#define MGL_GRAPH320x200x16      0x0D
#define MGL_GRAPH320x200x256     0x13

#define MGL_GRAPH640x200x2       0x06
#define MGL_GRAPH640x200x16      0x0E

#define MGL_GRAPH640x350x2       0x0F
#define MGL_GRAPH640x350x16      0x10

#define MGL_GRAPH640x480x2       0x11
#define MGL_GRAPH640x480x16      0x12


/* costanti tipologia modo video */
#define MGL_TEXT_MODE          0x00
#define MGL_GRAPHIC_MODE       0x01

#define MGL_COLOR_MODE         0x00
#define MGL_MONOCHROME_MODE    0x01
#define MGL_BW_MODE            0x02

/* costanti tipologia adattatore video */
#define MGL_NO_ADAPTER         0x00
#define MGL_MDA_ADAPTER        0x01
#define MGL_CGA_ADAPTER        0x02
#define MGL_EGA_ADAPTER        0x04
#define MGL_PGA_ADAPTER        0x06
#define MGL_VGA_ADAPTER        0x07
#define MGL_MCGA_ADAPTER       0x0A
#define MGL_UNKNOW_ADAPTER     0xFF

/* costanti tipologia monitor video */
#define MGL_NO_MONITOR         0x00
#define MGL_MONOCHROME_MONITOR 0x01
#define MGL_COLORS_MONITOR     0x02
#define MGL_UNKNOW_MONITOR     0xFF

/* costanti tasti tabulazione */
#define MGL_KEY_ESC        0x0B
#define MGL_KEY_ENTER      0x0D
#define MGL_KEY_SPACE      0x20
#define MGL_KEY_BACKSPACE  0x08
#define MGL_KEY_TAB        0x09

/* costanti tasti speciali */
#define MGL_KEY_INSERT    0x52 
#define MGL_KEY_DELETE    0x53
#define MGL_KEY_HOME      0x47
#define MGL_KEY_END       0x4F
#define MGL_KEY_PGUP      0x49
#define MGL_KEY_PGDOWN    0x51
#define MGL_KEY_UP        0x48
#define MGL_KEY_DOWN      0x50
#define MGL_KEY_LEFT      0x4B
#define MGL_KEY_RIGHT     0x4D
#define MGL_KEY_F1        0x3B
#define MGL_KEY_F2        0x3C
#define MGL_KEY_F3        0x3D
#define MGL_KEY_F4        0x3E
#define MGL_KEY_F5        0x3F
#define MGL_KEY_F6        0x40
#define MGL_KEY_F7        0x41
#define MGL_KEY_F8        0x42
#define MGL_KEY_F9        0x43
#define MGL_KEY_F10       0x44


/* attributi di dimensione/coordinate */
typedef struct mgl_sizeinfo {
	int       cols;                    /* dimensione/coordinata orizzontale */
	int       rows;                      /* dimensione/coordinata verticale */
} MGL_SIZE, MGL_COORD;

/* dati relativi alle informazioni del modo video corrente */
typedef struct mgl_video {
	int       mode;                      /* contiene il modo video corrente */
    char      modetype;                       /* se modo testuale o grafico */
	char      colortype;            /* se modo a colori, bw o monocromatico */
	int       colors;                    /* numero colori del modo corrente */
	int       pages;               /* numero pagine video del modo corrente */
	int       activepage;              /* pagina video correntemente attiva */
    MGL_SIZE  text;            /* dimensione in caratteri del modo corrente */
    MGL_SIZE  graphic;             /* dimensione in pixel del modo corrente */
	char     *ramaddress;          /* indirizzo ram video del modo corrente */
    int       adapter;          /* tipologia di adattatore video installato */
    int       monitor;             /* tipologia di monitor video installato */
} MGL_VIDEO;


/* variabile globale contenente le informazioni del modo video corrente */
MGL_VIDEO MGL_video;

/* */
MGL_COLOR background;


/* 
 * prototipi delle funzioni della libreria
 */
void MGL_setVideoMode(int mode);
void MGL_setExtraVideoMode(int mode);
int  MGL_getVideoMode(void);
int  MGL_getVideoAdapter(void);
int  MGL_getVideoMonitor(void);
void MGL_setActivePage(int page);
void MGL_clearScreen(int color);
void MGL_cls(void);
void MGL_scrollUp(int rows, int tlrow, int tlcol, int blrow, int brcol, int color);
void MGL_scrollDown(int rows, int tlrow, int tlcol, int blrow, int brcol, int color);
void MGL_setCursorPosition(int col, int row, int page);
void MGL_getCursorPosition(int* col, int* row, int page);
void MGL_setCursorDimension(int size);
int  MGL_getCursorDimension(void);
char MGL_getChar(int* fgcolor, int* bgcolor, int page);
void MGL_writeChar(char ch, int fgcolor, int bgcolor, int page);
int  MGL_getPixel(int col, int row, int page);
void MGL_writePixel(int col, int row, int color, int page);
void MGL_writeString(const char *str, int fgcolor, int bgcolor, int page);
char MGL_readKey(char* skey);



#ifdef __cplusplus
}
#endif /* !defined(__cplusplus) */

#endif /* !defined(_MGL_H_) */
