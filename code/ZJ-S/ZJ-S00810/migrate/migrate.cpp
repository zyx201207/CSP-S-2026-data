#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+5, N1 = 5005, inf = 1e9;
int n, d, x[N];
int dis[N1][N1], cnt[N1][N1]; 
void build(int now);
void solve1();
void solvea();
void solve();
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios:: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t; cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
void solve1() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = inf;
			cnt[i][j] = 0;
		}
	}
	struct node {int pos, dis;};
	for (int k = 1; k <= n; k++) {
		queue <node> q;
		q.push({k, 0});
		dis[k][k] = 0, cnt[k][k] = 1;
		while (!q.empty()) {
			node now = q.front();
			q.pop();
			for (int i = now.pos + 1; i <= n; i++) {
				if (x[i] - x[now.pos] > d) {
					break;
				}
				int nd = now.dis + 1;
				if (nd < dis[k][i]) {
					dis[k][i] = nd;
					cnt[k][i]++;
					q.push({i, nd});
				} else if (nd == dis[k][i]) {
					cnt[k][i]++;
					if (cnt[k][i] <= 3) q.push({i, nd});
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (cnt[i][j] == 2) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
}
void solvea() {
	if (d <= x[3] - x[1]) cout << 0 << '\n';
	else cout << n - (d / x[2] - x[1]) - 1 << '\n';
}
void solve() {
	bool ok1 = 0, oka = 1;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (i > 2 && x[i] - x[i - 1] != x[i - 1] - x[i - 2]) oka = 0;
	}
	if (n <= 5000) {
		ok1 = 1;
	}
	
	if (ok1) {
		solve1();
	} else if (oka) {
		solvea();
	} else {
		cout << 0 << '\n';
	}
}
