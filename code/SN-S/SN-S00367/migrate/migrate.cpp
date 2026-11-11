// SN-S00367 李天江 西安交通大学附属中学
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
int n;
int64_t d;

void solve() {
	cin >> n >> d;
	vector<int64_t> a(n + 2);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << "0\n";
		return;
	}

	vector<int> c(n + 2);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int last = i, left = i;
		int64_t dis = 0, rest = d;
		c[i] = 1;
		for (int j = i + 1; j <= n; ++j) {
			const int64_t tmp = a[j] - a[j - 1];
			dis += tmp;
			while (dis > d) {
				dis -= a[left + 1] - a[left];
				left++;
			}
			
			if (rest < tmp) {
				last = j - 1;
				rest = d - tmp;
			} else {
				rest -= tmp;
			}

//			if (i == 2) {
//				clog << rest << ' ' << tmp << '\n';
//			}

			const int candidates = last - left + 1;
			if (candidates > 2) {
				c[j] = 3;
			} else if (candidates == 1) {
				c[j] = c[left];

				if (c[j] == 2) {
					ans++;
				}
			} else {
				c[j] = min(3, c[left] + c[left + 1]);
				
				if (c[j] == 2) {
					ans++;
				}
			}
			
//			clog << i << ' ' << j << ' ' << last << ' ' << left << ' ' << c[j] << '\n';
		}
	}
	cout << ans << '\n';
}

void solve_A() {
	cin >> n >> d;
	vector<int64_t> a(n + 2);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << "0\n";
		return;
	}

	const int64_t x = a[2] - a[1], s = d / x;
//	clog << x << ' ' << s << ' ' << d << '\n';
	if (s <= 1) {
		cout << "0\n";
		return;
	}

	const int64_t ans = max<int64_t>(0, n - 2 * s + 1);
	cout << ans << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_c, t;
	cin >> test_c >> t;
	for (int _ = 0; _ < t; ++_) {
		if (test_c == 11 || test_c == 12) {
			solve_A();
		} else {
			solve();
		}
	}
	return 0;
}
