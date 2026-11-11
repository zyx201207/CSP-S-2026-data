#include<iostream>
#include<cstring>
#include<vector>
#define int long long
#define gc getchar
#define pc putchar
using namespace std;
int rd() {
	int res = 0, c = gc();
	bool f = false;
	while (c < 48 || c > 57) {
		if (c == 45) f = true;
		c = gc();
	}
	while (48 <= c && c <= 57) res = (res << 3) + (res << 1) + (c ^ 48), c = gc();
	if (f) return -res;
	return res;
}
void wr(int x) {
	if (x > 9) wr(x / 10);
	pc(x % 10 + 48);
}
//bool st;
const int maxm = 5e5 + 5;
const int maxn = 505;
const int inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;
int w[maxm];
int a[maxm];
int v[maxm];
int dis[maxn][maxn];
struct edge {
	int v, w;
};
vector<edge> g[maxm];
//bool nd;
signed main() {
//	cerr << &st - &nd;
//	cerr << inf;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = rd(), n = rd(), m = rd(), d = rd(), q = rd();
	for (int i = 1; i <= m; i ++) w[i] = rd();
	for (int i = 1; i <= n; i ++) {
		int k = rd();
		for (int j = 1; j <= k; j ++) {
			int v = rd(), w = rd();
			g[v].push_back((edge) {i, w});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i ++) dis[i][i] = 0;
	for (int i = 1; i <= m; i ++) {
		int k = g[i].size();
		for (int x = 0; x < k; x ++) for (int y = 0; y < x; y ++) {
			int &d1 = dis[g[i][x].v][g[i][y].v], &d2 = dis[g[i][y].v][g[i][x].v];
			d1 = min(d1, g[i][x].w + g[i][y].w);
			d2 = min(d2, g[i][x].w + g[i][y].w);
		}
	}
//	for (int i = 1; i <= n; i ++, pc('\n')) for (int j = 1; j <= n; j ++) {
//		wr(dis[i][j]), pc(' ');
//	}
	for (int k = 1; k <= n; k ++) for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//	for (int i = 1; i <= n; i ++, pc('\n')) for (int j = 1; j <= n; j ++) {
//		wr(dis[i][j]), pc(' ');
//	}
//	for (int i = 1; i <= m; i ++) {
//		int k = g[i].size();
//		for (int x = 0; x < k; x ++) {
//			wr(g[i][x].v), pc(' ');
//		}
//		pc('\n');
//	}
	while (q --) {
		int x = rd(), y = rd(), ans = inf;
		for (int i = 0; i < g[x].size(); i ++) for (int j = 0; j < g[y].size(); j ++) {
			int v1 = g[x][i].v, v2 = g[y][j].v, w1 = g[x][i].w, w2 = g[y][j].w;
//			wr(v1), pc(' '), wr(v2), pc(' '), wr(w1), pc(' '), wr(w2), pc('\n');
			ans = min(ans, w1 + w2 + dis[v1][v2]);
		}
		ans += w[x] + w[y];
		wr(ans), pc('\n');
	}
}

