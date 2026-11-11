#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 600005;
const int N = 505;
int n, m, cid, d, Q;
ll w[M], dis[N][N];
struct Edge {
	int to;
	ll val;
};
vector <Edge> E[M];
inline void floyd () {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	return;
}
int main () {
//	freopen ("subway7.in", "r", stdin);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	cin >> cid >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int sz;
		cin >> sz;
		while (sz--) {
			int id;
			ll t;
			cin >> id >> t;
			E[id].emplace_back (Edge {i, t});
		}
	}
	memset (dis, 0x3f, sizeof (dis));
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0ll;
	}
	for (int u = 1; u <= m; u++) {
		for (auto I : E[u]) {
			for (auto J : E[u]) {
				int x = I.to, y = J.to;
				ll val1 = I.val, val2 = J.val;
				dis[x][y] = min (dis[x][y], val1 + val2);
				dis[y][x] = min (dis[y][x], val1 + val2);
			}
		}
	}
	floyd ();
	while (Q--) {
		int l, r;
		cin >> l >> r;
		ll ans = 1000000000000000000ll;
		for (auto I : E[l]) {
			for (auto J : E[r]) {
				int x = I.to, y = J.to;
				ll val1 = I.val, val2 = J.val;
				ans = min (ans, dis[x][y] + val1 + val2);
			}
		}
		cout << ans + w[l] + w[r] << "\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
暴力建图 
发现地铁线路比较少 
我们可以把n个地铁线路缩成一个点 
就是询问任意两点之间的最短路 
看不见CE调试信息（有人把我的编译器调了导致我调编译器差点调不出来） 
暴力时间复杂度O(qmlogm)
我们设f[i][j]表示从地铁线路i到j的最短距离 
这个可以floyd跑全源最短路 
O(nq)可以AC 
我们考虑直接暴力找地铁站 
两边加起来最多400个 
预处理最短路之后可以快速查询 
总时间复杂度O(n^3+qd^2) 可以通过n<=500 q<=1e5 d<=20
已经想出正解 
*/
