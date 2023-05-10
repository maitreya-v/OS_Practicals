// #include<iostream>
// using namespace std;

// int main()
// {
//      int n=20;

//     int page_references[20]={7, 0, 1, 2,
//                0, 3, 0, 4, 2, 3, 0, 3, 2, 1,
//                2, 0, 1, 7, 0, 1};
//     int page_references_size=n;
//     int page_frames = 3;
//     int page_faults = 0;
//     int frames[page_frames] = {-1, -1, -1}; // initialize frames with -1

//     for(int i=0;i<n;i++){
//         int inframe=0;
//         for(int j=0;j<page_frames;j++){
//             if(frames[j]==page_references[i]){
//                 inframe=1;
//                 break;
//             }
//         }
//         if(inframe==0){
//             int least_distance=n+1;
//             int least_index=n+1;

//             for(int j=0;j<page_frames;j++){
//                 int distance=n+1;
//                 for(int k=i-1;k>=0;k--){
//                     if(frames[j]==page_references[k]){
//                         distance=i-k;
//                         break;
//                     }
//                 }
//                 if(distance<least_distance){
//                     least_distance=distance;
//                     least_index=j;  
//                 }
//             }
//             frames[least_index]=page_references[i];
//             page_faults++;
//         }
//     }
//     cout<<page_faults<<endl;
//     return 0;
// }



#include<iostream>
using namespace std;

int main()
{
    int arr[10]={0 q};
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}