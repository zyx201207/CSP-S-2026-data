#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, minn = LONG_LONG_MAX, maxx = LONG_LONG_MIN, sum, num;
ll a[500005] ;
bool f;

bool check(int x) {
	num = 0;
	f = 1;
	for (ll i = 1; i <= n; i++) {
		if (a[i] > x) {
			f = 1;
			break;
		}
		sum = max(sum, i);
		num += (x - a[i]);
		if (num > m) {
			f = 0;
			break;
		}

	}
	return f;
}

int main() {
	freopen("crystal4 .in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		minn = min(minn, a[i]);
		maxx = max(maxx, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			f = 1;
		}
	}
	if (f == 0) {
		cout << n;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	ll l = minn, r = maxx, mid;
	while (l < r) {
		mid = (l + r) / 2 ;
		if (check(mid)) {
			l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << sum;
	return 0;
}