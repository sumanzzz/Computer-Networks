#include <iostream>
#include <vector>
using namespace std;
void receiver(vector<int>frame);
void sender(){
    int n;
    vector<int> data;
    vector<int> frame;
    vector<int> add = {0,1,1,1,1,1,1,0};

    cout<<"Enter the number of bits:"<<endl;
    cin>>n;
    cout<<"Enter  "<<n<<" bits:"<<endl;
    for(int i=0;i<n;i++){
        int dig;
        cin>>dig;
        data.push_back(dig);
    }
    frame.insert(frame.end(),add.begin(),add.end());

    int cnt = 0;

    for(int i=0;i<n;i++){
        if(cnt==5){
            frame.push_back(0);
            cnt = 0;
        }
        frame.push_back(data[i]);
        if(data[i]==1) cnt++;
    }
    frame.insert(frame.end(),add.begin(),add.end());

    cout<<"Sent Frame:";
    for(int i=0;i<frame.size();i++){
        cout<<frame[i]<<" ";
    }
    cout<<endl;
    receiver(frame);

}
void receiver(vector<int> frame){
    vector<int> data;
    int cnt = 0;
    for(int i=8;i<frame.size()-8;i++){
        if(frame[i]==1){
            data.push_back(frame[i]);
            cnt++;
        }
        if(frame[i]==0){
            if(cnt ==5){
                cnt = 0;
            }
            else data.push_back(frame[i]);
        }
    }
    cout<<"Data received is:";
    for(int bit : data) cout<<bit<<" ";
    cout<<endl;

}
int main()
{
    sender();
    return 0;
}
