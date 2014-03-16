#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

char message[] = "Hello there!\n";
char buf[sizeof(message)];

int main()
{
    int sock, r;
    struct sockaddr_in addr;
    char ip[100];
    char filename[1024];
    char content[1024];
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(1);
    }
    printf("Enter ip address: ");
    scanf("%s", ip);
    printf("Enter filename: ");
    scanf("%s", filename);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425); // или любой другой порт...
    addr.sin_addr.s_addr = inet_addr(ip);
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        exit(2);
    }
    send(sock, filename, sizeof(filename), 0);
    r = recv(sock, content, sizeof(content), 0);
    FILE *fp;
    fp = fopen("recvFile.txt", "w");
    fwrite(content, 1, r, fp);
    fclose(fp);
    close(sock);
    return 0;
}
