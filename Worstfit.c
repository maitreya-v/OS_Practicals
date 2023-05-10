#include<stdio.h>
#include<stdlib.h>


int main(){

    // m is blocksize array
    // n is processsize array
    int m,n;
    printf("Enter the block size\n");
    scanf("%d",&m);
    
    printf("Enter the prcoess size\n");
    scanf("%d",&n);

    int processSize[n];
    int blockSize[m];

    printf("Enter the values for block size");

    for(int i=0;i<m;i++){
        printf("Value%d ",i);
        scanf("%d",&blockSize[i]);
    }

    printf("Enter the values for process size");

    for(int i=0;i<n;i++){
        printf("Value%d ",i);
        scanf("%d",&processSize[i]);
    }

    // allocation array is equal to the size of process array

    int allocation[n];

    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }

    for(int i=0;i<n;i++){
        int wstInd=-1;
        for(int j=0;j<m;j++){
            if(blockSize[j]>=processSize[i]){
                
                if(wstInd==-1){
                    wstInd=j;
                }
                else if(wstInd!=-1){
                    if(blockSize[wstInd]<blockSize[j]){
                        wstInd=j;
                    }
                }

            }
        }
    
    if(wstInd!=-1){
        allocation[i]=wstInd;
        blockSize[wstInd]-=processSize[i];
    }

    }

    for(int i=0;i<n;i++){
        printf("Process id %d\t\t",i+1);
        printf("Allocation index %d",allocation[i]+1);
        printf("\n");
    }

    return 0;
}