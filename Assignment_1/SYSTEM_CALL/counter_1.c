#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
 int fileDetials,size;
 char *ptr=(char *)calloc(50,sizeof(char));
 fileDetials=open("file.txt",O_RDONLY);
 int inword;
 if(fileDetials<0)
    {
 perror("Error:");
 exit(1);
    }
 size=read(fileDetials,ptr,50);
 ptr[size]="\0";
 int words=0,count=0,countLine=0,loop;


 for(loop=0;loop<strlen(ptr);loop++)
    {
 if(ptr ==' '|| ptr=='\t'|| ptr=='\0')
            {
 if(inword)
                {
 inword=0;
 words++;
                }
            }
 if(ptr[loop]=='\n')
        {
 countLine++;
        }
 else 
 words=1;
    }
 printf("\nTotal no lines %d\n Total words %d\n Total characters: %d\n",countLine,words,loop);
 close(fileDetials);
}