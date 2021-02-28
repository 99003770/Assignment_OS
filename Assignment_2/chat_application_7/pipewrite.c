#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{
    int Fd; 
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    char Input1[200], Input2[200];
    while (1)
    {
    Fd = open(myfifo, O_WRONLY);
    fgets(Input2, 100, stdin);
    write(Fd, Input2, strlen(Input2)+1);
    close(Fd);
    read(Fd, Input1, sizeof(Input1));
    printf("client1: %s\n", Input1);
    close(Fd);
    }
return 0;
}