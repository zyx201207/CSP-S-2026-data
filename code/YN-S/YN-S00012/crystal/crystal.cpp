#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m, h = 1, dta;
	bool p = 1;
	vector<ll>a(500005);
	cin >> n >> m;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 2 && a[i] - a[i - 1] != a[i - 2])
			p = 0;
	}
	sort(a.begin(), a.begin() + n);
	if (m == 0)
		cout << 1;
	if (!p) {
		for (int i = 2; i < n; i++) {
			dta = a[i] - a[i - 1];
			if (dta != a[i - 1] - a[i - 2]) {
				p = 0;
				break;
			}
		}
	}
	if (p) {
		for (int i = 1; i <= n; i++) {
			if (m >= i * dta)
				m -= i * dta, h++;
			else
				break;
		}
		cout << h;
	} else {
		for (int i = n - 1; i >= 0; i--) {
			ll bz = a[i], hh = 1, mm = m;
			for (int j = i - 1; j >= 0; j--) {
				if (mm >= bz - a[j]) {
					mm = mm - (bz - a[j]), hh++;
					if (j == 1 && mm < bz - a[j]) {
						cout << hh;
						return 0;
					} else if (j == 0) {
						cout << hh;
						return 0;
					}
				} else
					break;
			}
			h = max(h, hh);
		}
		cout << h;
	}
	return 0;
}