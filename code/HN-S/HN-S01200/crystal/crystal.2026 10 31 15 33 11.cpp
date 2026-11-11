#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n, m, l, r, ans;
ll a[N], p[N];
void solve_mA() {
	int res = 0;
	for (int j = n - 1; j && res <= m; j --) {
		ans = (n - j + 1);
		res += a[n] - a[j];
	}
}
void solve_mB() {
	int res = 0;
	for (int j = n - 1; j && res <= m; j --) {
		ans = (n - j + 1);
		res += a[n] - a[j];
	}
}
void solve_45pts() {
	for (int i = 1; i <= n; i ++) {
		int res = 0;
		for (int j = i - 1; j; j --) {
			res += a[i] - a[j];
			if (res <= m) {
				ans = max(ans, i - j + 1);
			} else 
				break;
		}
	}
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	while (t --) {
		bool mA = 1, mB = 1;
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			if (i > 1 && a[i] - a[i - 1] != 1) {
				mA = 0;
			}
			if (i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) {
				mA = mB = 0;
			}
		}
		sort(a + 1, a + 1 + n);
		if (mA) {
			solve_mA();
		} else if (mB) {
			solve_mB();
		} else {
			solve_45pts();
		}
//		while (l <= r) {
//			int mid = (l + r) >> 1;
//			if (check(mid)) {
//				
//			} else {
//				
//			}
//		}
		// a[1];
		cout << ans;
	}
	return 0;
}

