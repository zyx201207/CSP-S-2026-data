#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5e5 + 7, MAXL = 507;
int c, n, m, d, q;
LL ans;
int w[MAXN];
LL dis[MAXL][MAXL];
vector<pair<int, int> > pass[MAXN];
int main() {
	//
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	//input
	scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) scanf ("%d", &w[i]);
	for (int i = 1, ki; i <= n; i++) {
		scanf("%d", &ki);
		for (int j = 1, ai, ti; j <= ki; j++) {
			scanf("%d%d", &ai, &ti);
			pass[ai].push_back(make_pair(i, ti));
		}
	}
	//build_new_map
	for (int i = 1; i <= 502; i++) for (int j = 1; j <= 502; j++) {
		dis[i][j] = 1e18;
		if(i == j) dis[i][j] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (auto it1:pass[i]) {
			for (auto it2:pass[i]) {
				if (it1 == it2) continue;
				int a1 = it1.first, a2 = it2.first;
				int t1 = it1.second, t2 = it2.second;
				dis[a1][a2] = min(dis[a1][a2], (long long)(t1 + t2));
			}
		}
	}
//	cout << dis[1][2] << endl;
	//min_road
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	//query
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		ans = 1e18 + 7;
		for (auto i:pass[x])
			for (auto j:pass[y]) {
				ans = min(ans, dis[i.first][j.first] + (long long)(i.second + j.second));
			}
		printf("%lld\n", ans + (long long)(w[x] + w[y]));
	}
	return 0;
}