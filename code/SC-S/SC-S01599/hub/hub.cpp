# include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10, M = 20;
vector<int> s[N];
int f[N][M], dep[N], n, k, a[N], tot, vis[N], flg[N];

void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1;
	for(int v : s[u])
	{
		if(v != fa) 
		{
			dfs(v, u);
			f[v][0] = u;
		}
	}
}

int lca(int u, int v)
{
	if(dep[u] < dep[v]) swap(u, v);
	int tmp = dep[u] - dep[v];
	for(int i = 0;i < M; i ++ )
	{
		if(tmp >> i & 1) u = f[u][i];
	}
	if(u == v) return u;
	for(int i = M - 1;i >= 0;i -- ) if(f[u][i] != f[v][i]) u = f[u][i], v = f[u][i];
	return f[u][0];
}

void ck(int u)
{
	for(int v : s[u])
	{
		if(!vis[v] && flg[v])
		{
			vis[v] = 1;
			ck(v);
		}
	}
}

int check(int s)
{
	tot = 0;
	int idx = 0;
	for(int i = 1;i <= n;i ++ ) vis[i] = flg[i] = 0;
	for(int i = 0;i < n;i ++ )
	{
		if(s >> i & 1) 
		{
			idx ++ ;
			a[ ++ tot] = i + 1;
			flg[i + 1] = 1;
		}
	}
	if(idx > k) return 0;
	int cnt = 0;
	for(int i = 1;i <= tot;i ++ )
	{
		if(!vis[a[i]])
		{
			vis[a[i]] = 1;
			ck(a[i]);
			cnt ++ ;
		}
	}
	return (cnt <= 2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, t; cin >> c >> t;
	while(t -- )
	{
		cin >> n >> k;
		for(int i = 1, u, v;i < n;i ++ )
		{
			cin >> u >> v;
			s[u].emplace_back(v);
			s[v].emplace_back(u);
		}
		
		dfs(1, 0);
		for(int j = 1;j < M;j ++ )
		{
			for(int i = 1;i <= n;i ++ )
			{
				f[i][j] = f[f[i][j - 1]][j - 1];
			}
		}
		int mx = (1 << n) - 1;
		int qqq = 1e9;
		for(int s = 0;s <= mx;s ++ )
		{
			if(!check(s)) continue;
			int res = 0;
			for(int i = 1;i <= n;i ++ )
			{
				int ans = 1e9;
				for(int j = 1;j <= tot;j ++ )
				{
					int u = i, v = a[j], lc = lca(u, v);
					ans = min(ans, dep[u] - dep[lc] + dep[v] - dep[lc]);
				}
				res = max(res, ans);
			}
			qqq = min(qqq, res);
		}
		cout << qqq << '\n';
		for(int i = 1;i <= n;i ++ ) s[i].clear();
		for(int i = 0;i < M;i ++ ) for(int j = 1;j <= n;j ++ ) f[j][i] = 0;
	}
	return 0;
}