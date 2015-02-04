CC=gcc
CPFLAGS=-g -Wall -lpthread
LDFLAGS= -lpcap

SRC= portScanner.c portScanner_functions.c 
OBJ=$(SRC:.c=.o)
BIN=portScanner

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CPFLAGS) $(LDFLAGS) -o $(BIN) $(OBJ) 


%.o:%.c
	$(CC) -c $(CPFLAGS) -o $@ $<  

$(SRC):

clean:
	rm -rf $(OBJ) $(BIN)
