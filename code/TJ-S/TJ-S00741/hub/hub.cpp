// RP ++;
// by MLE_Automaton
// subscribe MLE_Automaton please
// jodio9 yao bao sha wo le
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),END##i=(b);i<=END##i;++i)
#define pre(i,a,b) for(int i=(a),END##i=(b);i>=END##i;--i)
#define pb push_back
using namespace std;
typedef long long ll;
template<typename T> inline void chmin(T &x, T y) { x = min(x, y); }
template<typename T> inline void chmax(T &x, T y) { x = max(x, y); }

constexpr int N = 1e6 + 5;
// 0: making block; 1: first block finished; 2:
int T, n, m, vis[N]; vector<int> g[N];
void dfs(int u, int fa, int qwq)
{
	if (!(qwq >> (u - 1) & 1)) return;
	vis[u] = 1;
	rep(i, 0, g[u].size() - 1)
	{
		int v = g[u][i];
		if (v != fa) dfs(v, u, qwq);
	}
}
void dfs2(int u, int fa, int qwq)
{
	if (qwq >> (u - 1) & 1) vis[u] = 0;
	else if (fa) chmin(vis[u], vis[fa] + 1);
	rep(i, 0, g[u].size() - 1)
	{
		int v = g[u][i];
		if (v != fa) dfs2(v, u, qwq);
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%*d%d", &T);
	while (T --)
	{
		scanf("%d%d", &n, &m);
		rep(i, 1, n) g[i].clear();
		rep(i, 2, n)
		{
			int u, v; scanf("%d%d", &u, &v);
			g[u].pb(v); g[v].pb(u);
		}
		int ans = 114514;
		rep(i, 0, (1 << n) - 1)
		{
			if (__builtin_popcount(i) != m) continue;
			rep(j, 1, n) vis[j] = 0;
			int cnt = 0;
			rep(j, 1, n) if ((i >> (j - 1) & 1) && !vis[j]) dfs(j, 0, i), ++ cnt;
			if (cnt > 2) continue;
			rep(j, 1, n) vis[j] = 114514;
			rep(j, 1, n) dfs2(j, 0, i);
			int res = 0;
			rep(j, 1, n) chmax(res, vis[j]);
			chmin(ans, res);
		}
		printf("%d\n", ans);
	}
	return 0;
}

