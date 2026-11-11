#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100];
bool check(long long x){
	long long s=0;
	for(long long i=1;i<x;i++)s+=a[x]-a[i];
		if(s<=m)return 1;
	for(long long l=2,r=x+1;r<=n;l++,r++){
		s-=(a[r-1]-a[l-1]);
		s+=(x-1)*(a[r]-a[r-1]);
		if(s<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<r){
		long long mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
