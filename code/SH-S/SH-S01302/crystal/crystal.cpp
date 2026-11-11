#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 5;

int n;
ll m, ans, a[N];

int check(int p) {
	ll op = 0;
	int res = 0;
	for (int i = 1; i < p; ++i) {
		ll diff = a[p] - a[i];
		if (LONG_LONG_MAX - op < diff) {
			return -1;
		}
		op += diff;
		if (op > m) {
			return -1;
		}
		++res;
		// test
			// cout << op << " " << res << "\n";
	}
	return res + 1; // ¼ÓÉÏ p Ë®¾§ 
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n + 1);
	ll l = 1, r = n, ans = 0;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		// test
			// cout << mid << ":\n";
		int res = check(mid);
		if (res != -1) {
			ans = res;
			for (int i = mid + 1; a[i] == a[mid]; ++i) {
				ans += 1;
			}
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
} 
