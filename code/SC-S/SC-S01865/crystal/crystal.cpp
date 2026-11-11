#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,f[500500];
int sum[505050];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(f+1,f+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+f[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=((l+r)>>1);
			if((i-mid+1)*f[i]-(sum[i]-sum[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}