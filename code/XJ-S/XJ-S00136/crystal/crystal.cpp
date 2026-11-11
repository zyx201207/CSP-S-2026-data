#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f1=0,f2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f1=1;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])f2=1;
	}
	if(!f1){
		long long tm=0,ta=1;
		while(tm+ta<=m){
			tm+=ta;
			ta++;
		}
		if(m==0)cout<<0;
		else if(ta<=n)cout<<ta;
		else cout<<n;
	}else if(!f2){
		int tmp=a[2]-a[1];
		long long tm=0,ta=0;
		while(tm+ta<=m){
			tm=tm+ta*tmp;
			ta++;
		}
		if(m<tmp)cout<<0;
		else if(ta<=n)cout<<ta;
		else cout<<n;
	}
	return 0;
}
