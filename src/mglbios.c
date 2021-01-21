/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 * @(#)mglbios.c  1.0  1999/05/02
 *   ________        _________________.________
 *  /  _____/  ____ /   _____/   __   \   ____/
 * /   \  ___ /  _ \\_____  \\____    /____  \
 * \    \_\  (  <_> )        \  /    //       \
 *  \______  /\____/_______  / /____//______  /
 *         \/              \/               \/
 *
 * Autore....: Alessandro Fraschetti
 * Libreria..: GoS'95 Micro Graphics Library (DOS-BIOS API)
 * Note......: compilare con djgpp
 *
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/


#include <bios.h>
#include "mgl.h"


extern MGL_VIDEO MGL_video;


/*
 * imposta il modo video corrente
 */
void MGL_setVideoMode(int mode)
{
    union REGS r;

	r.h.ah = 0x00;
    r.h.al = mode;

	int86(0x10, &r, &r);

    MGL_getVideoMode();

    return;
}


/*
 * imposta il modo video corrente non-standard
 */
void MGL_setExtraVideoMode(int mode)
{
    union REGS r;

	r.h.ah = 0x00;
    r.h.al = mode;

	int86(0x10, &r, &r);

	r.h.ah = 0x0F;
    int86(0x10, &r, &r);

    background = MGL_BLACK;

	MGL_video.mode       = r.h.al;
	MGL_video.text.cols  = r.h.ah;
	MGL_video.activepage = r.h.bh;

    return;
}


/*
 * restituisce il modo video corrente
 */
int MGL_getVideoMode(void)
{
    union REGS r;

	r.h.ah = 0x0F;
    int86(0x10, &r, &r);

/*
    MGL_getVideoAdapter();
	MGL_getVideoMonitor();
*/

    background = MGL_BLACK;
	
	MGL_video.mode       = r.h.al;
	MGL_video.text.cols  = r.h.ah;
	MGL_video.activepage = r.h.bh;

	switch (r.h.al) {

    /* TEXT40x25 */
	case 0x00:
		MGL_video.text.cols    = 40;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 360;
	    MGL_video.graphic.rows = 400;
		MGL_video.modetype     = MGL_TEXT_MODE;
        MGL_video.colortype    = MGL_MONOCHROME_MODE;
		MGL_video.colors       = 16;
		MGL_video.pages        = 8;
		MGL_video.ramaddress   = (char*)0xB800;
        break;
	case 0x01:
		MGL_video.text.cols    = 40;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 360;
	    MGL_video.graphic.rows = 400;
		MGL_video.modetype     = MGL_TEXT_MODE;
        MGL_video.colortype    = MGL_COLOR_MODE;
		MGL_video.colors       = 16;
		MGL_video.pages        = 8;
		MGL_video.ramaddress   = (char*)0xB800;
	    break;

    /* TEXT80x25 */
	case 0x07:
		MGL_video.text.cols    = 80;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 720;
	    MGL_video.graphic.rows = 400;
		MGL_video.modetype     = MGL_TEXT_MODE;
        MGL_video.colortype    = MGL_MONOCHROME_MODE;
		MGL_video.colors       = 2;
		MGL_video.pages        = 1;
		MGL_video.ramaddress   = (char*)0xB000;
		break;
	case 0x02:
		MGL_video.text.cols    = 80;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 720;
	    MGL_video.graphic.rows = 400;
		MGL_video.modetype     = MGL_TEXT_MODE;
        MGL_video.colortype    = MGL_MONOCHROME_MODE;
		MGL_video.colors       = 16;
		MGL_video.pages        = 8;
		MGL_video.ramaddress   = (char*)0xB800;
	    break;
	case 0x03:
		MGL_video.text.cols    = 80;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 720;
	    MGL_video.graphic.rows = 400;
		MGL_video.modetype     = MGL_TEXT_MODE;
        MGL_video.colortype    = MGL_COLOR_MODE;
		MGL_video.colors       = 16;
		MGL_video.pages        = 8;
		MGL_video.ramaddress   = (char*)0xB800;
		break;

	/* GRAPH320x200 */
	case 0x05:
		MGL_video.text.cols    = 40;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 320;
	    MGL_video.graphic.rows = 200;
		MGL_video.modetype     = MGL_GRAPHIC_MODE;
        MGL_video.colortype    = MGL_MONOCHROME_MODE;
		MGL_video.colors       = 4;
		MGL_video.pages        = 1;
		MGL_video.ramaddress   = (char*)0xB800;
		break;
	case 0x04:
		MGL_video.text.cols    = 40;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 320;
	    MGL_video.graphic.rows = 200;
		MGL_video.modetype     = MGL_GRAPHIC_MODE;
        MGL_video.colortype    = MGL_COLOR_MODE;
		MGL_video.colors       = 4;
		MGL_video.pages        = 1;
		MGL_video.ramaddress   = (char*)0xB800;
		break;
	case 0x0D:
		MGL_video.text.cols    = 40;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 320;
	    MGL_video.graphic.rows = 200;
		MGL_video.modetype     = MGL_GRAPHIC_MODE;
        MGL_video.colortype    = MGL_COLOR_MODE;
		MGL_video.colors       = 16;
		MGL_video.pages        = 8;
		MGL_video.ramaddress   = (char*)0xA000;
		break;
	case 0x13:
		MGL_video.text.cols    = 40;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 320;
	    MGL_video.graphic.rows = 200;
		MGL_video.modetype     = MGL_GRAPHIC_MODE;
        MGL_video.colortype    = MGL_COLOR_MODE;
		MGL_video.colors       = 256;
		MGL_video.pages        = 1;
		MGL_video.ramaddress   = (char*)0xA000;
        break;

	/* GRAPH640x200 */
	case 0x06:
		MGL_video.text.cols    = 80;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 640;
	    MGL_video.graphic.rows = 200;
		MGL_video.modetype     = MGL_GRAPHIC_MODE;
        MGL_video.colortype    = MGL_BW_MODE;
		MGL_video.colors       = 2;
		MGL_video.pages        = 1;
		MGL_video.ramaddress   = (char*)0xB800;
        break;
	case 0x0E:
		MGL_video.text.cols    = 80;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 640;
	    MGL_video.graphic.rows = 200;
		MGL_video.modetype     = MGL_GRAPHIC_MODE;
        MGL_video.colortype    = MGL_COLOR_MODE;
		MGL_video.colors       = 16;
		MGL_video.pages        = 4;
		MGL_video.ramaddress   = (char*)0xA000;
		break;

	/* GRAPH640x350 */
	case 0x0F:
		MGL_video.text.cols    = 80;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 640;
	    MGL_video.graphic.rows = 350;
		MGL_video.modetype     = MGL_GRAPHIC_MODE;
        MGL_video.colortype    = MGL_MONOCHROME_MODE;
		MGL_video.colors       = 2;
		MGL_video.pages        = 2;
		MGL_video.ramaddress   = (char*)0xA000;
		break;
	case 0x10:
		MGL_video.text.cols    = 80;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 640;
	    MGL_video.graphic.rows = 350;
		MGL_video.modetype     = MGL_GRAPHIC_MODE;
        MGL_video.colortype    = MGL_COLOR_MODE;
		MGL_video.colors       = 16;
		MGL_video.pages        = 2;
		MGL_video.ramaddress   = (char*)0xA000;
		break;

	/* GRAPH640x480 */
	case 0x11:
		MGL_video.text.cols    = 80;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 640;
	    MGL_video.graphic.rows = 480;
		MGL_video.modetype     = MGL_GRAPHIC_MODE;
        MGL_video.colortype    = MGL_MONOCHROME_MODE;
		MGL_video.colors       = 2;
		MGL_video.pages        = 1;
		MGL_video.ramaddress   = (char*)0xA000;
		break;
	case 0x12:
		MGL_video.text.cols    = 80;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 640;
	    MGL_video.graphic.rows = 480;
		MGL_video.modetype     = MGL_GRAPHIC_MODE;
        MGL_video.colortype    = MGL_COLOR_MODE;
		MGL_video.colors       = 16;
		MGL_video.pages        = 1;
		MGL_video.ramaddress   = (char*)0xA000;
		break;

	default:
		MGL_video.mode         = 0x03;
		MGL_video.text.cols    = 80;
	    MGL_video.text.rows    = 25;
		MGL_video.graphic.cols = 720;
	    MGL_video.graphic.rows = 400;
		MGL_video.modetype     = MGL_TEXT_MODE;
        MGL_video.colortype    = MGL_COLOR_MODE;
		MGL_video.colors       = 16;
		MGL_video.pages        = 8;
		MGL_video.ramaddress   = (char*)0xB800;
		break;
	}

    return MGL_video.mode;
}


/*
 * restituisce l'adattatore video attivo
 */
int MGL_getVideoAdapter(void)
{
    union REGS r;

	r.h.ah = 0x1A;
	r.h.ah = 0;

	int86(0x10, &r, &r);

    switch (r.h.bl) {
    case 0x00:
	case 0x01:
	case 0x02:
        MGL_video.adapter = r.h.bl;
	    break;
    case 0x04:
	case 0x05:
        MGL_video.adapter = MGL_EGA_ADAPTER;
	    break;
	case 0x06:
        MGL_video.adapter = MGL_PGA_ADAPTER;
	    break;
    case 0x07:
	case 0x08:
        MGL_video.adapter = MGL_VGA_ADAPTER;
	    break;
    case 0x0A:
	case 0x0B:
	case 0x0C:
        MGL_video.adapter = MGL_MCGA_ADAPTER;
	    break;
    default:
		MGL_video.adapter = MGL_UNKNOW_ADAPTER;
    }

    return r.h.bl;
}


/*
 * restituisce il monitor video attivo
 */
int MGL_getVideoMonitor(void)
{
    union REGS r;

	r.h.ah = 0x1A;
	r.h.ah = 0;

	int86(0x10, &r, &r);

    switch (r.h.bl) {
    case 0x00:
		MGL_video.monitor = MGL_NO_MONITOR;
	    break;
	case 0x01:
	case 0x05:
	case 0x07:
	case 0x0B:
		MGL_video.monitor = MGL_MONOCHROME_MONITOR;
	    break;
	case 0x02:
	case 0x04:
	case 0x06:
	case 0x08:
	case 0x0A:
	case 0x0C:
		MGL_video.monitor = MGL_COLORS_MONITOR;
	    break;
    default:
		MGL_video.monitor = MGL_UNKNOW_ADAPTER;
    }

    return r.h.bl;
}


/*
 * imposta la pagina video attiva
 */
void MGL_setActivePage(int page)
{
    union REGS r;

    MGL_video.activepage = page&(MGL_video.pages-1);

    r.h.ah = 0x05;
	r.h.al = page;

    int86(0x10, &r, &r);

    return;
}


/*
 * effettua lo scroll verso l'alto dell'area specificata
 */
void MGL_scrollUp(int rows, int tlrow, int tlcol, int brrow, int brcol, int color)
{
    union REGS r;

	r.h.ah = 0x06;
	r.h.al = rows;
	r.h.ch = tlrow;
	r.h.cl = tlcol;
	r.h.dh = brrow;
	r.h.dl = brcol;
	r.h.bh = (MGL_video.modetype==MGL_GRAPHIC_MODE? color&(MGL_video.colors-1) : ((color&(MGL_video.colors-1))<<4));
	int86(0x10, &r, &r);

    return;
}


/*
 * effettua lo scroll verso il basso dell'area specificata
 */
void MGL_scrollDown(int rows, int tlrow, int tlcol, int brrow, int brcol, int color)
{
    union REGS r;

	r.h.ah = 0x07;
	r.h.al = rows;
	r.h.ch = tlrow;
	r.h.cl = tlcol;
	r.h.dh = brrow;
	r.h.dl = brcol;
	r.h.bh = (MGL_video.modetype==MGL_GRAPHIC_MODE? color&(MGL_video.colors-1) : ((color&(MGL_video.colors-1))<<4));
	int86(0x10, &r, &r);

    return;
}


/*
 * imposta la posizione corrente del cursore nella pagina video specificata
 */
void MGL_setCursorPosition(int col, int row, int page)
{
    union REGS r;

    r.h.ah = 0x02;
    r.h.bh = page&(MGL_video.pages-1);
	r.h.dl = col;
    r.h.dh = row;

    if (col<0) r.h.dl = 0;
	if (col>=MGL_video.text.cols) r.h.dl = MGL_video.text.cols-1;
	if (row<0) r.h.dh = 0;

    int86(0x10, &r, &r);

    return;
}


/*
 * restituisce la posizione corrente del cursore nella pagina video
 * specificata
 */
void MGL_getCursorPosition(int *col, int *row, int page)
{
    union REGS r;

    r.h.ah = 0x03;
    r.h.bh = page&(MGL_video.pages-1);

    int86(0x10, &r, &r);

	*col = r.h.dl;
    *row = r.h.dh;

    return;
}


/*
 * imposta la dimensione del cursore
 */
void MGL_setCursorDimension(int size)
{
    union REGS r;

    r.h.ah = 0x01;
	r.h.ch = size&15;
    r.h.cl = 15;

    int86(0x10, &r, &r);

    return;
}


/*
 * restituisce la corrente dimensione del cursore
 */
int MGL_getCursorDimension(void)
{
    union REGS r;

    r.h.ah = 0x03;
    r.h.bh = MGL_video.activepage;

    int86(0x10, &r, &r);

    return r.h.ch;
}


/*
 * restituisce il carattere e l'attributo colore presenti alla posizione
 * corrente del cursore
 */
char MGL_getChar(int* fgcolor, int* bgcolor, int page)
{
    union REGS r;

    r.h.ah = 0x08;
    r.h.bh = page&(MGL_video.pages-1);

    int86(0x10, &r, &r);

    *fgcolor = r.h.ah&15;
    *bgcolor = (r.h.ah>>4);

    return r.h.al;
}


/*
 * scrive il carattere con gli attributi specificati
 */
void MGL_writeChar(char ch, int fgcolor, int bgcolor, int page)
{
    union REGS r;

    r.h.ah = 0x09;
	r.h.al = ch;
    r.h.bh = (MGL_video.mode==MGL_GRAPH320x200x256? bgcolor : page&(MGL_video.pages-1));
	r.h.bl = fgcolor + (MGL_video.modetype==MGL_GRAPHIC_MODE? (background<<4)|128 : (bgcolor<<4));
	r.x.cx = 1;

	int86(0x10, &r, &r);
}


/*
 * scrive il pixel con gli attributi specificati
 */
void MGL_writePixel(int col, int row, int color, int page)
{
    union REGS r;

    if (MGL_video.modetype != MGL_GRAPHIC_MODE) return;

    r.h.ah = 0x0C;
	r.h.al = color&15;
    r.h.bh = page&(MGL_video.pages-1);

	r.x.cx = col;
	r.x.dx = row;

	if (col<0) r.x.cx = 0;
	if (col>=MGL_video.graphic.cols) r.x.cx = MGL_video.graphic.cols-1;
	if (row<0) r.x.dx = 0;
	if (row>=MGL_video.graphic.rows) r.x.dx = MGL_video.graphic.rows-1;

	int86(0x10, &r, &r);
}


/*
 * restituisce l'attributo colore del pixel alla posizione specificata
 */
int MGL_getPixel(int col, int row, int page)
{
    union REGS r;

    if (MGL_video.modetype != MGL_GRAPHIC_MODE) return MGL_BLACK;

	r.h.ah = 0x0D;
    r.h.bh = page&(MGL_video.pages-1);

	r.x.cx = col;
	r.x.dx = row;

	if (col<0) r.x.cx = 0;
	if (col>=MGL_video.graphic.cols) r.x.cx = MGL_video.graphic.cols-1;
	if (row<0) r.x.dx = 0;
	if (row>=MGL_video.graphic.rows) r.x.dx = MGL_video.graphic.rows-1;

    int86(0x10, &r, &r);

    return r.h.al;
}


/*
 * restituisce il codice di scansione del tasto premuto
 */
char MGL_readKey(char* skey)
{
    union REGS r;

	r.h.ah = 0x00;

    int86(0x16, &r, &r);

    *skey = (char)(r.x.ax>>8);

	return (char)r.x.ax;
}



/* * * * Routines Derivate * * * */


/*
 * scrive la stringa con gli attributi specificati
 */
void MGL_writeString(const char *str, int fgcolor, int bgcolor, int page)
{
    int col, row;

	MGL_getCursorPosition(&col, &row, page);

	while (*str) {
		MGL_writeChar(*str, fgcolor, bgcolor, page);
        if (++col >= MGL_video.text.cols) {
			col = 0;
			if (++row >= MGL_video.text.rows) {
				row = MGL_video.text.rows-1;
				MGL_scrollUp(1, 0, 0, MGL_video.text.rows-1, MGL_video.text.cols-1, background);
			}
		}
		MGL_setCursorPosition(col, row, page);
		str++;
	}
}


/*
 * effettua il clear dell'intera area video settando il colore di fondo
 */
void MGL_clearScreen(int color)
{
    background = color;

	MGL_scrollUp(0, 0, 0, MGL_video.text.rows-1, MGL_video.text.cols-1, background);
    MGL_scrollUp(1, 0, 0, MGL_video.text.rows-1, MGL_video.text.cols-1, background);

    return;
}


/*
 * effettua il clear dell'intera area video nel modo corrente
 */
void MGL_cls(void)
{

    MGL_getVideoMode();
	MGL_clearScreen(background);
    MGL_setCursorPosition(0, 0, MGL_video.activepage);

	return;
}
