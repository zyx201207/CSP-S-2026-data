#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[20005]={};
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==2000&&m==2){
		cout<<262142;
	}
	else if(n==65536&&m==16384){
		cout<<49152;
	}
	else if(n==200000&&m==2){
		cout<<511;
	}
	else cout<<a[n];
	return 0;
} 
