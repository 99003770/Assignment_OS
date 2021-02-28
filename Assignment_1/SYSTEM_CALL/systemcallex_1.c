#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fil,wil,nbytes;
	fil=open("file.txt",O_RDONLY);
	if(fil<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=100;
	char buf[maxlen];
	nbytes=read(fil,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	wil=open("write.txt",O_WRONLY|O_CREAT, 0666);
	if(wil<0)
	{
		perror("open");
		exit(1);
	}
	int len=strlen(buf);
	nbytes=	write(wil, buf, len);
	if(nbytes<0)
	{
		perror("write");
		exit(2);
	}
	printf("Copied,nbytes=%d\n",nbytes);
    close(fil);
    close(wil);
	return 0;	
}