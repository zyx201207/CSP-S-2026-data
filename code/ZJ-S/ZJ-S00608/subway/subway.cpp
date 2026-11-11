#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 510, M = 500010, D = 25;

int n, m, d, T;
int cnt[N], r[M];
int ct[M];
struct Station
{
	int id, w;
} sta[D][M];
int h[N], e[N * N], w[N * N], ne[N * N], idx;
int dist[N][N];
int st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
	e[idx] = a, w[idx] = c, ne[idx] = h[b], h[b] = idx ++ ;
}

void dijkstra(int s)
{
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, s});
	dist[s][s] = 0;
	while (q.size())
	{
		auto t = q.top();
		q.pop();
		if (st[t.y]) continue;
		st[t.y] = 1;
		int u = t.y;
		for (int i = h[u]; ~i; i = ne[i])
		{
			int j = e[i];
			if (dist[s][j] > dist[s][u] + w[i])
			{
				dist[s][j] = dist[s][u] + w[i];
				if (!st[j]) q.push({dist[s][j], j});
			}
		}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(h, -1, sizeof h);
	cin >> n >> n >> m >> d >> T;
	for (int i = 1; i <= m; i ++ ) cin >> r[i];
	for (int i = 1; i <= n; i ++ )
	{
		cin >> cnt[i];
		for (int j = 1; j <= cnt[i]; j ++ )
		{
			int x, t;
			cin >> x >> t;
			sta[ ++ ct[x]][x] = {i, t};
		}
	}
	
	for (int i = 1; i <= m; i ++ )
	{
		for (int j = 1; j <= ct[i]; j ++ )
			for (int k = 1; k < j; k ++ )
				add(sta[j][i].id, sta[k][i].id, sta[j][i].w + sta[k][i].w);
	}
	for (int i = 1; i <= n; i ++ )
	{
		memset(dist[i], 0x3f, sizeof dist[i]);
		memset(st, 0, sizeof st);
		dijkstra(i);
	}
	
	while (T -- )
	{
		int a, b, res = 1e18;
		cin >> a >> b;
		for (int i = 1; i <= ct[a]; i ++ )
			for (int j = 1; j <= ct[b]; j ++ )
			{
				auto ti = sta[i][a], tj = sta[j][b];
				res = min(res, dist[ti.id][tj.id] + ti.w + tj.w);
			}
		
		cout << res + r[a] + r[b] << '\n';
	}
	
	return 0;
}
