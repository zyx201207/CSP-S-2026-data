#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100005],q[100005],ans=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			int sum=0;
			for(int k=l;k<=r;k++)
			{
				sum=0;
				for(int w=l;w<=r;w++) sum+=abs(a[k]-a[w]);
				if(sum<=m) 
				{
					ans=max(r-l+1,ans);
					break;
				}
			}
		}
	}
	cout<<ans;
} 
