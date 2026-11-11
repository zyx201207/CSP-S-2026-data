#include <bits/stdc++.h>
using namespace std;

int n;
long long m, ans = -1;
long long a[500010], d[500010], c[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + a[i];
		c[i] = a[i] * i - d[i];
		//cout << d[i] << " " << c[i] << endl;
	}
	if (n <= 6000) {
		int f1 = 0;
		for (int i = n; i >= 1; i--) {
			for (int l = 1; l <= n - i + 1; l++) {
				int r = l + i - 1;
				long long dj = a[r] * i - (d[r] - d[l - 1]);
				if (dj <= m) {
					f1 = 1;
					cout << i;
					break;
				}
			}
			if (f1 == 1)
				break;
		}
		if (f1 == 0) {
			cout << 0;
		}
	} else {
		int f = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] > m) {
				f = 1;
				cout << i - 1;
				break;
			}
		}
		if (f == 0) {
			cout << n;
		}
	}
	return 0;
}
/*
5 3
1 100 101 102 103
*/
