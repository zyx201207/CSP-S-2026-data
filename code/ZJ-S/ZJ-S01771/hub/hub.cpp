// 100+100+40+15 不挂的话应该比较稳。

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

constexpr int N = 1e4 + 1, INF = 1e9;
vector<int> g[N];
int C, T, n, k;

namespace dsu {
	int _[N];

	void erase(int n) { for (int i = 1; i <= n; i ++) _[i] = i; }
	auto query(int u) -> int { return _[u] == u ? u : _[u] = query(_[u]); }
	bool combine(int u, int v) {
		u = query(u), v = query(v);
		return (_[u] = v) != u;
	}
}

namespace s1l {
	auto check() -> bool { return n <= 15; }

	int dis[N];

	auto solve() -> int {
		int ans = INF;
		for (int I = 0; I < (1 << n); I ++) {
			if (__builtin_popcount(I) != k) continue;
			dsu::erase(n);

			for (int i = 1; i <= n; i ++) {
				if (!((I >> (i - 1)) & 1)) continue;
				for (int v : g[i]) {
					if (!((I >> (v - 1)) & 1)) continue;
					dsu::combine(i, v);
				}
			}

			set<int> st;
			for (int i = 1; i <= n; i ++) {
				if (!((I >> (i - 1)) & 1)) continue;
				st.insert(dsu::query(i));
			}

			if (st.size() > 2) continue;

			priority_queue<pii, vector<pii>, greater<pii> > pq;
			for (int i = 1; i <= n; i ++) dis[i] = INF;
			for (int i = 1; i <= n; i ++)
				if ((I >> (i - 1)) & 1) pq.emplace(dis[i] = 0, i);

			while (!pq.empty()) {
				int d = pq.top().first, u = pq.top().second; pq.pop();
				if (dis[u] != d) continue;

				for (int v : g[u])
					if (dis[u] + 1 < dis[v])
						pq.emplace(dis[v] = dis[u] + 1, v);
			}

			int ret = 0;
			for (int i = 1; i <= n; i ++) ret = max(ret, dis[i]);
			ans = min(ans, ret);
		}

		return ans;
	}
}

auto main() -> signed {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (cin >> C >> T; T; T --) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++) g[i].clear();
		for (int i = 1, u, v; i < n; i ++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		if (s1l::check()) cout << s1l::solve() << '\n';
	}

	return 0;
}