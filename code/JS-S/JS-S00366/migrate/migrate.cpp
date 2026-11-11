#include <bits/stdc++.h>
using namespace std;
int n,cnt[505][505];
long long x[2000005],d,dp[505][505],ans;
inline void myst()
{
	cin >> n >> d;
	for(int i=1;i<=n;i++) cin >> x[i];
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			cnt[i][i]=1;
			for(int j=i+1;j<=n;j++)
			{
				dp[i][j]=2e18;
				cnt[i][j]=0;
				for(int k=i;k<j;k++) if(x[j]-x[k]<=d)
				{
					if(dp[i][j]>dp[i][k]+1)
					{
						dp[i][j]=dp[i][k]+1;
						cnt[i][j]=cnt[i][k];
					}
					else if(dp[i][j]==dp[i][k]+1) cnt[i][j]+=cnt[i][k];
				}
				if(cnt[i][j]==2) ans++;
			}
			cout << ans;
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	feopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) myst();
}
