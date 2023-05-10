#include<stdio.h>
#include<stdlib.h>

int mutex=1,full=0,empty=3,x=0;


int main(){

    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    int n;
   while(1){
     printf("1 for Producer, 2 for Consumer, 3 for exit\n");
    scanf("%d",&n);
    switch(n){
        case 1:
        if(mutex==1 && empty!=0){
            producer();
        }
        else{
            printf("Buffer is full\n");
        }
        break;
        case 2:
        if(mutex==1 && full!=0){
            consumer();
        }
        else{
            printf("Buffer is empty\n");
        }
        break;
        case 3:
        exit(0);
        break;
    }
   }
   return 0;
}

int wait(int s){
    return --s;
}

int signal(int s){
    return ++s;
}

void producer(){
    mutex=wait(mutex);
    x++;
    empty=wait(empty);
    full=signal(full);
    printf("Produced item %d\n",x);
    mutex=signal(mutex);
}

void consumer(){
    mutex=wait(mutex);
    x--;
    empty=signal(empty);
    full=wait(full);
    printf("Consumed item %d\n",x);
    mutex=signal(mutex);
}