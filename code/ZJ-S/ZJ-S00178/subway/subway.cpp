#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 507, M = 5e5 + 7;
int c, n, m, d, q;
int w[M];
vector<int> a[M], t[M];
int k[M];
struct EDGE
{
	int to, next, w;
}edge[M];
int h[M], idx;

void Add(int u, int v, int w)
{
	edge[++idx] = {v, h[u], w};
	h[u] = idx;
}

priority_queue<pii, vector<pii>, greater<pii> > p;
int dis[M], dp[N][N];
int vis[M];
void dijkstra(int s)
{
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0; p.push({0, s});
	while (!p.empty())
	{
		int u = p.top().second; p.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = h[u]; i; i = edge[i].next)
		{
			int v = edge[i].to, w = edge[i].w;
			if (dis[v] > dis[u] + w) dis[v] = dis[u] + w, p.push({dis[v], v});
		}
	}
	for (int i = 1; i <= n; i++) dp[s][i] = dis[i];
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= m; i++)
	{
		cin >> k[i];
		a[i].resize(k[i] + 1), t[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][j];
		for (int j = 1; j <= k[i]; j++) Add(a[i][j], a[i][j] + n * i, t[i][j]), Add(a[i][j] + n * i, a[i][j], t[i][j]);
		for (int j = 1; j <= k[i]; j++)
		{
			for (int p = j + 1; p <= min(j + d, k[i]); p++) Add(a[i][j] + n * i, a[i][p] + n * i, 0), Add(a[i][p] + n * i, a[i][j] + n * i, 0);
		}
	}
	for (int i = 1; i <= n; i++) dijkstra(i);
	while (q--)
	{
		int x, y; cin >> x >> y;
		cout << dp[x][y] + w[x] + w[y] << '\n';
	}
	return 0;
}
/*
暴力：
一共有2500个分层点 8000条边
跑500次dijkstra,然后对于每次直接访问即可500*2500 
*/
