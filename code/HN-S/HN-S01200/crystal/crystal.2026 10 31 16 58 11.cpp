#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define deb(x) cerr << #x << ":" << x << " "
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n, m, l, r, ans;
ll a[N], b[N];
void solve_mA() {
	cerr << "mA" << "\n";
	int res = 0;
	for (int j = n - 1; j && res <= m; j --) {
		ans = (n - j + 1);
		res += a[n] - a[j];
	}
}
void solve_mB() {
	cerr << "mB" << "\n";
	int res = 0;
	for (int j = n - 1; j && res <= m; j --) {
		ans = (n - j + 1);
		res += a[n] - a[j];
	}
}
void solve_45pts() {
	cerr << "45" << "\n";
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
bool check(int x) {
	for (int i = x + 1; i <= n; i ++) {
		int res = x * a[i] - (b[i] - b[i - x - 1]);
//		deb(x), deb(i), deb(res), cerr << "\n";
		if (res <= m) {
			return 1;
		}
	}
	return 0;
}
void solve_100pts() {
	for (int i = 1; i <= n; i ++) {
		b[i] = a[i] + b[i - 1];
	}
	int L = 0, R = n; // Will add the 1 at the end
	while (L + 1 < R) {
		int mid = (L + R) >> 1;
		if (check(mid)) {
			// if it is able to do it then +
			L = mid;
		} else {
			R = mid;
		}
	}
	ans = L;
	for (int i = 1; i <= n; i ++) {
		if (i * a[i] - b[i] <= m) 
			ans = max(ans, i);
//		deb(i), deb(check(i)), cerr << "\n";
	}
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int t = 1;
	while (t --) {
//		bool mA = 1, mB = 1;
		cin >> n >> m >> a[1] >> a[2];
//		int c = a[2] - a[1], d = c;
		for (int i = 3; i <= n; i ++) {
			cin >> a[i];
//			c = a[i] - a[i - 1];
//			if (c != d && i != n) {
//				mB = 0;
//				deb(n), deb(i), deb(c), deb(d) , deb(a[i]), deb(a[i - 1]), deb(a[i - 2]);
//				cerr << "\n";
//			} 
//			d = c;
		}
		sort(a + 1, a + 1 + n);
//		if (mA) {
//			solve_mA();
//		} else 
//		if (mB) {
//			solve_mB();
//		} else {
//			solve_45pts();
//		}
//		while (l <= r) {
//			int mid = (l + r) >> 1;
//			if (check(mid)) {
//				
//			} else {
//				
//			}
//		}
		// a[1];
		solve_100pts();
		cout << ans;
	}
	return 0;
}

