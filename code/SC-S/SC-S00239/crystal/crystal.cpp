#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],sum_d[500005];
bool check(long long k){
	long long ans=0;
	for(long long i=n;i>n-k+1;--i){
		ans+=d[i]*(k-n+i-1);
	}
	if(ans<=m) return true;
	for(long long i=n-1;i>=k;--i){
		ans+=sum_d[i]-sum_d[i-k+1]-k*d[i+1];
		if(ans<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;++i){
		d[i]=sum_d[i]=a[i]-a[i-1];
		sum_d[i]+=sum_d[i-1];
	}
	long long l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		//cout<<mid<<' '<<check(mid)<<endl; 
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}