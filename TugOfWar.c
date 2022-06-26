#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX 22
#define MIN 7
#define RA_Exemplo 202010101

char a[88];
int x;
pthread_mutex_t buffer_mutex;

void *totheend(void *arg) {
    int n;
    while(1) {
        pthread_mutex_lock(&buffer_mutex);
        if(x+2 != 86){
            x++ ;
            a[x] = 'A';
            a[x+1] = 'B';
            a[x+2] = 'C';
            a[x-1] = '_';
            pthread_mutex_unlock(&buffer_mutex);
        }
        usleep((long) (drand48() * RA_Exemplo/89.0));
    }
}

void *tothestart(void *arg) {
    while(1) {
        pthread_mutex_lock(&buffer_mutex);
        if(x > 0){
            x-=1;
            a[x] = 'A';
            a[x+1] = 'B';
            a[x+2] = 'C';
            a[x+3] = '_';
        }
        pthread_mutex_unlock(&buffer_mutex);
        usleep((long) (drand48() * RA_Exemplo/89.0));
    }
}

int main(int argc, char **argv) {
    //Creation of array a with 88 positions.
    for(int i=0; i<88; i++){
        a[i] = '_';
    }
    a[42] = 'A';
    a[43] = 'B';
    a[44] = 'C';
    a[87] = '\0';
    //Defining the middle of the array as the start positions for the flag.
    x = 42;
    //Thread quantity draw
    srand48(time(0));
    int q1 = (int) (drand48()*(MAX - MIN + 1)) + MIN;
    int q2 = (int) (drand48()*(MAX - MIN + 1)) + MIN;
    //Starting the mutex
    pthread_mutex_init(&buffer_mutex, NULL);
    // Creating interleaved threads
    int k = 0;
    while(k < q1+q2){
        if(k<q1){
        pthread_t tr;
        pthread_create(&tr,NULL, tothestart, NULL);
        }
        if(k<q2){
        pthread_t tr;
        pthread_create(&tr,NULL, totheend, NULL);
        }
        k++;
    }

    // Main loop 
    int loop = 1;
    while(loop){
        system("clear");
        printf("tothestart: %d\ttotheend: %d\n \n", q1, q2);
        printf("\n");
        printf("%s\n", a);
        if(x == 0){
            loop = 0;
            printf("tothestart é a vencedora! \n");
        }
        if(x+2 == 86){
            loop = 0;
            printf("totheend é a vencedora! \n");
        }
        // As requested in the task, the main thread will sleep for a while so as not to overload the processing.
        sleep(0.5);
    }
}