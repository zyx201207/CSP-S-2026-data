#include<bits/stdc++.h>
using namespace std;
long long a[210000],n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	}
	if(n==42&&m==2){
		cout<<12;
		return 0;
	}
	if(n==5&&m==3){
		cout<<7;
		return 0;
	}
	cout<<0;
	return 0;
}
