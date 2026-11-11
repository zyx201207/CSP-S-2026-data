#include<bits/stdc++.h>
using namespace std;

long long a[5005];
int dp[5005][5005],f[5005][5005];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		long long n,d;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				dp[i][j] = 1e9;
				f[i][j] = 0;
				if(a[j] - a[i] <= d)
				{
					dp[i][j] = 1;
					f[i][j] = 1;
				}
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				for(int k = i + 1;k <= j - 1;k++)
				{
					if(dp[i][k] + dp[k][j] < dp[i][j])
					{
						dp[i][j] = dp[i][k] + dp[k][j];
					}
				}
			}
		}
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				for(int k = i + 1;k <= j - 1;k++)
				{
					if(dp[i][k] + dp[k][j] == dp[i][j])
					{
						f[i][j] += f[i][k] * f[k][j];
					}
				}
			}
		}
		long long ans = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				if(f[i][j] == 2)
				{
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}