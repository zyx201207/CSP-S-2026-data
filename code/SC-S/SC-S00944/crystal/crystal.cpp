#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,mid=0,res=0;
		while(l<=r)
		{
			mid=l+r>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
			{
				res=mid;
				r=mid-1;
			}else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
/*
exp:100pts
writer:1419936 
*/