#include <bits/stdc++.h>
using namespace std;
#define freopen(io) freopen(io".in", "r", stdin), freopen(io".out", "w", stdout)

const int MAXN = 200007;
int n, m, a[MAXN], dp[2][MAXN], u = 0;

signed main()
{
	freopen("and");
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[0][0] = 0x7fffffff;
	for (int i = 1; i <= n; i++)
	{
		u ^= 1;
		dp[u][0] = 0x7fffffff;
		for (int j = 1; j <= i && j <= m; j++)
			dp[u][j] = max(dp[u ^ 1][j], a[i] & dp[u ^ 1][j - 1]);
	}
	cout << dp[u][m] << '\n';
}