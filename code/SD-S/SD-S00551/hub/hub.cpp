#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 110, INF = 1000000000000000007;
int a[N], b[N], fa[N], dis[N], n, k, ans;
bool vis[N];
vector<int> G[N];
struct Edge
{
	int u, v;
}E[N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int dist(int u, int v)
{
	if (u == v) return 0;
	for (int i = 1; i <= n; i += 1) a[i] = b[i] = INF;

	queue<pair<int, int> > q;
	a[u] = 0; q.push({u, 0});
	while (!q.empty())
	{
		int nw = q.front().first, step = q.front().second; q.pop();
		for (auto nxt: G[nw])
		{
			if (a[nxt] != INF) continue;
			a[nxt] = step + 1; q.push({nxt, step + 1});
		}
	}

	b[v] = 0; q.push({v, 0});
	while (!q.empty())
	{
		int nw = q.front().first, step = q.front().second; q.pop();
		for (auto nxt: G[nw])
		{
			if (b[nxt] != INF) continue;
			b[nxt] = step + 1; q.push({nxt, step + 1});
		}
	}

	int res = INF;
	for (int i = 1; i <= n; i += 1) res = min(res, a[i] + b[i]);
	return res;
}
void dfs(int pos)
{
	if (pos == (n + 1))
	{
		int cnt = 0;
		for (int i = 1; i <= n; i += 1) if (vis[i] == true) cnt += 1;
		if (cnt != k) return;

		for (int i = 1; i <= n; i += 1) fa[i] = i;
		for (int i = 1; i < n; i += 1)
		{
			if (vis[E[i].u] == true and vis[E[i].v] == true)
			{
				int fu = find(E[i].u), fv = find(E[i].v);
				fa[fu] = fv;
			}
		}

		set<int> s; s.clear();
		for (int i = 1; i <= n; i += 1) if (vis[i] == true) s.insert(find(fa[i]));
		if (s.size() > 2) return;

		for (int i = 1; i <= n; i += 1) dis[i] = INF;
		for (int i = 1; i <= n; i += 1)
		{
			if (s.find(find(i)) != s.end())
			{
				dis[i] = 0;
				continue;
			}
			for (int j = 1; j <= n; j += 1)
			{
				if (s.find(find(j)) != s.end()) dis[i] = min(dis[i], dist(i, j));
			}
		}

		int res = -INF;
		for (int i = 1; i <= n; i += 1) res = max(res, dis[i]);

		ans = min(ans, res);
		return;
	}

	vis[pos] = true;
	dfs(pos + 1);
	vis[pos] = false;
	dfs(pos + 1);
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	
	int c, T;
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i += 1) G[i].clear();
		for (int i = 1; i < n; i += 1)
		{
			int u, v;
			cin >> u >> v;
			E[i].u = u; E[i].v = v;
			G[u].push_back(v);
			G[v].push_back(u);
		}

		ans = INF;
		for (int i = 1; i <= n; i += 1) vis[i] = false;
		dfs(1);

		cout << ans << endl;
	}
	return 0;
}
