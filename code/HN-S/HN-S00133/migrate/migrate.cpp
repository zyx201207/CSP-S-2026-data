#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
int c, t, n, d, x[N], ans[N], cnt[N], vis[N];
struct heap {
	int now, step;
	bool operator < (const heap &x) const {
		return now > x.now;
	}
};
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int qwq = 0;
		vector <int> a[N];
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (x[j] - x[i] <= d)
					a[i].push_back(j);
		for (int i = 1; i <= n; i++) {
			priority_queue <heap> q;
			for (int j = 1; j <= n; j++)
				ans[j] = INT_MAX, cnt[j] = 1, vis[j] = 0;
			ans[i] = 0;
			q.push({i, 0});
			while (!q.empty()) {
				int u = q.top().now, st = q.top().step;
				q.pop();
				if (vis[u] || st != ans[u]) continue;
				vis[u] = 1;
				for (int v : a[u]) {
					if (ans[v] > ans[u] + 1) {
						ans[v] = ans[u] + 1;
						cnt[v] = cnt[u];
						if (!vis[v])
							q.push({v, ans[v]});
					}
					else if (ans[v] == ans[u] + 1) {
						cnt[v] += cnt[u];
						if (!vis[v])
							q.push({v, ans[v]});
					}
				}
			}
			for (int j = i + 1; j <= n; j++)
				qwq += (cnt[j] == 2);
		}
		cout << qwq << '\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
