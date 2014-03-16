CC=$(CROSS_COMPILE)gcc
all:
	$(CC) -pthread clientFolder/client.c -o clientFolder/client
	$(CC) -pthread serverFolder/server.c -o serverFolder/server
clean:
	rm -rf * clientFolder/client
	rm -ff * serverFolder/server

