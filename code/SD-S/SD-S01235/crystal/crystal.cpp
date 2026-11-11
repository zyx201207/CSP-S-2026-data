#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[500005],ans=0;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) 
	{
		sum[i]=sum[i-1]+a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int l=1,r=i,pos=i;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m)
			{
				pos=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
	
	
}

