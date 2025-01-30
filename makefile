rodriguezLorenzoA1: rodriguezLorenzoA1.o rodriguezLorenzoA1Main.o
	gcc rodriguezLorenzoA1.o rodriguezLorenzoA1Main.o -o rodriguezLorenzoA1

rodriguezLorenzoA1.o: rodriguezLorenzoA1.c
	gcc -Wall -std=c99 -c rodriguezLorenzoA1.c

rodriguezLorenzoA1Main.o: rodriguezLorenzoA1Main.c
	gcc -Wall -std=c99 -c rodriguezLorenzoA1Main.c

clean:
	rm *.o rodriguezLorenzoA1