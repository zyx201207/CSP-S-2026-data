#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q;
const int N = 520, M = 5e5 + 10;
int w[N], k[N];
unordered_map<int, int> t[N], a[N];
vector<int> nxt[M];
int cnt;
int dis[N][N];
vector<pair<int, int>> e[N];
int pre[M * 20];
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			nxt[a[i][j]].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int v : nxt[a[i][j]])
			{
				if (v == i)
				{
					continue;
				}
				e[i].push_back({v, t[i][j] * 2});
				dis[i][j] = t[i][j] * 2;
				dis[j][i] = t[i][j] * 2;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			for (int k = 1; k <= j; k++)
			{
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
			}
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		cin >> x >> y;
		int ans = INT_MAX;
		for (int u : nxt[x])
		{
			for (int v : nxt[y])
			{
				ans = min(dis[u][v], ans);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
}
// rp++