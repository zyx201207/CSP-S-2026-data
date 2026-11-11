/*
15:14 最大点 windows下跑 0.4s，但是 linux 上要跑 2s 喵
      虽然相信 CCF 评测机的性能，但还是卡一卡常数吧喵
好吧我居然没关同步喵……
15:18 关同步之后 linux 上只跑了 0.5s 喵……
*/
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

#define il inline
#define cstex constexpr
#define endl '\n'
#define frer(filename) assert(freopen(filename, "r", stdin))
#define frew(filename) assert(freopen(filename, "w", stdout))

using ll = int64_t;

cstex ll inf = 0x3f3f3f3f3f3f3f3f;
cstex int N = 500, M = 5e5, XN = N + 10, XM = M + 10;
int FW_NUMBER, n, m, d, q, a[XM];
vector<pair<int, int>> b[XM];
ll g[XN][XN];

int main() {
	frer("subway.in"), frew("subway.out");
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> FW_NUMBER >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1, k, v, w; i <= n; i++)
		for (cin >> k; k --> 0; )
			cin >> v >> w, b[v].emplace_back(i, w);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) g[i][j] = i == j ? 0 : inf;
	for (int i = 1; i <= m; i++)
		for (pair<int, int> u : b[i]) for (pair<int, int> v : b[i])
			g[u.first][v.first] = min(g[u.first][v.first], ll(u.second + v.second));
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
	while (q --> 0) {
		int u, v; cin >> u >> v; ll res = inf;
		for (pair<int, int> i : b[u]) for (pair<int, int> j : b[v])
			res = min(res, g[i.first][j.first] + i.second + j.second);
		cout << res + a[u] + a[v] << endl;
	}
	return 0;
}
