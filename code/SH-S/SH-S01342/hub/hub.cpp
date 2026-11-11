#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int inf = 1e9;
int C , n , k , d[1000005] , fa[100005][20] , eu[100005] , ev[100005] , f[100005] , ans;
vector<int> g[1000005]; 
bool flag[1000005];
void init(int u)
{
	d[u] = d[fa[u][0]] + 1;
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int v : g[u])
		if (v != fa[u][0]) fa[v][0] = u , init(v);
}
int lca(int u , int v)
{
	if (d[u] < d[v]) swap(u , v);
	int t = d[u] - d[v];
	while (t)
	{
		u = fa[u][__builtin_ctz(t)];
		t &= t - 1;
	}
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (fa[u][i] != fa[v][i]) u = fa[u][i] , v = fa[v][i];
	return fa[u][0];
}
int dis(int u , int v)
{
	return d[u] + d[v] - d[lca(u , v)] * 2;
}
int search(int u)
{
	return (f[u] == u) ? u : f[u] = search(f[u]);
}
void dfs(int id , int cnt)
{
	if (id == n + 1)
	{
		if (cnt < k) return;
		for (int i = 1; i <= n; i++) f[i] = i;
		for (int i = 1; i < n; i++)
			if (flag[eu[i]] && flag[ev[i]]) f[search(eu[i])] = ev[i];
		int x = 0;
		for (int i = 1; i <= n; i++)
			if (flag[i] && search(i) == i) x ++;
		if (x > 2) return;
		int ret = 0;
		for (int i = 1; i <= n; i++)
		{
			int x = inf;
			for (int j = 1; j <= n; j++)
				if (flag[j]) x = min(x , dis(i , j));
			ret = max(ret , x);
		}
		ans = min(ans , ret);
		return;
	}
	if (cnt < k) flag[id] = true , dfs(id + 1 , cnt + 1);
	flag[id] = false , dfs(id + 1 , cnt);
}
bool check(int x)
{
	int t = n - x * 2 - k + 2;
	if (t <= 1) return true;
	return t / 2 + 1 <= x;
}
void solve()
{
	scanf("%d%d" , &n , &k);
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i < n; i++)
	{
		int u , v; scanf("%d%d" , &u , &v);
		eu[i] = u , ev[i] = v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (C <= 3)
	{
		init(1);
		ans = inf;
		dfs(1 , 0);
		printf("%d\n" , ans);
	}
	else if (C == 13 || C == 14)
	{
		int l = 0 , r = n;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n" , l);
	}
}
int main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int t; cin >> C >> t;
	while (t --) solve();
	return 0;
}
