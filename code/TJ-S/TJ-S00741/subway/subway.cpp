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
// wo de xi shu hao da za ban za ban
// nice ac at 15:24
// difficulty prediction: upper green/lower cyan?
constexpr int N = 5e5 + 5;
constexpr ll INF = 0x3f3f3f3f3f3f3f3fll;
struct edge
{
	int v; ll w;
};
int n, m, d, q, w[N]; ll f[505][505]; vector<edge> g[N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%*d%d%d%d%d", &n, &m, &d, &q);
	rep(i, 1, m) scanf("%d", &w[i]);
	rep(i, 1, n)
	{
		int l; scanf("%d", &l);
		rep(j, 1, l)
		{
			int v; ll ww; scanf("%d%lld", &v, &ww);
			g[v].pb({i, ww});
		}
	}
	rep(i, 1, n) rep(j, 1, n) f[i][j] = (i != j) * INF;
	rep(i, 1, m)
	{
		int sz = g[i].size();
		rep(j, 0, sz - 2) rep(k, j + 1, sz - 1) chmin(f[g[i][j].v][g[i][k].v], g[i][j].w + g[i][k].w);
	}
	rep(i, 1, n - 1) rep(j, i + 1, n) f[i][j] = f[j][i] = min(f[i][j], f[j][i]);
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) chmin(f[i][j], f[i][k] + f[k][j]);
	while (q --)
	{
		int x, y; scanf("%d%d", &x, &y);
		ll res = INF;
//		for (auto [u, w1] : g[x]) for (auto [v, w2] : g[y]) chmin(res, f[u][v] + w1 + w2);
		rep(i, 0, g[x].size() - 1) rep(j, 0, g[y].size() - 1) chmin(res, f[g[x][i].v][g[y][j].v] + g[x][i].w + g[y][j].w);
		printf("%lld\n", res + w[x] + w[y]);
	}
	return 0;
}

