CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o mappingFunc.o playerMovement.o terminal.o newsleep.o
EXEC = traffic

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c mapping.h player.h terminal.h newsleep.h
	$(CC) $(CFLAGS) main.c -c

mappingFunc.o : mappingFunc.c mapping.h
	$(CC) $(CFLAGS) mappingFunc.c -c

playerMovement.o : playerMovement.c player.h mapping.h
	$(CC) $(CFLAGS) playerMovement.c -c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

newsleep.o : newsleep.c newsleep.h
	$(CC) $(CFLAGS) newsleep.c -c

clean :
	rm -f $(EXEC) $(OBJ)
