#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7, inf = 1e18;
int c, n, m, d, q;
const int M = 507;
typedef pair<int, int> pii;
int dis[M][M], w[N];
vector<pii> vt[N];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1;i <= m; i++)
		scanf("%lld", w + i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = (i != j) * inf;
	for (int i = 1, k; i <= n; i++)
	{
		scanf("%lld", &k);
		for (int j = 1, a, t; j <= k; j++)
		{
			scanf("%lld%lld", &a, &t);
			for (pii p : vt[a])
				dis[p.first][i] = dis[i][p.first] = min(dis[i][p.first], t + p.second);
			vt[a].emplace_back(i, t);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
	while (q--)
	{
		int x, y, ret = inf;
		scanf("%lld%lld", &x, &y);
		for (pii px : vt[x])
			for (pii py : vt[y])
				ret = min(ret, w[x] + w[y] + px.second + py.second + dis[px.first][py.first]);
		cout << ret << "\n";
	}
}
