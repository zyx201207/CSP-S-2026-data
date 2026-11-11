#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
long long check(long long x)
{
	long long ans=0,minn=1e18;
	for(long long i=1;i<=x;i++) ans+=a[i];
	minn=min(minn,x*a[x]-ans);
	for(long long i=x+1;i<=n;i++) 
	{
		ans+=a[i];
		ans-=a[i-x];
		minn=min(minn,x*a[i]-ans);
	}
	return minn<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
} 
