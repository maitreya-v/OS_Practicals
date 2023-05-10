#include<iostream>
using namespace std;

int main()
{
     int n=20;

    int page_references[20]={7, 0, 1, 2,
               0, 3, 0, 4, 2, 3, 0, 3, 2, 1,
               2, 0, 1, 7, 0, 1};
    // int page_references[11]={
    //     1,2,3,4,2,1,5,3,2,4,6
    // };
    int page_references_size=n;
    int page_frames = 3;
    int page_faults = 0;
    int frames[page_frames] = {-1, -1, -1}; // initialize frames with -1

    for(int i=0;i<n;i++){
        int inframe=0;
        for(int j=0;j<page_frames;j++){
            if(frames[j]==page_references[i]){
                inframe=1;
                break;
            }
        }
        if(inframe==0){
            inframe=0;
            int farthest_distance=0;
            int farthest_index=0;

            for(int j=0;j<page_frames;j++){
                int distance=0;
                for(int k=i-1;k>=0;k--){
                    if(frames[j]==page_references[k]){
                        distance=i-k;
                        break;
                    }
                }
                if(distance>=farthest_distance){
                    farthest_distance=distance;
                    farthest_index=j;  
                }
            }

            if(page_faults<page_frames){
                frames[page_faults] = page_references[i];
            }
            else{
            frames[farthest_index]=page_references[i];
            }
            page_faults++;
            // cout<<inframe<<endl;
        }
        for(int j=0;j<page_frames;j++){
            cout<<frames[j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Page faults are "<<page_faults<<endl;
    return 0;
}