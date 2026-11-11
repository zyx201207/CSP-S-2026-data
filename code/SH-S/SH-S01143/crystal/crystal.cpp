#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[50005],s[50005],ans=1,l=1,now;
long long check(long long p,long long q,long long i)
{
	long long l=p,r=q;
	while(l<r)
	{
		long long mid=(l+r)/2;
		now=(i-mid)*a[i]-s[i-1]+s[mid-1];
		if(now<m)r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(long long i=2;i<=n;i++)s[i]=s[i-1]+a[i];
	for(long long i=1;i<=n;i++)
	{
		now=(i-l)*a[i]-s[i-1]+s[l-1];
		if(now<=m) ans=max(ans,i-l+1);
		else 
		{
			l=check(l,i,i);
			ans=max(ans,i-l+1);
		}
		
		
	}
	cout<<ans;
	return 0;
}
