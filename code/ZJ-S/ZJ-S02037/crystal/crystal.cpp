#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005],i,Max,l,r,ans,mid;
bool check(long long x,long long y)
{
	long long ans=a[y]*(y-x)-f[y-1]+f[x-1];
	if(ans<=m)return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)f[i]=f[i-1]+a[i];
	for(i=1;i<=n;i++)
	{
		l=i,r=n;
		if(r-l+1<Max)break;
		while(l<=r)
	    {
		    mid=(l+r)/2;
		    if(!check(i,mid))r=mid-1;
		    else
		    {
		    	ans=mid;
		    	l=mid+1;
		    }
	    }
	    Max=max(Max,ans-i+1);
	}
	cout<<Max;
	return 0;
}
