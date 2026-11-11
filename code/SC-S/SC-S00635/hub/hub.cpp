#include <bits/stdc++.h>
using namespace std;

const int N = 35;

int c, t, n, k, ans;
int col[N], dist[N], fa[N];
vector<int> tr[N];

int find(int x)
{
	return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

void merge(int u, int v)
{
	int fu = find(u), fv = find(v);
	if (fu != fv) fa[fu] = fv;
}

bool check()
{
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= n; i++)
	{
		if (!col[i]) continue;
		for (int j : tr[i])
			if (col[j]) merge(i, j);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!col[i]) continue;
		if (find(i) == i) cnt++;
	}
	return (cnt <= 2);
}

int calc()
{
	memset(dist, 0x3f, sizeof(dist));
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (col[i]) q.push(i), dist[i] = 0;
	while (q.size())
	{
		int u = q.front();
		q.pop();
		for (int v : tr[u])
		{
			if (dist[v] > dist[u] + 1)
			{
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res = max(res, dist[i]);
	return res;
}

void dfs(int u, int cnt)
{
	if (u == n + 1)
	{
		if (cnt != k) return;
		if (check()) ans = min(ans, calc());
		return;
	}
	dfs(u + 1, cnt);
	if (cnt < k)
	{
		col[u] = 1;
		dfs(u + 1, cnt + 1);
		col[u] = 0;
	}
}

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 1, u, v; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	ans = 1e9;
	dfs(1, 0);
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		tr[i].clear();
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) solve();
	return 0;
}

/*
15 pts at 16:53
*/