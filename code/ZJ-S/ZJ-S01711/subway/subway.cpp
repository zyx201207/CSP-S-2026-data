#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10;
struct Node
{
	int y, w;
};
vector <Node> g[N];
int c, m, n, D, q;
long long dis[N], w[N], k[N], a[N], d[N];
struct Edge
{
	int x;
	long long dis;
	bool operator < (const Edge &B) const
	{
		return dis > B.dis;
	}
};
void dijkstra(int s, int t)
{
	for (int i = 1; i <= n; i++) dis[i] = 1e18;
	dis[s] = 0;
	priority_queue <Edge> q;
	q.push({s, 0});
	while(q.size())
	{
		int x = q.top().x, d = q.top().dis;
		q.pop();
		if (d != dis[x]) continue;
		if (x == t) return;
		for (int i = 0; i < g[x].size(); i++)
		{
			int y = g[x][i].y, w = g[x][i].w;
			if (dis[x] + w < dis[y])
			{
				dis[y] = dis[x] + w;
				q.push({y, dis[y]});
			}
		}
	}
}
int fa1[N], fa2[N];
int aa[10][N], dd[10][N];
int find1(int x)
{
	if (fa1[x] == x) return fa1[x] = x;
	return fa1[x] = find1(fa1[x]);
}
int find2(int x)
{
	if (fa2[x] == x) return fa2[x] = x;
	return fa2[x] = find2(fa2[x]);
} 
int dist[510][510];
vector <int> f[N];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> m >> n >> D >> q;
	for (int i = 1; i <= n; i++) cin >> w[i];
	if (c <= 11)
	{
		for (int i = 1; i <= m; i++)
		{
			cin >> k[i];
			for (int j = 1; j <= k[i]; j++)
			{
				cin >> a[j] >> d[j];
			}
			for (int j1 = 1; j1 <= k[i]; j1++)
			{
				for (int j2 = j1 + 1; j2 <= k[i]; j2++)
				{
					g[a[j1]].push_back({a[j2], d[j1] + d[j2]});
					g[a[j2]].push_back({a[j1], d[j1] + d[j2]});
				}
			}
		}
		while(q--)
		{
			int x, y;
			cin >> x >> y;
			dijkstra(x, y);
			cout << w[x] + w[y] + dis[y] << endl;
		}
		return 0;
	}
	if (c >= 20 && c <= 21)
	{
		map <int, int> cc, s;
		for (int i = 1; i <= n; i++) fa1[i] = fa2[i] = i;
		for (int i = 1; i <= m; i++)
		{
			cin >> k[i];
			for (int j = 1; j <= k[i]; j++)
			{
				cin >> aa[i][j] >> dd[i][j];
				cc[aa[i][j]]++, s[aa[i][j]] += dd[i][j];
				if (i == 1) fa1[find1(aa[i][j])] = find1(aa[i][1]);
				else fa2[find2(aa[i][j])] = find2(aa[i][1]);
			}
		}
		int minn = 1e18;
		for (int i = 1; i <= n; i++)
		{
			if (cc[i] == 2) minn = min(minn, s[i]);
		}
		while(q--)
		{
			int x, y;
			cin >> x >> y;
			int ans = 1e18;
			if (find1(x) == find1(y)) ans = min(ans, dd[1][x] + dd[1][y]);
			if (find2(x) == find2(y)) ans = min(ans, dd[2][x] + dd[2][y]);
			if (find1(x) != find1(y) && find2(x) != find2(y)) ans = min(ans, minn + s[x] + s[y]);
			cout << ans + w[x] + w[y] << endl;
		}
		return 0;
	}
	if (c >= 12 && c <= 19)
	{
		int T;
		for (int i = 1; i <= m; i++)
		{
			int kk;
			cin >> kk;
			for (int j = 1; j <= kk; j++)
			{
				int x;
				cin >> x >> T;
				f[x].push_back(i);
			}
		}
		memset(dist, 0x3f, sizeof(dist));
		for (int i = 1; i <= n; i++) dist[i][i] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < f[i].size(); j++)
				for (int j2 = j + 1; j2 < f[i].size(); j2++)
				{
					dist[f[i][j]][f[i][j2]] = dist[f[i][j2]][f[i][j]] = 2;
				}
		}
		for (int kk = 1; kk <= n; kk++)
		{
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dist[i][j] = min(dist[i][j], dist[i][kk] + dist[kk][j]);
		}
		int ans = 1e18;
		while(q--)
		{
			int x, y;
			cin >> x >> y;
			for (int i = 0; i < f[x].size(); i++)
				for (int j = 0; j < f[y].size(); j++)
					ans = min(ans, dist[f[x][i]][f[y][j]]);
			cout << (ans + 2) * T + w[x] + w[y] << endl;
		}
		return 0;
	}
	return 0;
}
