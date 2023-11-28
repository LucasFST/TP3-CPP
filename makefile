CC = g++ -g -Wall -ansi -pedantic -std=c++11 #-DMAP
OBJETS = obj/Catalogue.o obj/TableauDynamique.o obj/Trajet.o obj/TrajetSimple.o obj/TrajetCompose.o obj/main.o
VALGRIND = ./valgrind

bin/exe : $(OBJETS)
	$(CC) $(OBJETS) -o bin/exe

obj/main.o : src/main.cpp src/Catalogue.h src/TableauDynamique.h src/Trajet.h src/TrajetSimple.h src/TrajetCompose.h
	$(CC) -c src/main.cpp -o obj/main.o

obj/Catalogue.o : src/Catalogue.h src/Catalogue.cpp src/TableauDynamique.h src/Trajet.h src/TrajetSimple.h src/TrajetCompose.h
	$(CC) -c src/Catalogue.cpp -o obj/Catalogue.o

obj/TableauDynamique.o : src/TableauDynamique.h src/TableauDynamique.cpp 
	$(CC) -c src/TableauDynamique.cpp -o obj/TableauDynamique.o

obj/Trajet.o : src/Trajet.h src/Trajet.cpp
	$(CC) -c src/Trajet.cpp -o obj/Trajet.o

obj/TrajetSimple.o : src/TrajetSimple.h src/TrajetSimple.cpp src/Trajet.h
	$(CC) -c src/TrajetSimple.cpp -o obj/TrajetSimple.o

obj/TrajetCompose.o : src/TrajetCompose.h src/TrajetCompose.cpp src/Trajet.h src/TableauDynamique.h src/TrajetSimple.h
	$(CC) -c src/TrajetCompose.cpp -o obj/TrajetCompose.o

clean : 
	rm -rf obj/*
	rm -rf bin/*

valgrind : exe
	$(VALGRIND) ./bin/exe

#TEST

bin/TTrajetSimple : obj/TTrajetSimple.o obj/TrajetSimple.o obj/Trajet.o
	$(CC) obj/TTrajetSimple.o obj/TrajetSimple.o obj/Trajet.o  -o bin/TTrajetSimple

obj/TTrajetSimple.o : src/Tests/TTrajetSimple.cpp src/Tests/TTrajetSimple.h src/TrajetSimple.h
	$(CC) -c src/Tests/TTrajetSimple.cpp -o obj/TTrajetSimple.o

bin/TTrajetCompose : obj/TTrajetCompose.o obj/TrajetCompose.o obj/Trajet.o obj/TableauDynamique.o obj/TrajetSimple.o
	$(CC) obj/TTrajetCompose.o obj/TrajetCompose.o obj/Trajet.o obj/TableauDynamique.o obj/TrajetSimple.o  -o bin/TTrajetCompose

obj/TTrajetCompose.o : src/Tests/TTrajetCompose.cpp src/Tests/TTrajetCompose.h src/TrajetCompose.h src/TableauDynamique.h
	$(CC) -c src/Tests/TTrajetCompose.cpp -o obj/TTrajetCompose.o