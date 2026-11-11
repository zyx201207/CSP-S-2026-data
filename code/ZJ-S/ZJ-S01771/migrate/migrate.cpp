// 这次一等线不会很高吧 w
// 最短的双径岛屿对 只有 U -> u1 -> v1/v2 -> u2 -> V 一种
// |id_v2 - id_v1| == 1 枚举中间算两边
// 好吧到此为止，我不会。

#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

constexpr int N = 2e6 + 10, INF = 1e18;
int C, T, n, d, A[N], a[N];

namespace s1l {
	auto check() -> bool { return n <= 1000; }

	vector<int> g[N];
	int dis[N], cnt[N];

	void dijkstra(int s) {
		for (int i = 1; i <= n; i ++) dis[i] = INF, cnt[i] = 0;
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		pq.emplace(dis[s] = 0, s), cnt[s] = 1;

		while (!pq.empty()) {
			auto d = pq.top().first, u = pq.top().second; pq.pop();
			if (d != dis[u]) continue;

			for (auto v : g[u])
				if (d + 1 < dis[v]) {
					pq.emplace(dis[v] = d + 1, v);
					cnt[v] = cnt[u];
				} else if (d + 1 == dis[v])
					cnt[v] += cnt[u];
		}
	}

	auto solve() -> int {
		for (int i = 1; i <= n; i ++) g[i].clear();
		for (int i = 1; i <= n; i ++)
			for (int j = i + 1; j <= a[i]; j ++)
				g[i].push_back(j);

		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			dijkstra(i);
			for (int j = 1; j <= n; j ++)
				if (cnt[j] == 2) ans ++;
		}

		return ans;
	}
}

auto main() -> signed {
	// freopen("migrate.in", "r", stdin);
	// freopen("migrate.out", "w", stdout);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (cin >> C >> T; T; T --) {
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) cin >> A[i];

		A[n + 1] = LLONG_MAX;
		for (int i = 1, j = 1; i <= n; i ++) {
			while (j <= n && A[j] - A[i] <= d) j ++;
			a[i] = j - 1;
		}

		if (s1l::check()) cout << s1l::solve() << '\n';
	}

	return 0;
}