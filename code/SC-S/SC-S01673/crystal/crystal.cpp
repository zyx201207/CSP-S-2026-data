#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],cnt=0;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,ans=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) ans=mid,r=mid-1;
			else l=mid+1;
		}
		cnt=max(cnt,i-ans+1);
	}
	cout<<cnt;
	return 0;
}