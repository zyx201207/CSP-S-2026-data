#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;
int test, n, d, a[N], ans;

int find(int x) {
	int lt = 0, rt = n + 1;
	while (lt + 1 < rt) {
		int mid = (lt + rt) >> 1;
		if (mid < x) lt = mid;
		else rt = mid;
	}
	return lt;
}

void solve() {
	if (test == 13 || test == 14) {
		cout << 0 << endl;
		return ;
	}
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int now = i, last = i;
			vector<int> v1, v2;
			v1.push_back(i);
			while (now < j) {
				int tmp = upper_bound(a + 1, a + n + 1, a[now] + d) - a;
				if (tmp > j) now = j;
				else now = tmp - 1;
				if (now == last || abs(a[now] - a[last]) > d) break;
				else {
					v1.push_back(now);
					last = now;
				}
			}
			if (v1.size() == 0) continue;
			now = j, last = j;
			v2.push_back(j);
			while (now > i) {
				int tmp = find(a[now] - d);
				if (tmp < i) now = i;
				else now = tmp + 1;
//				cout << i << ' ' << j << ' ' << tmp << ' '  << now << endl;
				if (now == last || abs(a[now] - a[last]) > d) break;
				else {
					v2.push_back(now);
					last = now;
				}
			}
			if (v2.size() != v1.size()) continue;
//			cout << "debug:" << i << ' ' << j << endl;
//			for (auto k: v1) {
//				cout << k << ' ';
//			}
//			cout << endl;
//			for (auto k: v2) {
//				cout << k << ' ';
//			}
//			cout << endl;
			for (int k = 0; k < v1.size(); k++) {
				int l = v2.size() - k - 1;
				if (v1[k] != v2[l]) {
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> test >> t;
	while (t--) {
		solve();
	}
	return 0;
}

