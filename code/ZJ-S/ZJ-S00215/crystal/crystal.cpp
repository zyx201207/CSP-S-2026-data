#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long ans,a[N],s[N],n,m;
bool check(long long l,long long r){
	if(l==r)return 1;
	long long len=r-l;
	if(a[r]*len-s[r-1]+s[l-1]<=m)return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		long long l=1,r=i,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(check(mid,i))r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9   
*/