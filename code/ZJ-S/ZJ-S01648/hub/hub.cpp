#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

int read()
{
	int x = 0;
	bool f = true;
	char c = getchar();
	while (c < '0' || c > '9')
		f = (c != '-'), c = getchar();
	while (c >= '0' && c <= '9')
		x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

void write(int x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar((x % 10) ^ 48);
}

const int INF = 0x3f3f3f3f;
int n, k;
vector<int> adj[5005];
int a[505];
int ans;
bool vis[505];
queue<pair<int, int> > q;
bool f[505][505];
int fa[505];

int getFa(int x)
{
	if (fa[x] != x)
		fa[x] = getFa(fa[x]);
	return fa[x];
}

void dfs(int u, int cnt)
{
	if (n - u + cnt < k)
		return;
	if (cnt > k)
	{
		for (int i = 1; i <= n; ++i)
			vis[i] = false, fa[i] = i;
		for (int i = 1; i < k; ++i)
			for (int j = i + 1; j <= k; ++j)
				if (f[a[i]][a[j]])
				{
					int fx = getFa(a[i]), fy = getFa(a[j]);
					if (fx != fy)
						fa[fx] = fy;
				}
		int f1 = -1, f2 = -1;
		for (int i = 1; i <= k; ++i)
		{
			int fx = getFa(a[i]);
			if (f1 == -1 || f1 == fx)
			{
				f1 = fx;
				continue;
			}
			if (f2 == -1 || f2 == fx)
			{
				f2 = fx;
				continue;
			}
			return;
		}
		for (int i = 1; i <= k; ++i)
			q.push(make_pair(a[i], 0)), vis[a[i]] = true;
		int res = 0;
		while (!q.empty())
		{
			int u = q.front().first, dis = q.front().second;
			q.pop();
			for (int i = 0; i < adj[u].size(); ++i)
			{
				int v = adj[u][i];
				
				if (vis[v])
					continue;
				vis[v] = true;
				q.push(make_pair(v, dis + 1));
				res = max(res, dis + 1);
			}
		}
		if (res < ans)
			ans = res;
		return;
	}
	if (u > n)
		return;
	a[cnt] = u;
	dfs(u + 1, cnt + 1);
	dfs(u + 1, cnt);
}

int dist[5005][5005];

void Bfs(int s)
{
	q.push(mp(s, 0));
	while (!q.empty())
	{
		int u = q.front().first;
		q.pop();
		for (int i = 0; i < adj[u].size(); ++i)
		{
			int v = adj[u][i];
			if (dist[s][v] != INF)
				continue;
			dist[s][v] = dist[s][u] + 1;
			q.push(mp(v, dist[s][v]));
		}
	}
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	c = read(), t = read();
	while (t--)
	{
		n = read(), k = read();
		for (int i = 1; i <= n; ++i)
		{
			adj[i].clear();
			for (int j = 1; j <= n; ++j)
				f[i][j] = false;
		}
		for (int i = 1, u, v; i < n; ++i)
		{
			u = read(), v = read();
			if (n <= 500)
				f[u][v] = f[v][u] = true;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ans = INF;
		if (k == 2 && n > 10)
		{
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					dist[i][j] = INF;
			for (int i = 1; i <= n; ++i)
			{
				dist[i][i] = 0;
				Bfs(i);
			}
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
				{
					if (i == j)
						continue;
					int res = 0;
					for (int l = 1; l <= n; ++l)
						res = max(res, min(dist[i][l], dist[j][l]));
					ans = min(ans, res);
				}
		}
		else
		{
			dfs(1, 1);
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}