#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[7]={82,170,43,140,24,16,190};
    int head=50;
    int n=7;
    int curr;
    int seek_time=0;
    int min_index;
    int min_distance;

    for(int i=0;i<n;i++){
        min_distance=INT_MAX;
        for(int j=0;j<n;j++){
            if(abs(head-arr[j])<min_distance){
                min_distance=abs(head-arr[j]);
                min_index=j;
            }
        }
        seek_time+=abs(head-arr[min_index]);
        printf("%d ",seek_time);
        head=arr[min_index];
        arr[min_index]=INT_MAX;
    }
    // printf("Total seek time is %d\n",seek_time);

    return 0;
}