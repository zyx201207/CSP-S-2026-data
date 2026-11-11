#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
const int N = 2e6 + 5, M = 300 + 5;
int c, t, n;
ll x[N];
ll d, ans;
ll g[M][M];
int cnt[M][M];
void Ciallo () {
	cin >> n >> d;
	ans = 0;
	if (c <= 6) {
//		for (int i = 1; i <= n; ++i) {
//			g[i].clear();
//			in[i] = 0;
//			cnt[i] = 0;
//			dis[i] = 4e18;
//		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				g[i][j] = 2e18;
				cnt[i][j] = 1;
			}
		}
		for (int i = 1; i <= n; ++i) {
			cin >> x[i];
			g[i][i] = 0;
			for (int j = 1; j < i; ++j) {
				if (x[i] - x[j] <= d) {
					g[j][i] = 1;
				}
			}
		}
//		for (int i = 1; i <= n; ++i) {
//			cin >> x[i];
//			for (int j = 1; j < n; ++j) {
//				if (x[i] - x[j] <= d) {
//					g[j].emplace_back(i, x[i] - x[j]);
//					++in[j];
//				}
//			}
//		}
//		queue<int> q;
//		for (int i = 1; i <= n; ++i) {
//			if (!in[i]) {
//				q.push(i);
//				cnt[i] = 1;
//				dis[i] = 0;
//			}
//		}
//		while (!q.empty()) {
//			int u = q.front();
//			q.pop();
//			for (pii i : g[u]) {
//				int v = i.first, w = i.second;
//				if (dis[v] > dis[u] + w) {
//					dis[v] = dis[u] + w;
//					cnt[v] = 1;
//				}
//				else if (dis[v] == dis[u] + w) {
//					cnt[v] += cnt[u];
//				}
//				if (!--in[v]) {
//					q.push(v);
//				}
//			}
//		}
//		for (int i = 1; i <= n; ++i) {
//			
//		}
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i < k; ++i) {
				for (int j = k + 1; j <= n; ++j) {
					if (g[i][j] > g[i][k] + g[k][j]) {
						g[i][j] = g[i][k] + g[k][j];
						cnt[i][j] = 1;
					}
					else if (g[i][j] == g[i][k] + g[k][j]) {
						cnt[i][j] += cnt[i][k] * cnt[k][j];
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (cnt[j][i] == 2) {
					++ans;
				}
			}
		}
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j < i; ++j) {
//				cerr << g[j][i] << " \n"[j == i - 1];
//			}
//		}
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j < i; ++j) {
//				cerr << cnt[j][i] << " \n"[j == i - 1];
//			}
//		}
		cout << ans << '\n';
		return;
	}
	else {
		cout << 0 << '\n';
	}
}
int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		Ciallo();
	}
	return 0;
}