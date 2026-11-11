#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long n,m,a[500005],ans,pfx[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pfx[i]=pfx[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]*i<=m+pfx[i])
		{
			ans=max(ans,i*1ll);
			continue;
		}
		long long l=1,r=i;
		while(l<r)
		{
			long long mid=(l+r)/2;
			if(a[i]*mid+pfx[i-mid]>m+pfx[i])r=mid;
			else l=mid+1;
		}
		ans=max(ans,l-1);
	}
	cout<<ans;
	return 0;
}
