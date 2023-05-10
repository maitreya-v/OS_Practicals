#include<bits/stdc++.h>
using namespace std;

#define MAX 200

int main(){
    int n, head, direction, i;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the requests: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the direction (1 for right, -1 for left): ");
    scanf("%d", &direction);
    int seek_time=0;
    sort(arr,arr+n);
    int curr_pos;
    if (direction == 1){
        for(int i=0;i<n;i++){
            if(arr[i]>=head){
                curr_pos=i;
                break;
            }
        }

        cout<<"Array test\n";
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }

        printf("Current head position: %d\n",head);


        for(int i=curr_pos;i<n;i++){
            seek_time+=abs(arr[i]-head);
            head=arr[i];
        }
        seek_time+=abs(arr[n-1]-(MAX-1));
        head=MAX-1;
        for(int i=curr_pos-1;i>=0;i--){
            seek_time+=abs(arr[i]-head);
            head=arr[i];
        }
        cout<<"Total seek time: "<<seek_time<<endl;
    }

    return 0;
}