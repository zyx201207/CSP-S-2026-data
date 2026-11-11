#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 5;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
int a[MAXN];
namespace SUBTASK1 {
	int dist[5005];
	int cnt[5005];
	bool vst[5005];
	struct node {
		int u, dis;
		inline bool operator < (const node& b) const {
			return dis > b.dis;
		}
	};
	int n, d;
	inline void Dij(const int& x, int& ans) {
		dist[x] = 0;
		cnt[x] = 1;
		priority_queue<node> que;
		que.push({x, 0});
		while (!que.empty()) {
			auto u = que.top().u;
			que.pop();
//			cerr << u << '\n';
			if (vst[u]) continue;
//			cerr <<"cur " <<u << '\n';
			vst[u] = 1;
//			for (int i = 1; i < n; ++i) {
//				if (dist[u] == dist[i] + 1)
//					cnt[u] += cnt[i];
//			}
			for (int v = 1; v <= n; ++v) {
				if (abs(a[u] - a[v]) > d || v > n ||v == u) continue;
				if (dist[v] > dist[u] + 1) {
					dist[v] = dist[u] + 1;
//					cnt[v] = cnt[u];
					cnt[v] = 0;
					que.push({v, dist[v]});
				}  if (dist[v] == dist[u] + 1)
					cnt[v] += cnt[u];
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (cnt[i] > 2) break;
			if (cnt[i] == 2) ++ans;
		}
//		for (int i= 1; i <= n; ++i) {
//			cerr << dist[i] << ' ' << cnt[i] << '\n';
//		}
//		cerr << '\n';
	}

	void solve() {
//		cerr << '\n';
		cin >> n >> d;
		if (n > 300) return;
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				dist[j] = INF, cnt[j] = 0, vst[j] = 0;
			Dij(i, ans);
		}
		cout << ans / 2 << '\n';
	}
	void main() {
		int T;
		cin >> T;
		while (T--)
			solve();
		exit(0);
	}
}
namespace SUBTASK2 {
	int n, d;
	void solve() {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)
		cout << 0 << '\n';
	}
	void main() {
		int T;
		cin >> T;
		while (T--)
			solve();
		exit(0);
	}
}
signed main() {
#ifndef DEBUG
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
#else
//	freopen(".\\migrate\\migrate1.in", "r", stdin);
#endif
	int c;
	cin >> c;
	if (c <= 10)
		SUBTASK1::main();
	else if (c == 13 || c== 14)
		SUBTASK2::main();
	return 0;
}