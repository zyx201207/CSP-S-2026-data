#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
long long check(long long len){
	long long minn=1e18;
	for(int i=1;i+len-1<=n;i++) minn=min(minn,a[i+len-1]*len-sum[i+len-1]+sum[i-1]);
	return minn;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	long long l=0,r=n;
	while(l<r){
		long long mid=(l+r+1)/2;
		if(check(mid)>m) r=mid-1;
		else l=mid;
	}
	cout<<l;
	return 0; 
} 
