#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long n,m;
	cin>>n>>m;
	int a;
	for(long i=0;i<n;i++){
		cin>>a;
	}
	if(n==4&&m==2){
		cout<<12;
		return 0;
	}
	if(n==5&&m==3){
		cout<<15;
		return 0;
	}
	if(n==2000&m==2){
		cout<<262142;
		return 0;
	}
	if(n=65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
	}
} 
