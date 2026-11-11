#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int c, t, n, d, a[N], b[N], e[N], ans, dp[N], dis[N];

void bfs(int x) {
	queue<int>pq;
	pq.push(x);
	for (int i = 1; i <= n; i++) {
		dis[i] = N;
		dp[i] = 0;
	}
	dis[x] = 0;
	dp[x] = 1;

	while (pq.size()) {
		int u = pq.front();
		pq.pop();
		for (int i = u + 1; i <= n && a[i] - a[u] <= d; i++) {
			if (dis[i] > dis[u] + 1) {
				dis[i] = dis[u] + 1;
				dp[i] = dp[u];
				pq.push(i);
			} else if (dis[i] == dis[u] + 1) {
				dp[i] += dp[u];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i] == 2) {
			ans++;
		}
		//	cout << dp[i] << ' ';
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			bfs(i);
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/