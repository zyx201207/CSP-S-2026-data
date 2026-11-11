#include <bits/stdc++.h>
using namespace std;

int ccccc, n, m, d, qu;
int G[505][100005];
long long a[500005];
vector<pair<long long, long long> > val[505];
vector<long long> p[505];
long long v[505][505];
long long ans;
vector<int> q[500005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	cin >> ccccc >> n >> m >> d >> qu;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int u, w;
			cin >> u >> w;
			G[i][u] = w;
			p[i].push_back(u);
			q[u].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			v[i][j] = v[j][i] = INT_MAX;
	for (int i = 1; i <= m; i++)
		for (auto x : q[i])
			for (auto y : q[i])
				if (x != y)
					v[x][y] = v[y][x] = min(v[x][y], (long long)G[x][i] + (long long)G[y][i]);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				v[i][j] = v[j][i] = min(v[i][j], v[i][k] + v[j][k]);
	while (qu--)
	{
		int x, y;
		cin >> x >> y;
		long long ans = LONG_LONG_MAX;
		for (auto l : q[x])
			for (auto r : q[y])
				ans = min(ans, a[x] + a[y] + v[l][r] + G[l][x] + G[r][y]);
		cout << ans << '\n';
	}
	
	return 0;
}
