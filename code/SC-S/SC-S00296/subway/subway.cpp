#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> dt[510], zt[20010];
vector<int> v;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	v.push_back(0);
	for (int i = 0, a; i < m; i++) {
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			dt[i].emplace_back(a, b);
			zt[a].emplace_back(i, b);
		}
	}
	while (q--) {
		int st, en;
		cin >> st >> en;
		queue<pair<pair<int, int>, int>> qq;
		qq.push({{st, -1}, v[st]});
		long long ans = LLONG_MAX;
		int num = 10000;
		int vis[20000] = {};
		while (!qq.empty() && (ans == LLONG_MAX || num--)) {
			auto [x, y] = qq.front();
			qq.pop();
			if (x.first == en) {
				ans = min(ans, 1ll * y + v[en]);
			}
			for (auto i : zt[x.first]) {
				for (auto j : dt[i.first]) {
					if (j.first == x.first) continue;
					if (vis[j.first] != 0 && vis[j.first] <= y + (x.second == i.first ? j.second - i.second : i.second + j.second)) continue;
					qq.push({{j.first, i.first}, y + (x.second == i.first ? j.second - i.second : i.second + j.second)});
					vis[j.first] = y + (x.second == i.first ? j.second - i.second : i.second + j.second);
				}
			}
		}
		cout << ans << '\n';
		while (!qq.empty()) qq.pop();
	}
	return 0;
}
/*
使用f[i][j]表示从i到j的最短时间然后用多源最短路求解
写不出来
写暴力算了
期望得分：32
*/