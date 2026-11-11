#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, t;
int n, d;
int x[2000005];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
				q.push({0, i});
				priority_queue<int, vector<int>, greater<int> > cnt;
				while (!q.empty()) {
					int u = q.top().second, w = q.top().first;
					q.pop();
					if (u == j) {
						cnt.push(w);
						continue;
					}
					for (int k = u + 1; k <= j; k++) {
						if (x[k] - x[u] > d) {
							break;
						}
						q.push({w + 1, k});
					}
				}
				if (cnt.size() >= 2) {
					int x = cnt.top();
					cnt.pop();
					int y = cnt.top();
					cnt.pop();
					if (x != y) {
						continue;
					}
					if (cnt.empty()) {
						ans++;
					} else {
						int z = cnt.top();
						if (z != x) {
							ans++;
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}