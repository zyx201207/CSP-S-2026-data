#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
int n,m;
static inline bool check(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<x)sum+=x-a[i];
	}
	return sum<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=-1e12,r=1e12,ans;
	while(l<=r)
	{
		int mid = (l+r)>>1;
		if(check(mid))
		{
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=ans)res++;
	}
	cout<<res;
	return 0;
}
