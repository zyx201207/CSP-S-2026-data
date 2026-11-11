#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
int CASE, T, n, k;
int d[N], anc[N][25];
vector <int> s[N];
void dfs(int u, int fa)
{
	d[u] = d[fa] + 1;
	anc[u][0] = fa;
	for (int v : s[u])
	{
		if (v == fa) continue;
		dfs(v, u);
	}
}
void init()
{
	for (int j = 1; j <= 20; j ++)
	{
		for (int i = 1; i <= n; i ++)
		{
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
}
int dis(int u, int v)
{
	int dist = d[u] + d[v];
	if (d[u] < d[v]) swap(u, v);
	for (int i = 20; i >= 0; i --)
	{
		if (d[anc[u][i]] >= d[v])
		{
			u = anc[u][i];
		}
	}
	if (u == v)
	{
		dist -= 2 * d[u];
		return dist;
	}
	for (int i = 20; i >= 0; i --)
	{
		if (anc[u][i] != anc[v][i])
		{
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	int lca = anc[u][0];
	dist -= 2 * d[lca];
	return dist;
}
int p[N], tot, vis[N], st[N];
void ltk(int u)
{
	st[u] = 1;
	for (int v : s[u])
	{
		if (vis[v] == 0 || st[v] == 1) continue;
		ltk(v);
	}
}
int ans = 1e9;
void qpl(int x)
{
	if (tot == k)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i ++) st[i] = 0;
		for (int i = 1; i <= k; i ++)
		{
			if (!st[p[i]])
			{
				ltk(p[i]);
				cnt ++;
			}
			if (cnt > 2)
			{
				break;
			}
		}
		if (cnt > 2) return ;
		int res = 0;
		for (int i = 1; i <= n; i ++)
		{
			if (vis[i]) continue;
			int dij = 1e9;
			for (int j = 1; j <= k; j ++)
			{
				dij = min(dij, dis(i, p[j]));
			}
			res = max(res, dij);
		}
		ans = min(ans, res);
		return ;
	}
	if (x > n) return ;
	p[++ tot] = x;
	vis[x] = 1;
	qpl(x + 1);
	tot --;
	vis[x] = 0;
	qpl(x + 1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> CASE >> T;
	while (T --)
	{
		cin >> n >> k;
		for (int i = 1; i < n; i ++)
		{
			int u, v;
			cin >> u >> v;
			s[u].push_back(v);
			s[v].push_back(u);
		}
		dfs(1, 0);
		init();
		qpl(1);
		cout << ans << '\n';
		for (int i = 1; i <= n; i ++)
		{
			s[i].clear();
			p[i] = vis[i] = st[i] = d[i] = 0;
			for (int j = 0; j <= 21; j ++) anc[i][j] = 0;
		}
		tot = 0;
		ans = 1e9;
	}
	return 0;
}

