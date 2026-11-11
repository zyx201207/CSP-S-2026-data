/*
地铁有站口，站厅，站台
给定若干条线路，线路上的每个站台到站厅的距离都给出
多次询问两个点之间的最短步行距离
首先站口步行一定是 w_start + w_end，可以不再考虑
然后可以理解为把每个站台看成一个点，把每个站厅看成一个点
同一路线的站台的距离为 0，站台与对应站厅的距离已知
然后多次求最短路
考虑同一路线距离为 0 的问题可以用虚点优化建图
然后观察到路线的数量较少，所以可以求出每个虚点为起点的最短路
然后对于每次询问，枚举一个虚点作为中转点即可
一定要注意数组开小的问题
意识到一个问题，不能支持 500 次 n log n 的最短路，只能支持 O(1) 次
但是发现每个站厅最多只与 20 个站台连接
这启示我们可以计算路线与路线之间的最短路
先用 N * 20 * 20 的代价算出一个 dis[500][500]
然后使用 floyd 算出
最后查询时枚举 20 * 20 即可
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 1.1e6, inf = 1e17;
int C, n, m, d, u, w[N], f[505][505];
vector<pair<int, int> > v[N];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> C >> n >> m >> d >> u;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int o = 1, k; o <= n; ++o) {
		cin >> k;
		for (int i = 1, pos, d; i <= k; ++i)
			cin >> pos >> d, v[pos].push_back({o, d});
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j)
				f[i][j] = inf;
	for (int i = 1; i <= m; ++i)
		for (const pair<int, int> &x : v[i])
			for (const pair<int, int> &y : v[i])
				f[x.first][y.first] = min(f[x.first][y.first], x.second + y.second);
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for (int o = 1, i, j; o <= u; ++o) {
		cin >> i >> j;
		int ans = inf;
		for (const pair<int, int> &x : v[i])
			for (const pair<int, int> &y : v[j])
				ans = min(ans, w[i] + w[j] + x.second + y.second + f[x.first][y.first]);
		cout << ans << '\n';
	}
	return 0;
}