#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
int n, m, a[MAXN];
int dp[MAXN][2005], ans;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n <= 5000 && m <= 5000) 
	{ 
		dp[0][0] = 0;
		for(int i = 1; i <= n; i++)
		{
			dp[i][0] = 0;
			dp[i][1] = a[i];
		}
		for(int i = 0; i <= n; i++)
			if(i < m)
				for(int j = 1; j <= m - i; j++)
					dp[i][j] = -1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 2; j <= min(i, m); j++)
			{
				dp[i][j] = max(dp[i - 1][j - 1] & a[i], dp[i][j - 1]);
			}
		}
		cout << dp[n][m];
		return 0;
	}
	if(m == 1)
	{
		for(int i = 1; i <= n; i++)
			ans = max(ans, a[i]);
		cout << ans;
		return 0;
	}
	if(m == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
}
