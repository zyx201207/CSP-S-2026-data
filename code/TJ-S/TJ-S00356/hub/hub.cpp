#include <bits/stdc++.h>
using namespace std;

vector <int> g[1000005];
vector <int> ctis;
int n, k;
int fa[1000005][24];
int dep[1000005];
bool book[1000005];
void dfsl(int x, int fat)
{
	fa[x][0] = fat;
	for (int i = 1; i <= 23; i++)
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	dep[x] = dep[fat] + 1;
	for (int i = 0; i < g[x].size(); i++)
	{
		if (g[x][i] != fat)
		{
			dfsl(g[x][i], x);
		}
	}
}

int lca(int x, int y)
{
	if (dep[x] < dep[y])
		swap(x, y);
	for (int i = 23; i >= 0; i--)
	{
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	}
	for (int i = 23; i >= 0; i--)
	{
		if (fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	if (x != y)
	{
		return fa[x][0];
	}
	return x;
}
int ans = 0x3f3f3f3f3f3f3f3f;
bool bookn[2000005];
void dfs2(int x, int fa)
{
	for (int i = 0; i < g[x].size(); i++)
	{
		if (fa == g[x][i]) continue;
		if (book[g[x][i]])
		{
			bookn[g[x][i]] = 1;
			dfs2(g[x][i], x);
		}
	}
}
bool check()
{
	memset(bookn, 0, sizeof(bookn));
	int num = 0;
	for (int i = 0; i < ctis.size(); i++)
	{
		if (!bookn[ctis[i]])
		{
			num++;
			if (num > 2) return 0;
			dfs2(ctis[i], 0);
		}
	}
	return 1;
}

void dfs(int x, int es)
{
	if (x == n + 1)
	{
		if (es != 0) return;
		int maxn = 0;
//		for (int i = 1; i <= n; i++) cout << book[i] << ' ';
//		cout << '\n';
		if (check())
		{
//			cout << '$';
			for (int i = 1; i <= n; i++)
			{
				int minn = 0x3f3f3f3f;
				if (book[i] == 0)
				{
					for (int j = 1; j <= n; j++)
					{
						if (book[j] == 1)
						{
							int lc = lca(i, j);
							minn = min(minn, dep[i] + dep[j] - dep[lc] - dep[fa[lc][0]] - 1);
						}
					}
//					cout << i << ' ' << minn << '\n';
					maxn = max(maxn, minn);
				}
			}
			ans = min(ans, maxn);
//			if (maxn == 0)
//			{
//				for (int i = 1; i <= n; i++)
//				{
//					int minn = 0x3f3f3f3f;
//					if (book[i] == 0)
//					{
//						for (int j = 1; j <= n; j++)
//						{
//							if (book[j] == 1)
//							{
//								int lc = lca(i, j);
//								minn = min(minn, dep[i] + dep[j] - dep[lc] - dep[fa[lc][0]] - 1);
//							}
//						}
//						cout << i << ' ' << minn << '\n';
//						maxn = max(maxn, minn);
//					}
//				}
//			}
		}
		return;
	}
	dfs(x + 1, es);
	if (es > 0)
	{
		ctis.push_back(x);
		book[x] = 1;
		dfs(x + 1, es - 1);
		book[x] = 0;
		ctis.pop_back();
	}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(fa, 0, sizeof(fa));
		memset(dep, 0, sizeof(dep));
		dfsl(1, 0);
		ans = 0x3f3f3f3f;
		dfs(1, k);
		cout << ans << '\n';
	}
	return 0;
}
