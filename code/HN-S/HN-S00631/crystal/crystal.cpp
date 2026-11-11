#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int sum[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int maxx=INT_MIN;
	for(int i=1;i<=n;++i)
	{
		int l=0;
		int r=i+1;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-sum[i]+sum[mid-1]<=m)
			{
				r=mid;
			}
			else
			{
				l=mid;
			}
		}
		maxx=max(maxx,i-r+1);
	}
	cout<<maxx;
	return 0;
}
