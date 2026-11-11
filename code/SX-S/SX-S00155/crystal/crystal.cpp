#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll n, m, a[N], mmax = INT_MIN, s = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
//	ll q = -1, w = -1;
//	bool qw = 0;
//	for (int i = n; i > 1; i--) {
//		if (a[i] == a[i - 1]) {
//			q = a[i - 1];
//			w = i - 2;
//			qw = 1;
//		}
//	}
//	cerr << q << ' ' << w << ' ' << qw << '\n';
//	if (!qw) {
	for (int i = 2; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			bool f = 0;
			ll x = a[i] - a[i - 1];
			for (int j = i - 1; j >= 1; j--) {
				if (m < x) {
					f = 1;
					break;
				}
				a[j] += x;
				m -= x;
			}
			if (f)
				break;
		}
	}
//	} else {
//		for (int i = w; i >= 1; i--) {
//			if (a[i] != q) {
//				bool f = 0;
//				ll x = q - a[i];
//				for (int j = i; j >= 1; j--) {
//					if (m < x) {
//						f = 1;
//						break;
//					}
//					a[j] += x;
//					m -= x;
//				}
//				if (f)
//					break;
//			}
//		}
//	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			mmax = max(mmax, s);
			s = 1;
		} else {
			s++;
		}
	}
	cout << mmax;
	return 0;
}
/*
6 3
1 3 6 6 7 8
*/