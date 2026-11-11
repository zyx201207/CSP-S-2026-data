#include <bits/stdc++.h>
using namespace std;
const long long N = 500050;
long long n, m;
long long a[N], b[N];

int main(void) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long b1 = 1, b2 = 1;
	long long c = a[2] - a[1];
	for (long long i = 2; i <= n; i++) {
		if (a[i] - a[i] != 1) {
			b1 = 0;
		}
		if (a[i] - a[i - 1] != c) {
			b2 = 0;
		}
	}
//	cout << b1 << b2 << endl;
	if (b1) {
		long long cntn = 0;
		long long ans = -1;
		for (long long i = 2; i <= n; i++) {
			cntn = cntn + a[i - 1];
			if (cntn <= m) {
				ans = max(ans, i);
			} else {
				break;
			}
//			if (cntn > m) {
//				cout << i - 1;
//				break;
//			}
		}
		cout << ans;
	} else if (b2 && c != 0) {
		long long cntn = 0;
		long long ans = -1;
		for (long long i = 1; i <= n; i++) {
			cntn = cntn + (i - 1) * c;
			if (cntn <= m) {
				ans = max(ans, i);
			} else {
				break;
			}
//			if (cntn > m) {
//				cout << i - 1;
//				break;
//			}
		}
		cout << ans;
	} else {
		long long ans = -1;
		long long cntn = 0;
		for (long long i = 1; i <= n; i++) {
			cntn = 0;
			for (long long j = i - 1; j >= 1; j--) {
				if (j == i - 1) {
					cntn = a[i] - a[j];
				} else {
					cntn = cntn + a[i] - a[j];
				}
				if (cntn <= m) {
					ans = max(ans, i - j + 1);
				} else {
					break;
				}
			}
		}
		cout << ans;
	}
	return 0;
}