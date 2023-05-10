#include<bits/stdc++.h>
using namespace std;


int main(){
int n=8;
     int arr[n] = { 176, 79, 34, 60, 92, 11, 41, 114 };
     int head = 50;
     int curr_pos;
     int seek_time=0;
     vector<int> v;
     for(int i=0;i<n;i++){
      curr_pos=arr[i];
      
      seek_time=seek_time+abs(curr_pos-head);
    // sequence is
    v.push_back(curr_pos);
      head=curr_pos;


     }
     cout<<"The seek time is "<<seek_time<<endl;
     for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
     }
    return 0;
}