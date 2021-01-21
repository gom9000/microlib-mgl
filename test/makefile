#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#
#   ________        _________________.________
#  /  _____/  ____ /   _____/   __   \   ____/
# /   \  ___ /  _ \\_____  \\____    /____  \
#  \    \_\  (  <_> )        \  /    //       \
#   \______  /\____/_______  / /____//______  /
#          \/              \/               \/
# 
# Autore....: Alessandro Fraschetti
# Funzione..: makefile per test della libreria mgl
# Input.....: -
# Output....: exec
# Note......:
#
#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#


SOURCES  = test.c
OBJECTS  = $(SOURCES:.c=.o)
EXEC     = $(OBJECTS:.o=.exe)
INCLUDES = ../distrib
LIBNAME  = mgl
LIBPATH  = ../distrib
CC       = gcc
RM       = rm
CFLAGS   = -Wall -pedantic -O2 -I$(INCLUDES) -c


$(EXEC): $(OBJECTS)
	$(CC) -o $(EXEC) $(OBJECTS) -L$(LIBPATH) -l$(LIBNAME)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)


.PHONY: clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(EXEC)