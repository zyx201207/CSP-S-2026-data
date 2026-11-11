#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename _Tp1, typename _Tp2> inline bool chkmn(_Tp1&x, const _Tp2&y) {return y < x && (x = y, 1);}
constexpr int N = 509;
constexpr int D = 21;
constexpr int M = 5e5+9;
constexpr ll INF = 1e18;
int n,m,q,w[M],k,a,t,b,nL[M];
struct Line {int id,t;} line[M][D];
ll d[N][N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%*d%d%d%*d%d", &n, &m, &q);
	for (int i = 1; i <= m; ++i) scanf("%d", &w[i]);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &k);
		while (k--)
		{
			scanf("%d%d", &a, &t);
			line[a][++nL[a]] = (Line){i, t};
		}
	}
	for (int u = 1; u <= n; ++u) for (int v = 1; v <= n; ++v) d[u][v] = (u == v ? 0 : INF);
	for (int k = 1; k <= m; ++k) for (int i = 1; i <= nL[k]; ++i) for (int j = 1; j <= nL[k]; ++j) chkmn(d[line[k][i].id][line[k][j].id], line[k][i].t + line[k][j].t);
	for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) chkmn(d[i][j], d[i][k] + d[k][j]);
	while (q--)
	{
		scanf("%d%d", &a, &b);
		ll ans = INF;
		for (int i = 1; i <= nL[a]; ++i) for (int j = 1; j <= nL[b]; ++j) chkmn(ans, d[line[a][i].id][line[b][j].id] + w[a] + w[b] + line[a][i].t + line[b][j].t);
		printf("%lld\n", ans);
	}
	return 0;
}