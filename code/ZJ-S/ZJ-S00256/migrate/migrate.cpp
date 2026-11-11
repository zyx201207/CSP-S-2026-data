#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
int f[5005][5005];
int g[5005][5005];
void solve(void)
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=d)
			{
				f[i][j]=1;
				g[i][j]=1;
			}
			else
			{
				f[i][j]=0;
				g[i][j]=2e18;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i+1;k<=j-1;k++)
			{
				if(a[j]-a[k]<=d&&f[i][k]>0)
				{
					if(g[i][j]==g[i][k]+1)
					{
						f[i][j]+=f[i][k];
					}
					else if(g[i][j]>g[i][k]+1)
					{
						g[i][j]=g[i][k]+1;
						f[i][j]=f[i][k];
					}
				}
			}
			ans+=(f[i][j]==2);
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int RP,T;
	cin>>RP>>T;
	RP++;
	while(T--)
	{
		solve();
	}
	return 0;
}

