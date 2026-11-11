#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 500010;
typedef long long ll;
#define x first
#define y second

int C, n, m, D, Q;
vector<pair<int, ll>> w[M];
vector<pair<int, ll>> v[N];
ll sta[M];
ll g[N][N];
ll f[1010][1010];

void fl()
{
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(g, 0x3f, sizeof g);
	memset(f, 0x3f, sizeof f);
	scanf("%d%d%d%d%d", &C, &n, &m, &D, &Q);
	for (int i = 1; i <= n; i ++) g[i][i] = 0;
	for (int i = 1; i <= m; i ++) scanf("%lld", &sta[i]);
	
	for (int i = 1; i <= n; i ++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j ++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			w[a].push_back({i, b});
			v[i].push_back({a, b});
		}
	}
	for (int i = 1; i <= m; i ++)
	{
		int sz = w[i].size();
//		printf("station = %d %d\n", i, sz);
		if (sz > 1)
		{
			for (int l = 0; l < sz; l ++)
				for (int r = l + 1; r < sz; r ++)
					if (w[i][l].y + w[i][r].y < g[w[i][l].x][w[i][r].x])
						g[w[i][l].x][w[i][r].x] = g[w[i][r].x][w[i][l].x] = w[i][l].y + w[i][r].y;
		}
	}
//	for (int i = 1; i <= n; i ++)
//	{
//		for (int j = 1; j <= n; j ++)
//			printf("%lld ", g[i][j]);
//		puts("");
//	}
	fl();
	
	if (C >= 7 && C <= 11)
	{
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				{
					int a = v[i].size(), b = v[j].size();
					for (int l = 0; l < a; l ++)
						for (int r = 0; r < b; r ++)
							f[v[i][l].x][v[j][r].x] = min(f[v[i][l].x][v[j][r].x], g[i][j] + v[i][l].y + v[j][r].y);
				}
		while (Q --)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			printf("%lld\n", f[u][v] + sta[u] + sta[v]);
		}
	}
	else
	{
		while (Q --)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			int a = w[u].size(), b = w[v].size();
			ll res = 0x3f3f3f3f3f3f3f3f;
			for (int i = 0; i < a; i ++)
				for (int j = 0; j < b; j ++)
					res = min(res, g[w[u][i].x][w[v][j].x] + w[u][i].y + w[v][j].y + sta[u] + sta[v]);
			printf("%lld\n", res);
		}
	}
	
	return 0;
}
