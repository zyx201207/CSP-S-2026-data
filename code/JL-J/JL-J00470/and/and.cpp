#include<iostream>
#include<string>
long long line[1000001];
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>line[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(line[i]<line[j]){
				int t=line[i];
				line[i]=line[j];
				line[j]=t;
			}
		}
	}
	cout<<line[m-1];
	return 0;
}
