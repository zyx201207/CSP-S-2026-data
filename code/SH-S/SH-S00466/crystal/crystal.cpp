#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 1;
int n, m, span, a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	if (n < 6000) {
		for (int i = 1; i <= n; i++) {
			int diff = 0;
			for (int j = i - 1; j > 0; j--) {
				diff += a[i] - a[j];
				if (diff <= m && i - j + 1 > span)
					span = i - j + 1;
			}
		}
		cout << span;
	} else {
		bool f1 = true;
		for (int i = 2; i <= n; i++)
			if (a[i] != a[i - 1] + 1)
				f1 = false;
		if (f1) {
//			cout << "special A\n";
			int t = sqrt(2 * m) + 5;
			for (int i = t; i > 1; i--) {
				if (i * (i - 1) <= 2 * m) {
					cout << (i > n ? n : i);
					return 0;
				}
			}
			return 0;
		}
	}
	return 0;
}

// 1-9, 13-15
// 12/20 -> 60/100
