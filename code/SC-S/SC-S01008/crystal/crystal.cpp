#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long miku=0,teto=0,neru=0,n=0,m=0,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	miku=a[n/2+1];
	for(long long i=1;i<=n;i++){
		if(a[i]==miku){
			teto++;
		}
	}
	for(long long i=n/2;i>=1;i--){
		neru=miku-a[i];
		if(m>=neru){
			m-=neru;
			teto++;
		}
	}
	cout<<teto;
	return 0;
}