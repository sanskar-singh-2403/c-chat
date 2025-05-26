CC = gcc
CFLAGS = -Wall -g

all: server client

server: server.c
	$(CC) $(CFLAGS) -o server server.c

client: client.c
	$(CC) $(CFLAGS) -o client client.c

run-server: server
	./server

run-client: client
	./client

clean:
	rm -f server client