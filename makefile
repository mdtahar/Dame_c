FICHIERS =piece.o liste.o liste_conf.o partie.o main.o
CFLAGS =-ansi

all: $(FICHIERS) 
	gcc -g $(FICHIERS) -o Dame_exe
     
main.o: main.c partie.h
	gcc -c $(CFLAGS) main.c -o main.o
partie.o: partie.c partie.h
	gcc -c $(CFLAGS) partie.c -o partie.o
liste_conf.o: liste_conf.c liste_conf.h
	gcc -c $(CFLAGS) liste_conf.c -o liste_conf.o
liste.o: liste.c liste.h
	gcc -c $(CFLAGS) liste.c -o liste.o
piece.o: piece.c piece.h
	gcc -c $(CFLAGS) piece.c -o piece.o	

clean:
	rm dame_exe $(FICHIERS)
