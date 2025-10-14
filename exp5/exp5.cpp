#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	vector<int> div = {1,0,0,0,1,0};
	vector<int> data;
	vector<int> cdata ;
	cout<<"Enter the number of bits:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		int bit;
		cout<<"Enter  "<<i+1<<" bit :"<<endl;
		cin>>bit;
		data.push_back(bit);
	}
	int m = div.size();
	if ( n< m){
		cout<<"Invalid data"<<endl;
		exit(0);
	}
	cdata= data;
	for(int i = 0;i<m-1;i++){
			cdata.push_back(0);
	}
	for(int i=0;i<n;i++){
		if(cdata[i] == 1){
			for(int j = 0; j<m;j++){
				cdata[i+j] = cdata[i+j] ^ div[j];
			}
		}
	}
	for(int i=n;i<n+m-1;i++){
		data.push_back(cdata[i]);
	}
	cout<<"Data to be transmitted is :"<<endl;
	for(int bit : data){
		cout<<bit;
	}
	cout<<"\n";
		
	
		
	
	
	
}
