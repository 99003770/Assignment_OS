#include <unistd.h> 
#include <stdio.h> 
#include <sys/types.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
int main() 
{ 
    int Fd; 
    char *myfifo = "/tmp/myfifo"; 
    mkfifo(myfifo, 0666); 
    char Input1[200], input2[200]; 
    while (1) 
    { 
     Fd = open(myfifo,O_RDONLY); 
     read(Fd, Input1, 100); 
     printf("Client2: %s \n", Input1); 
     close(Fd); 
     Fd = open(myfifo,O_WRONLY); 
     fgets(input2, 100, stdin); 
     write(Fd, input2, strlen(input2)+1); 
     close(Fd); 
    } 
    return 0; 
}