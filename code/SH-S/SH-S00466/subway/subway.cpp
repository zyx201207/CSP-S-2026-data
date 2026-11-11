#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500 * 20 + 5, M = 2e4 + 5;
struct Node {
	int v, line;
};
struct PQ {
	int dis, u, line, p;
};
vector<Node> g[N];
int w[M], k[N], T[501][M];
int test, n, m, d, q;

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> test >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		int last = 0;
		for (int j = 1; j <= k[i]; j++) {
			int x;
			cin >> x;
			cin >> T[i][x];
			if (last) {
				g[last].push_back({x, i});
				g[x].push_back({last, i});
			}
			last = x;
		}
	}
	while (q--) {
		int s, t;
		cin >> s >> t;
		queue<PQ> q;
		q.push({0, s, 0, -1});
		int ans = LLONG_MAX;
		unordered_map<string, bool> vis;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			int u = cur.u, l1 = cur.line, p = cur.p, dis = cur.dis;
			for (auto e : g[u]) {
				int v = e.v, l2 = e.line, val = 0;
				string str = to_string(l1) + " " + to_string(l2) + " " + to_string(u) + " " + to_string(v);
				if (v == p || vis[str]) continue;
//				cout << "lines: " << l1 << ' ' << l2 << endl;
				if (l1 == 0) {
					val = T[l2][u];
//					cout << "directly " << l2 << ',' << u << endl;
				} else if (l1 != l2 && l1 != 0) {
					val = T[l2][u] + T[l1][u];
//					cout << "added " << l1 << ',' << u << " " << l2 << ',' << u << endl;
				}
				if (v == t) {
					val += T[l2][v];
//					cout << "arrive\n";
					ans = min(ans, dis + val);
//					cout << u << " --> " << v << ": " << dis + val << ", val = " << val << endl;
					continue;
				}
				vis[str] = true;
				q.push({dis + val, v, l2, u});
//				cout << u << " --> " << v << ": " << dis + val << ", val = " << val << endl;
			}
		}
		cout << ans + w[s] + w[t] << '\n';
	}
	return 0;
}

// 1-6
// 6/25 -> 24/100
