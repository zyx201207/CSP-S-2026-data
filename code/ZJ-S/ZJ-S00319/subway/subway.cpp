#include <bits/stdc++.h>
using namespace std;
int n, m, q, x, y, w[500005];
long long d[505][505];
vector<pair<int, int>> a[500005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> n >> m >> q >> q;
	for(int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for(int i = 1, k; i <= n; i++)
	{
		cin >> k;
		while(k--) scanf("%d%d", &x, &y), a[x].push_back({i, y});
	}
	memset(d, 63, sizeof d);
	for(int i = 1; i <= n; i++) d[i][i] = 0;
	for(int i = 1; i <= m; i++)
		for(auto x : a[i])
			for(auto y : a[i])
				d[x.first][y.first] = min<long long>(d[x.first][y.first], x.second + y.second);
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	while(q--)
	{
		scanf("%d%d", &x, &y);
		long long ans = 5e18;
		for(auto X : a[x])
			for(auto Y : a[y])
				ans = min(ans, d[X.first][Y.first] + X.second + Y.second);
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}