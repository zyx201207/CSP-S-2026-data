#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 2e6 + 10;
int c, t, n, d;
int a[maxn];
struct node {
	int v, step;
};
bool check (int l, int r) {
	queue <node> q;
	q.push({l, 0});
	int minn = -1, cnt = 0;
	while (!q.empty()) {
		node u = q.front();
//		if (l == 1 && r == 4) {
//			cout << u.v << " " << u.step << endl;
//		}
		q.pop();
		if (cnt > 2) break;
		if (u.v == r) {
//			if (l == 1 && r == 4) cout << "___";
			if (minn == -1) minn = u.step;
			if (u.step == minn) cnt ++;
			continue;
		}
		for (int i = u.v + 1; i <= r; i ++) {
			if (a[i] - a[u.v] <= d) {
//				if (l == 1 && r == 4 && i == 4) cout << u.v << " " << i << " " << u.step + 1 << endl;
				q.push({i, u.step + 1});
			}
		}
	}
//	if (l == 1 && r == 4) cout << cnt << endl;
	if (cnt == 2) return 1;
	return 0;
}
signed main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t --) {
		cin >> n >> d;
		int ans = 0;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		if (n <= 5000) {
			for (int l = 1; l <= n; l ++) {
				for (int r = l + 1; r <= n; r ++) {
					if (check(l, r)) {
//					cout << l << " " << r << endl;
						ans ++;
					}
				}
			}
			cout << ans << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}


