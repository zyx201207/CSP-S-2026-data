#include <bits/stdc++.h>
using namespace std;
template <typename _Tp1, typename _Tp2> inline bool chkmx(_Tp1&x, const _Tp2&y) {return x < y && (x = y, 1);}
template <typename _Tp1, typename _Tp2> inline bool chkmn(_Tp1&x, const _Tp2&y) {return y < x && (x = y, 1);}
constexpr int N = 1e6+9;
int n,k,u,v,d,f[N],g[N],mn;
vector<int> to[N],prf[N],prg[N],suf[N],sug[N];
void delfa(int u, int fa)
{
	for (auto v : to[u]) if (v != fa) delfa(v, u);
	for (int i = 0; i < to[u].size(); ++i) if (to[u][i] == fa)
	{
		to[u].erase(to[u].begin() + i);
		break;
	}
}
void dfs1(int u)
{
	f[u] = g[u] = prf[u][0] = prg[u][0] = suf[u][to[u].size()] = sug[u][to[u].size()] = 0;
	for (int i = 0; i < to[u].size(); ++i)
	{
		int v = to[u][i];
		dfs1(v);
		if (!f[v] && !f[u]) chkmx(g[u], g[v] + 1);
		else if (f[v] && !f[u])
		{
			if (g[v] + 1 + g[u] <= d)
			{
				f[u] = f[v];
				g[u] = g[v] + 1;
			}
			else
			{
				f[u] = f[v] + g[v] + 1 + g[u] - d;
				g[u] = d - g[u];
			}
		}
		else if (!f[v] && f[u])
		{
			if (g[u] + g[v] + 1 > d)
			{
				f[u] += g[u] + g[v] + 1 - d;
				g[u] = d - g[v] - 1;
			}
		}
		else
		{
			f[u] += f[v] + g[u] + g[v];
			g[u] = 0;
		}
		prf[u][i + 1] = f[u];
		prg[u][i + 1] = g[u];
	}
	f[u] = g[u] = 0;
	for (int i = (int)to[u].size() - 1; i >= 0; --i)
	{
		int v = to[u][i];
		if (!f[v] && !f[u]) chkmx(g[u], g[v] + 1);
		else if (f[v] && !f[u])
		{
			if (g[v] + 1 + g[u] <= d)
			{
				f[u] = f[v];
				g[u] = g[v] + 1;
			}
			else
			{
				f[u] = f[v] + g[v] + 1 + g[u] - d;
				g[u] = d - g[u];
			}
		}
		else if (!f[v] && f[u])
		{
			if (g[u] + g[v] + 1 > d)
			{
				f[u] += g[u] + g[v] + 1 - d;
				g[u] = d - g[v] - 1;
			}
		}
		else
		{
			f[u] += f[v] + g[u] + g[v];
			g[u] = 0;
		}
		suf[u][i] = f[u];
		sug[u][i] = g[u];
	}
	if (!f[u] && g[u] >= d)
	{
		f[u] = 1;
		g[u] = 0;
	}
}
void dfs2(int u, int fa)
{
	for (int i = 0; i < to[u].size(); ++i)
	{
		int v = to[u][i];
		if (!prf[u][i] && !suf[u][i + 1])
		{
			f[u] = 0;
			g[u] = max(prg[u][i], sug[u][i + 1]);
		}
		else if (prf[u][i] && !suf[u][i + 1])
			if (prg[u][i] + sug[u][i + 1] <= d)
			{
				f[u] = prf[u][i];
				g[u] = prg[u][i];
			}
			else
			{
				f[u] = prf[u][i] + prg[u][i] + sug[u][i + 1] - d;
				g[u] = d - sug[u][i + 1];
			}
		else if (!prf[u][i] && suf[u][i + 1])
			if (prg[u][i] + sug[u][i + 1] <= d)
			{
				f[u] = suf[u][i + 1];
				g[u] = sug[u][i + 1];
			}
			else
			{
				f[u] = suf[u][i + 1] + prg[u][i] + sug[u][i + 1] - d;
				g[u] = d - prg[u][i];
			}
		else
		{
			f[u] = prf[u][i] + suf[u][i + 1] + prg[u][i] + sug[u][i + 1] - 1;
			g[u] = 0;
		}
		if (fa)
		{
			int v = fa;
			if (!f[v] && !f[u]) chkmx(g[u], g[v] + 1);
			else if (f[v] && !f[u])
			{
				if (g[v] + 1 + g[u] <= d)
				{
					f[u] = f[v];
					g[u] = g[v] + 1;
				}
				else
				{
					f[u] = f[v] + g[v] + 1 + g[u] - d;
					g[u] = d - g[u];
				}
			}
			else if (!f[v] && f[u])
			{
				if (g[u] + g[v] + 1 > d)
				{
					f[u] += g[u] + g[v] + 1 - d;
					g[u] = d - g[v] - 1;
				}
			}
			else
			{
				f[u] += f[v] + g[u] + g[v];
				g[u] = 0;
			}
		}
		if (!f[u] && g[u] >= d)
		{
			f[u] = 1;
			g[u] = 0;
		}
		chkmn(mn, max(1, f[u]) + max(1, f[v]));
		dfs2(v, u);
		f[v] = suf[v][0];
		g[v] = sug[v][0];
		if (!f[v] && g[v] >= d)
		{
			f[v] = 1;
			g[v] = 0;
		}
	}
}
bool OK()
{
	dfs1(1);
	mn = n + 1;
	dfs2(1, 0);
	return mn <= k;
}
void mian()
{
	for (int u = 1; u <= n; ++u) to[u].clear();
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &u, &v);
		to[u].push_back(v);
		to[v].push_back(u);
	}
	delfa(1, 0);
	for (int u = 1; u <= n; ++u)
	{
		prf[u].resize(to[u].size() + 1);
		prg[u].resize(to[u].size() + 1);
		suf[u].resize(to[u].size() + 1);
		sug[u].resize(to[u].size() + 1);
	}
	int low = 0,high = n - 1,res = n;
	while (low <= high)
	{
		d = (low + high) >> 1;
		if (OK()) res = d,high = d - 1;
		else low = d + 1;
	}
	printf("%d\n", res);
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int t;
	scanf("%*d%d", &t);
	while (t--) mian();
	return 0;
}