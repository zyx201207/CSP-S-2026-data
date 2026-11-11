#include <bits/stdc++.h>
using namespace std;
long long a[1000000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n, m;
	cin >> n >> m;
	long long b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b += abs(a[i]);
	}
	int cnt = 0;
	long long ans = m;
	long long ji = 0;
	int p = 0, q = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == i) {
			p++;
		}
	}
	if (n % 2 == 0) {
		sort(a + 1, a + 1 + n, greater<int>());
		for (int i = 1; i <= n; i++) {
			ji += abs(a[i]);
			if (ji > m) {
				cout << i;
				return 0;
			}
		}
	}

	else {
		if (m > a[n] && p == n) {
			for (int i = 1; i <= n; i++) {
				q += abs(a[i]);
				if (q > m) {
					cout << i - 1;
					return 0;
				} else if (i == n && q <= m) {
					cout << n;
				}
			}
		} else {
			sort(a + 1, a + 1 + n);
			b = a[n / 2 + 1];
			for (int i = 1; i <= n; i++) {
				while (a[i] <= b && ans >= 0) {
					cnt++;
					ans -=  abs(b - a[i]);
				}
			}
			cout << cnt;
		}
	}

	return 0;
}
