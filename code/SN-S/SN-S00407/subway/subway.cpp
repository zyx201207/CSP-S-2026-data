#include<bits/stdc++.h>
using namespace std;
constexpr int N = 500 + 7, M = 5e5 + 7;
constexpr long long inf = 0x3f3f3f3f3f3f3f3f;
int n, m, w[M];
struct edge {int to, val;}; vector<edge> g[M];
long long dis[N][N];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >>T >>n >>m >>T >>T;
	for(int i = 1; i <= m; ++i) cin >>w[i];
	for(int i = 1, k, j, t; i <= n; ++i) {cin >>k; while(k--) cin >>j >>t, g[j].push_back({i, t});}
	for(int i = 1; i <= n; ++i) memset(dis[i] + 1, 0x3f, n << 3), dis[i][i] = 0;
	for(int k = 1; k <= m; ++k) {
		const int s = g[k].size();
		for(int i = 0; i < s; ++i) for(int j = i + 1; j < s; ++j) {
			const int u = g[k][i].to, v = g[k][j].to; const long long w = g[k][i].val + g[k][j].val;
			dis[v][u] = dis[u][v] = min(dis[u][v], w);
		}
	}
	for(int k = 1; k <= n; ++k) for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(T--) {
		int x, y; cin >>x >>y;
		const int sx = g[x].size(), sy = g[y].size();
		long long res = inf;
		for(int i = 0; i < sx; ++i) for(int j = 0; j < sy; ++j) {
			const int u = g[x][i].to, v = g[y][j].to, w = g[x][i].val + g[y][j].val;
			res = min(res, dis[u][v] + w);
		}
		res += w[x] + w[y];
		cout <<res <<'\n';
	}
	return 0;
}
