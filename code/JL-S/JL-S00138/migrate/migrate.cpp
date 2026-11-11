#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[2005][2005];
int dis[2005][2005];
int a[200005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		int n,d;
		scanf("%lld%lld",&n,&d);
		if(c<=6)
		{
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
						dis[i][j] = 0x3f3f3f3f3f3f3f3f;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(a[j]-a[i]<=d)
						dis[i][j] = dis[j][i] = 1,dp[i][j] = dp[j][i] = 1;
			for(int i=1;i<=n;i++) dis[i][i] = 0;
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++)
						dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			for(int i=1;i<=n;i++) dp[i][i] = 1;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=1;k<=n;k++)
						if(dis[i][k]+dis[k][j]==dis[i][j]&&k!=i&&k!=j)
							dp[i][j] += dp[i][k]*dp[k][j];
			//for(int i=1;i<=n;i++)
			//	for(int j=1;j<=n;j++) printf("dp %lld %lld = %lld\n",i,j,dp[i][j]);
			int ans = 0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(dp[i][j]==2)
						ans++;
			printf("%lld\n",ans);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dp[i][j] = 0;
		}
		else puts("0");
	}
}//24(172min)