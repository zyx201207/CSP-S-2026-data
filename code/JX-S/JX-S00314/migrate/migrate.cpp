#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int a[N];
int n, d;
int ans = 0;

inline void dcha() {
	int df = a[2] - a[1];
	for (int i = 4; i <= n; i++) {
		if (2 * df <= d) ans++;
		else break;
	}
	cout << ans << '\n';
}
// int cnt, r;
// vector<int> v;
// inline void dfs() {
// 	if (cnt > 2) return;
// 	if (v.back() == r) {
// 		int len = v.size();
// 		for (int i = 1; i < len; i++) {
// 			if (v[i] - v[i - 1] > d) return;
// 		}
// 		for (int x : v) cout << x << " ";
// 		cout << '\n';
// 		cnt++;
// 		return;
// 	}
// 	for (int i = v.back() + 1; i <= r; i++) {
// 		v.push_back(i);
// 		dfs();
// 		v.pop_back();
// 	}
// }

inline void solve() {
	cin >> n >> d;
	ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	bool dengcha = 1;
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
			dengcha = 0;
			break;
		}
	}
	if (n >= 4 && dengcha) { 
		dcha();
		return;
	} else {
		cout << 0 << '\n';
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = i + 1; j <= n; j++) {
	// 		cout << '\n';
	// 		r = j;
	// 		v.clear();
	// 		v.push_back(i);
	// 		cnt = 0;
	// 		dfs();
	// 		if (cnt == 2) ans++;
	// 		if (cnt == 2) {
	// 			cerr << "i:" << i << " " << j << '\n';
	// 		}
	// 	}
	// }
	// cout << ans << '\n';
	// cerr << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int C, T;
	cin >> C >> T;
	while (T--) {
		solve();
	}
	return 0;
}