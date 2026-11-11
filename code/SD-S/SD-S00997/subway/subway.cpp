// รปีÞมห  
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
const int N = 505, M = 5e5 + 5, INF = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[M], k[N], ex[M][N], dist[N];
bool vis[N];
vector<int> a[N], t[N], e[M];
//int dfs(int u) {
//	for (int v : e[u]) {
//		
//	}
//}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++ ) {
		cin >> w[i];
	}
	for (int i = 1, na, nt; i <= n; i ++ ) {
		cin >> k[i] >> na >> nt;
		a[i].push_back(0);
		t[i].push_back(0);
		ex[na][i] = nt;
		int las = na, lasw = nt;
		for (int j = 2; j <= k[i]; j ++ ) {
			cin >> na >> nt;
			a[i].push_back(na);
			t[i].push_back(nt);
			e[las].push_back(na);
			ex[na][i] = nt;
		}
	}
	while (q -- ) {
//		memset(dist, 0, sizeof(dist));
		int x, y, ans = 0;
		cin >> x >> y;
		cout << w[x] + w[y] << "\n";
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
*/
