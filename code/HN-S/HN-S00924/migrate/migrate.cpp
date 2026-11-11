#include<bits/stdc++.h>
#define int __int128
using namespace std;
long long c,t,n,d;
int x[2000005],dp[5005][5005],g[5005][5005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		{
			long long a;
			cin>>a;
			x[i]=a;
		}
		if(c<=6)
		{
			for(long long i=1;i<=n;i++)
			{
				dp[i][i]=0;
				for(long long j=i+1;j<=n;j++)
				{
					long long now=lower_bound(x+1,x+n+1,x[j]-d)-x;
					if(x[j]-d>x[j-1])dp[i][j]=2e36;
					else dp[i][j]=1+dp[i][now];
					if(dp[i][j]==2e36)g[i][j]=0;
					else g[i][j]=1;
				}
//				cout<<"\n";
			}
			for(long long k=1;k<=n;k++)
				for(long long u=1;u<=k;u++)
					for(long long v=k;v<=n;v++)
					{
						int now=lower_bound(x+1,x+n+1,(__int128)x[v]-d)-x;
						if(dp[u][v]==dp[u][k]+dp[k][v]&&k!=now)g[u][v]+=g[u][k]*g[k][v];
					}
			int ans=0;
			for(long long u=1;u<=n;u++)
				for(long long v=u;v<=n;v++)
					if(g[u][v]==2)ans++;
			cout<<(long long)ans<<"\n";
		}
	}
	return 0;
}
