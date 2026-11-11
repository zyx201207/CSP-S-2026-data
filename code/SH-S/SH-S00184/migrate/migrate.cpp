#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e6 + 10, M = 301;
int cid, n, d, a[N], f[M][M], g[M][M];
void solve()
{
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			f[i][j] = 1e18;
			g[i][j] = 0;
		}
	for (int i = 1; i <= n; ++i)
	{
		f[i][i] = 0;
		g[i][i] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		if (a[i + 1] - a[i] <= d) f[i][i + 1] = g[i][i + 1] = 1;
	}
	for (int len = 3; len <= n; ++len)
	{
		for (int i = 1; i + len - 1 <= n; ++i)
		{
			int j = i + len - 1;
			if (a[j] - a[i] <= d)
			{
				f[i][j] = 1;
				g[i][j] = 1;
				continue;
			}
			for (int k = i + 1; k < j; ++k) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			if (f[i][j] > n) continue;
			for (int k = i + 1; k < j; ++k) if (f[i][k] + f[k][j] == f[i][j] && f[k][j] == 1) g[i][j] += g[i][k] * g[k][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) for (int j = i + 2; j <= n; ++j) if (g[i][j] == 2) ++ans;
	cout << ans << '\n';
	return ;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> cid >> T;
	while (T--) solve();
	return 0;
}
