#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define pb push_back
#define min(x, y) (x > y ? y : x)
#define max(x, y) (x > y ? x : y)
using namespace std;
const int N = 5e5 + 10;
int C, T, n, m;
int dfn[N], tp[N], rnk[N], fa[N], dep[N], sz[N], hs[N];
vector<int> g[N];
void dfs1(int u)
{
	dfn[u] = ++ idx, rnk[idx] = u, dep[u] = dep[fa[u]] + 1, sz[u] = 1;
	for(auto j : g[u])
		if(j != fa[u])
		{
			fa[j] = u, dfs1(j), sz[u] += sz[j];
			if(sz[j] > sz[hs[u]]) hs[u] = j;
		}
}
void dfs2(int u, int t)
{
	tp[u] = t;
	if(hs[u]) dfs2(hs[u], t);
	for(auto j : g[u]) if(j != fa[u] && j != hs[u]) dfs2(j, j);
}
int lca(int u, int v)
{
	while(tp[u] != tp[v])
	{
		if(dep[u] < dep[v]) swap(u, v);
		u = fa[tp[u]];
	}
	return dfn[u] < dfn[v] ? u : v;
}
int d[N], md, mk;
bool vis[N];
bool dfs3(int u)
{
	bool fg = 0;
	d[u] = d[fa[u]] + 1;
	if(d[u] > md) md = d[u], mk = u;
	for(auto j : g[u]) if(!vis[j] && j != fa[u]) fg |= dfs3(j);
	return fg;
}
void check(int mid)
{
	int u = 1;
	vector<int> ans;
	md = mk= 0;
	while(dfs3(u))
	{
		
		vis[mk] = 1, u = mk, md = mk = 0;
	}
}
void solve()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) g[i].clear();
	for(int i = 1, x, y; i < n; i ++)
		cin >> x >> y, g[x].pb(y). g[y].pb(x);
	dfs1(1), dfs2(1, 1);
	int l = 1, r = N - 1, ans = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid - 1, ans = mid;
		else r = mid + 1;
	}
	cout << ans << "\n";
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> C >> T;
	while(T --) solve();
	return 0;
}
