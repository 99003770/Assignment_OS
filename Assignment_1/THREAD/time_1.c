#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int hour, minute, second, day, month, year;
    time_t now;
    time(&now);
    printf("Today is : %s", ctime(&now));
    struct tm *local = localtime(&now);
 
    hour = local->tm_hour;          
    minute = local->tm_min;         
    second = local->tm_sec;
    if (hour < 12)
    {  
        printf("Time is : %02d:%02d:%02d am\n", hour, minute, second);
    }
    else 
    { 
        printf("Time is : %02d:%02d:%02d pm\n", hour - 12, minute, second);
    }
    return 0;
}