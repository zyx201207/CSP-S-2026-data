#include<bits/stdc++.h>

const int MAXN = 2e5 + 5;

const int inf = 1e9;

int cc, tt, n, k; std::vector<int> e[MAXN];

int depth[MAXN], sz[MAXN], son[MAXN], fa[MAXN];

inline void dfs1(int u, int fat)
{
	fa[u] = fat, sz[u] = 1, depth[u] = depth[fat] + 1;
	for(int v : e[u])
	{
		if(!(v ^ fat))
			continue;
		dfs1(v, u), sz[u] += sz[v];
		if(sz[v] > sz[son[u]])
			son[u] = v;
	}
}

int dfn[MAXN], rk[MAXN], idx, top[MAXN];

inline void dfs2(int u, int ftop)
{
	top[u] = ftop, dfn[u] = ++idx, rk[idx] = u;
	if(son[u]) dfs2(son[u], ftop);
	for(int v : e[u])
	{
		if(!(v ^ fa[u]))
			continue;
		else if(!(v ^ son[u]))
			continue;
		dfs2(v, v);
	}
}

inline int lca(int x, int y)
{
	while(top[x] != top[y])
	{
		if(dfn[top[x]] > dfn[top[y]])
			x = fa[top[x]];
		else y = fa[top[y]];
	}
	
	return (dfn[x] < dfn[y] ? x : y);
}

int ans; bool vis[MAXN];

int U[MAXN], V[MAXN];

struct DSU
{
	int fa[MAXN];
	
	inline void init(const int n)
	{
		for(int i = 1; i <= n; i++)
			fa[i] = i;
	}
	
	inline int getf(int x)
	{
		if(fa[x] == x) return x;
		return fa[x] = getf(fa[x]);
	}
	
	inline void merge(int x, int y)
	{
		int xf = getf(x), yf = getf(y);
		if(xf != yf) fa[xf] = yf;
	}
} dsu;

inline void dfs(int x, int count)
{
	if(count == k)
	{
		dsu.init(n);
		for(int i = 1; i < n; i++)
			if(vis[U[i]] && vis[V[i]])
				dsu.merge(U[i], V[i]);
		std::map<int, int> M;
		for(int i = 1; i <= n; i++)
			M[dsu.getf(i)]++;
		if((int)M.size() == 2)
		{
			int mx = 0;
			for(int i = 1; i <= n; i++)
			{
				int mi = inf;
				for(int j = 1; j <= n; j++)
					if(vis[j])
						mi = std::min(mi, depth[i] + depth[j] - 2 * depth[lca(i, j)]);
				mx = std::max(mx, mi);
			} ans = std::min(ans, mx);
		}
		return;
	}
	if(x == n + 1) return;
	vis[x] = 1, dfs(x + 1, count + 1), vis[x] = 0, dfs(x + 1, count);
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	scanf("%d%d", &cc, &tt);
	while(tt--)
	{
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
			e[i].clear(), depth[i] = sz[i] = son[i] = fa[i] = dfn[i] = rk[i] = top[i] = vis[i] = 0; idx = 0;
		for(int _ = 1, u, v; _ < n; _++)
			scanf("%d%d", &u, &v), e[u].emplace_back(v), e[v].emplace_back(u), U[_] = u, V[_] = v;
		dfs1(1, 0), dfs2(1, 1), ans = inf, dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}
