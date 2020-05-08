CFLAGS 	= -g -Wall
LIB 	= -lncurses
CC 		= g++

#COMPILA Y EJECUTA
todo: menu ejecutar

#COMPILA EL PROGRAMA PRINCIPAL	
menu: menu.o
	$(CC) $(CFLAGS) -o $@ menu.o $(LIB)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<	

ejecutar:
	./menu

clean:
	rm -f menu *.o