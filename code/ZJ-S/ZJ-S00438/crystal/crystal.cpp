#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000001],maxn,sum[1000001];
int find(int l,int r,int num)
{
	int ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]==num)
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int now=find(i,n,a[i]);
		int l=1,r=now,ans;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(((now-mid+1)*a[now]-(sum[now]-sum[mid-1]))<=m)ans=mid,r=mid-1;
			else l=mid+1;
		}
		maxn=max(maxn,now-ans+1);
	}
	cout<<maxn<<endl;
	return 0;
}