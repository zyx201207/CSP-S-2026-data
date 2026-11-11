#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],sum[500010],MAX;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i-1,mid,ans;
		while(l<=r)
		{
			mid=l+r>>1;
			if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m)
			{
				ans=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		MAX=max(MAX,i-ans+1);
	}
	cout<<MAX;
	return 0;
}
//start: 14:39
//end: 14:46
