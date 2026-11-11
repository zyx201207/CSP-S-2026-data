#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],pfA,pfa[500010],pfB,x,pfb[500010],b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]!=a[i-1]+1){
			pfA=1;
		}
	}

	if(pfA==0){
		for(int i=1;i<=n;++i){
			pfa[i]=pfa[i-1]+i;
		}
	
	if(m>=pfa[n]){
		cout<<n;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(pfa[i]>=m){
			cout<<i;
			return 0;
		}
		else if(pfa[i]==m){
			cout<<i+1;
			return 0;
		}
		else if(pfa[i]<m&&m<pfa[i+1]){
			cout<<i+1;
			return 0;
		}
	}
}
	x=a[2]-a[1];
	pfb[1]=x;
	for(int i=1;i<=n;i++){
		pfb[i]=pfb[i-1]+x*i;
		b=a[i]-a[i-1];
		if(i>1&&b!=x){
			pfB=1;
		}
	}
	if(pfB==0){
		if(m>=pfb[n]){
			cout<<n;
			return 0;
		}
		for(int i=1;i<n;i++){
			if(pfb[i]>m){
				cout<<i;
				return 0;
			}
			else if(pfb[i]==m){
				cout<<i+1;
				return 0;
			}
			else if(pfb[i]<m&&m<pfb[i+1]){
				cout<<i+1;
				return 0;
			}
		}
	}
	
	return 0;
}
