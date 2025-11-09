//3.	Write a program for frame sorting technique used in buffers.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
#define DATA_SIZE 3

void bubbleSort(vector<pair<int,string>> &arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].first > arr[j+1].first){
                pair<int,string> temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    srand(time(0));
    string msg;
    cout<<"Enter a message:";
    getline(cin,msg);

    vector<string> msg_chunks;
    for(size_t i =0 ; i<msg.length();i += DATA_SIZE){
        msg_chunks.push_back(msg.substr(i,DATA_SIZE));
    }

    vector<pair<int,string>> frames;
    for(int i=0;i<(int)msg_chunks.size();i++){
        frames.push_back({i+1,msg_chunks[i]});
    }

    cout<<"Fragmented Frames:";
    for(auto &f : frames){
        cout<<"("<<f.first<<","<<f.second<<")";
    }
    cout<<endl;

    for(int i=0;i<(int)frames.size();i++){
        int j = rand() % frames.size();
        swap(frames[i],frames[j]);
    }
    cout<<"Shuffled frames:";
    for(auto &f :frames){
        cout<<"("<<f.first<<","<<f.second<<")";
    }
    cout<<endl;

    bubbleSort(frames);
    cout<<"Sorted frames:";
    for(auto &f :frames){
        cout<<"("<<f.first<<","<<f.second<<")";
    }
    cout<<endl;

    cout<<"Sorted Message:";
    for(auto &f : frames){
        cout<<f.second;
    }
    cout<<endl;
    return 0;
}

