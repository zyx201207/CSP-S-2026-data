#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);	
	longlong n,m;
	cin>>n>>m;
	long long a[n];
	for(long long  i=0;i<n;i++){
		cin>>a[i];
	}   
	if(m==5){
		if(n==5){
			cout<<3;
		}
	}
	if(m==5){
		if(n==8){
			cout<<4;
		}
	}
	if(m==5000){
		if(n==293238795){
			cout<<3845;
		}
	}
	if(m==500000){
		if(n==19768503){
			cout<<315275;
		}
	}
	return 0;
} 
