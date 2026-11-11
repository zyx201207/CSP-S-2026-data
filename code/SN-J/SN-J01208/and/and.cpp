#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200007
using namespace std;
int n, m, a[N];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp[i][1] = a[i];
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			for (int k = i - 1; k >= 1; k--)
			{
//				cout << i << " " << j << " " << k << " " << a[i] & dp[k][m - 1] << " " <<
				dp[i][j] = max(dp[i][j], a[i] & dp[k][j - 1]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, dp[i][m]);
	}
	cout << ans;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
	return 0;
}
