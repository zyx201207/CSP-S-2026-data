#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,a[maxn],f[maxn],ans,m;
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
	for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]*i-f[i]<=m)
		{
			ans=max(ans,i);
			continue;
		}
		int l=1,r=i,k=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(f[i]-f[mid-1])<=m)
			{
				k=i-mid+1;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,k);
	}
	cout<<ans;
	return 0; 
} 
