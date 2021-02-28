#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct data{
    int* arr;
    int thread_num;
} data;

int arraySize = 10;

void* halfSum(void* p)
{
    data* ptr = (data*)p;
    int n = ptr->thread_num;
    int* thread_sum = (int*) calloc(1, sizeof(int));
    
    if(n == 0){
        for(int i = 0; i < arraySize/2; i++)
            thread_sum[0] = thread_sum[0] + ptr->arr[i];
    }
    else{
        for(int i = arraySize/2; i < arraySize; i++)
            thread_sum[0] = thread_sum[0] + ptr->arr[i];
    } 
    pthread_exit(thread_sum);
}
int main(void)
{
    int* int_arr = (int*) calloc(arraySize, sizeof(int));
    for(int i = 0; i < arraySize; i++)
        int_arr[i] = i + 1;
    data thread_data[2];
    thread_data[0].thread_num = 0;
    thread_data[0].arr = int_arr;
    thread_data[1].thread_num = 1;
    thread_data[1].arr = int_arr;
    pthread_t tid[2];
    pthread_create(&tid[0], NULL, halfSum, &thread_data[0]);
    pthread_create(&tid[1], NULL, halfSum, &thread_data[1]);
    int* sum0;
    int* sum1;
    pthread_join(tid[0], (void**)&sum0);
    pthread_join(tid[1], (void**)&sum1);
    
    printf("Sum of whole array = %i\n", *sum0 + *sum1);
    return 0;
}
