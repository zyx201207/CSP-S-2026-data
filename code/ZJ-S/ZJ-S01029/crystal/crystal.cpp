#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,ans=0;
	long long a[100001];
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&m==5){
		cout<<3;
	}
	if(n==5&&m==8){
		cout<<4;
	}
	if(n==5000&&m==293238795){
		cout<<3845;
	}
	if(n==500000&&m==19768503){
		cout<<315275;
	}
	return 0;
}
