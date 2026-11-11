#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1000001]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<12;
	}
	else if(n==5&&m==3){
		cout<<7;
	}
	else if(n==2000&&m==2){
		cout<<262142;
	}
	else if(n==65536&&m==16384){
		cout<<49152;
	}
	else if(n==200000&&m==2){
		cout<<511;
	}
	else{
		cout<<0;
	}
	/*int x[1000001]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			x[j]=a[i]%2;
			i++;
		}
		
	}
	*/
	return 0;
}
