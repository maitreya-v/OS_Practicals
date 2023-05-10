#include<iostream>
using namespace std;

int main()
{
     int n=20;

    int page_references[20]={7, 0, 1, 2,
               0, 3, 0, 4, 2, 3, 0, 3, 2, 1,
               2, 0, 1, 7, 0, 1};
    int page_references_size=n;
    int page_frames = 3;
    int page_faults = 0;
    int frames[page_frames] = {-1, -1, -1}; // initialize frames with -1
    int counts[page_frames] = {0,0,0}; // initialize frames with -1

    for(int i=0;i<n;i++){
        int inframe=0;
        for(int j=0;j<page_frames;j++){
            if(frames[j]==page_references[i]){
                inframe=1;
                counts[j]++;
                break;
            }
        }
        if(inframe==0){
            inframe=0;

            for(int x=0;x<page_frames;x++){
                if(frames[x]==-1){
                    inframe=1;
                    frames[x]=page_references[i];
                    page_faults++;
                    break;
                }
            }

            if(inframe==0){
                int least_distance=n+1;
            int least_index=n+1;

            int min=page_frames-1;
                for(int k=0;k<page_frames;k++){
                    if(counts[min]>counts[k]){
                        min=k;
                    }
            }
            frames[min]=page_references[i];
            counts[min]=0;
            page_faults++;
            }
            // counts[]=0;
        }

        
        cout<<"Frames"<<endl;
                for(int i=0;i<page_frames;i++){
            cout<<frames[i]<<" ";
        }
        cout<<endl;
        cout<<"Counts"<<endl;
                for(int i=0;i<page_frames;i++){
            cout<<counts[i]<<" ";
        }
        cout<<endl;
    }
    cout<<page_faults<<endl;
    return 0;
}