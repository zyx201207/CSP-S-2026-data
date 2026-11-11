#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int c, t, n, d, a[N];
int dis[N], p[N];
queue<int> q;
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (c == 11 || c == 12) {
			int o = a[2] - a[1];
			d = d / o;
			if (d <= 1) {
				cout << 0 << endl;
				continue;
			}
			cout << max(0ll, n - (d + d - 1)) << endl;
			continue;
		}
		for (int i = 1; i <= n; i++) {
			memset(dis, 0x3f, sizeof dis);
			memset(p, 0x3f, sizeof p);
			q.push(i);
			dis[i] = 0;
			p[i] = 1;
			while (q.size()) {
				int u = q.front();
				q.pop();
				for (int v = u + 1; v <= n && a[v] - a[u] <= d; v++) {
					if (dis[v] > dis[u] + 1) {
						dis[v] = dis[u] + 1;
						p[v] = p[u];
						q.push(v);
					} else if (dis[v] == dis[u] + 1) {
						p[v] += p[u];
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				ans += (p[i] == 2);
			}
		}
		cout << ans << endl;
	} 
	return 0;
}
