#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n, m, a[N], d[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = d[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	int j;
	for (int i = 2; i <= n; i++) {
		if (m <= 0)
			break;
		j = m;
		m -= a[i] * i - d[i];
		d[i + 1] = a[i] * i + a[i + 1];
		if (m == 0) {
			int ans = 0;
			for (int k = i; k <= n; k++) {
				if (a[k] == a[k + 1]) {
					ans++;
				} else {
					break;
				}
			}
			cout << i + ans;
		} else if (m < 0) {
			if (j / (a[i] - a[i - 1]) >= 0) {
				int ans = 0;
				for (int k = i; k <= n; k++) {
					if (a[k] == a[k + 1]) {
						ans++;
					} else {
						break;
					}
				}
				cout << (i - 1 + ans);
			}
		}
	}
	return 0;
}