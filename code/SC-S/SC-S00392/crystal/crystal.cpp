#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	long long l=a[1],r=a[n]+m,maxn=a[1];
	long long sum=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		for(int i=1;i<=n;++i){
			if(a[i]<=mid)sum+=(mid-a[i]);
		}
		if(sum<=m){
			maxn=max(maxn,mid);
			l=mid+1;
		}
		else r=mid-1;
		sum=0;
	}
	for(int i=n;i>=1;--i){
		if(a[i]<=maxn){
			cout<<i;
			return 0;
		}
	}
	return 0;
} 