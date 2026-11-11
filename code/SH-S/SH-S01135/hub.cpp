#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 7, inf = 1e18;
int c, t;
int a[N << 1], virt[N], cnt, dp[N];
typedef pair<int, int> pii;
vector<int> e[N];
int n, k, dfn[N], fa[N][21], tot, dep[N], depmn[N], dis2[N];
void dfs(int u, int pa)
{
	fa[u][0] = pa; dep[u] = dep[pa] + 1;
	for (int i = 1; i <= 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	dfn[u] = ++tot;
	for (int v : e[u])
		if (v != pa)
			dfs(v, u);
}
int lca(int u, int v)
{
	if (dep[u] < dep[v])
		swap(u, v);
	for (int d = dep[u] - dep[v], i = 20; ~i; i--)
		if (d >> i & 1)
			u = fa[u][i];
	if (u == v)
		return u;
	for (int i = 20; ~i; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
bool live[N], recall[N];
int dis(int u, int v)
{
	return dep[u] + dep[v] - dep[lca(u, v)] * 2;
}
pii fnd()
{
	int cnta = 0, cntb = 0, cts = 0;
	sort(virt + 1, virt + cnt + 1, [&](int a, int b)
		{ return dfn[a] < dfn[b]; });
	for (int i = 1; i <= cnt; i++)
		a[++cts] = virt[i];
	for (int i = 1; i < cnt; i++)
		a[++cts] = lca(virt[i + 1], virt[i]);
	sort(a + 1, a + cts + 1, [&](int a, int b)
		{ return dfn[a] < dfn[b]; });
	cts = unique(a + 1, a + cts + 1) - a - 1;
	cnta = dis(a[1], a[cts]);
	for (int i = 1; i < cts; i++)
	{
		cnta += dis(a[i], a[i + 1]);
		cntb = max(cntb, dep[a[i + 1]] - dep[lca(a[i], a[i + 1])]);
	}
	return pii(cnta / 2 + 1, cntb);
}
bool vis[N];
void bfs(int nw)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		vis[i] = 0, dis2[i] = inf;
	for (int i = 1; i <= n; i++)
		if (e[i].size() == 1)
			q.push(i), dis2[i] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		if (vis[u] || dis2[u] == nw + 1)
			continue;
		vis[u] = 1;
		for (int v : e[u])
			if (dis2[v] > dis2[u] + 1)
				dis2[v] = dis2[u] + 1, q.push(v);
	}
}
int check(int mid)
{
	//...
	bfs(mid);
	for (int i = 1; i <= n; i++)
		live[i] = !vis[i];
	cnt = 0;
	int cts = 0;
	for (int i = 1; i <= n; i++)
	{
		cts += live[i];
		if (!live[i])
			continue;
		if (e[i].size() == 2)
		{
			for (int j : e[i])
				if (!live[j])
				{
					virt[++cnt] = i;
					break;
				}
		}
		else
			virt[++cnt] = i;
	}
	if (!cts)
		return 1;
	pii qy = fnd();
	return qy.first - min(qy.second, mid * 2) + 1 <= k;
}
void solve()
{
	scanf("%lld%lld", &n, &k); tot = 0;
	for (int i = 1; i <= n; i++)
		e[i].clear();
	for (int i = 1, u, v; i < n; i++)
		scanf("%lld%lld", &u, &v), e[u].push_back(v), e[v].push_back(u);
	if (n == k)
	{
		printf("0\n");
		return;
	}
	dfs(1, 0);
	int l = 1, r = n;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%lld\n", l);
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--)
		solve();
}
