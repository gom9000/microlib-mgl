#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#
#   ________        _________________.________
#  /  _____/  ____ /   _____/   __   \   ____/
# /   \  ___ /  _ \\_____  \\____    /____  \
#  \    \_\  (  <_> )        \  /    //       \
#   \______  /\____/_______  / /____//______  /
#          \/              \/               \/
# 
# Autore....: Alessandro Fraschetti
# Funzione..: makefile della libreria GoS'95 Micro Graphics Library
# Input.....: -
# Output....: library
# Note......: versione PC BIOS.
#
#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

 
SOURCES  = mglbios.c
OBJECTS  = $(SOURCES:.c=.o)
INCLUDES = .
LIBRARY  = mgl
DISTPATH = ../distrib
ANAME    = lib$(LIBRARY).a
CC       = gcc
AR       = ar
RM       = del
#CFLAGS   = -Wall -ansi -pedantic -O2 -I$(INCLUDES) -c
CFLAGS   = -Wall -pedantic -O2 -I$(INCLUDES) -c


$(ANAME): $(OBJECTS)
	$(AR) crs $(DISTPATH)/$(ANAME) $(OBJECTS)
	copy *.h ..\distrib\*.h

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)


.PHONY: clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(DISTPATH)/$(ANAME)
