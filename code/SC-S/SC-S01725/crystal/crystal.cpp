#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long k[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=0;
	for(long long i=1;i<n;i++){
		ans+=a[n]-a[i];
		k[i]=a[n]-a[i];
	}
	if(ans<=m){
		cout<<n;
		return 0;
	}
	for(long long i=n-1;i>=0;i--){
		ans-=i*(k[i]-k[i+1]);
		if(ans<=m){
			cout<<i;
			return 0;
		} 
	}
	return 0;
}
/*
5 8
-3 -1 2 2 7

*/