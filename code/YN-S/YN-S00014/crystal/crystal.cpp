#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll N = 1000010;
const ll INF = 0x3f3f3f3f;
ll n, a[N], d[N], ans = -INF;
ull m;

void calc() {
	ll delta;
	delta = a[2] - a[1];
	if (delta < 0)
		delta = -delta;
	if (delta == 0) {
		cout << n;
		return;
	}
	if (delta > 0) {
		ll mod = m / delta;
		for (int k = 1; k <= n / 2; k++) {
			if (mod < k + (k * k)) {
				cout << (2 * (k - 1));
				return;
			}
		}
		cout << n;
		return;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m >= 1e12) {
		calc();
		return 0;
	}
	sort(a + 1, a + n + 1);
	a[0] = -INF;
	a[n + 1] = INF;
	if (m == 0) {
		ll spans = 0, pre, cnt = 0;
		pre = a[1];
		for (int i = 2; i <= n; i++) {
			if (a[i] == pre) {
				pre = a[i];
				cnt++;
			} else {
				pre = a[i];
				spans = max(spans, cnt);
				cnt = 0;
			}
		}
		cout << spans + 1;
		return 0;
	}

	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	}

	for (int i = 1; i <= n; i++) {

		ll mid, r, l;
		if (i == 1) {
			mid = 1, r = 2, l = 1;
		} else if (i == n) {
			mid = n, r = n, l = n - 1;
		} else {
			mid = i, r = i + 1, l = i - 1;
		}
		ll val = m, wr = a[r] - a[mid], wl = a[mid] - a[l];
		if (mid == r)
			wr = INF;
		if (mid == l)
			wl = INF;
		//cout << "gain new mid:" << mid << endl;
		ll cnt = 0;
		while (val >= wr || val >= wl) {
			if (cnt >= 10) {
				//cout << "wr" << endl;
				break;
			}
			cnt++;
			//cout << "now l: " << l << " r: "
			//        << r << " val: " << val << endl;
			wr = a[r] - a[mid], wl = a[mid] - a[l];
			//cout << "wl: " << wl << " wr: " << wr << endl;
			if (n + 1 == r)
				wr = INF;
			if (0 == l)
				wl = INF;
			if (wr >= wl) {
				val -= wl;
				l--;
			} else {
				val -= wr;
				r++;
			}
		}
		//cout << "now r:l:" << r << ' ' << l << endl;
		//cout << "gain ans:" << r - l - 1 << endl;
		ans = max(ans, r - l - 1);
	}
	cout << ans;
}