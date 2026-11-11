#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 1;
int tid, tests, n, mxd;
int x[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> tid >> tests;
	while (tests--) {
		cin >> n >> mxd;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		int ans = 0;
		for (int s = 1; s < n; s++) {
			for (int t = s + 1; t <= n; t++) {
//				cout << "s, t: " << s << "," << t << endl;
				int mn = LLONG_MAX;
				unordered_map<int, int> mp;
				queue<pair<int, int>> q;
				q.push({s, 0});
				while (!q.empty()) {
					auto cur = q.front();
					int u = cur.first, steps = cur.second;
					q.pop();
					for (int v = u + 1; v <= t; v++) {
						if (x[v] - x[u] > mxd) break;
						if (v == t) {
							mp[steps]++;
							mn = min(mn, steps);
						}
						else q.push({v, steps + 1});
					}
				}
				if (mp[mn] == 2) {
//					cout << "GOOD!\n";
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

// 1-2
// 2/25 -> 8/100
