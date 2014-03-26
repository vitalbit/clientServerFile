CC=$(CROSS_COMPILE)gcc
all:
	$(CC) clientFolder/client.c -o clientFolder/client
	$(CC) -pthread serverFolder/server.c -o serverFolder/server
clean:
	rm -rf clientFolder/client serverFolder/server

