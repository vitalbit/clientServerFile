CC=$(CROSS_COMPILE)gcc
all:
	$(CC) client.c -o client
	$(CC) server.c -o server
clean:
	rm -rf * client
	rm -ff * server

