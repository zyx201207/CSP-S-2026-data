#include<bits/stdc++.h>
using namespace std;
int c, q, n, dp[1005];
long long a[50001], d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> q;
	while(q--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			scanf ("%lld", &a[i]);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			memset(dp, 0, sizeof(dp));
			for (int j = i + 1; j <= n; j++)
			{
				for (int k = i ; k < j; k++)
					if (abs(a[j] - a[k]) <= d)
					{
						dp[j] = dp[k] + 1;
						if (dp[k] == dp[k + 1] && dp[k] != dp[k + 2])
							ans++;
						break;	
					}	
			}
		}
		cout << ans << "\n";	
	}
	return 0;
}
