#include <bits/stdc++.h>
using namespace std;
long long  n, m, sum, t;
long long a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if (n % 2 != 0) {
		t = n / 2 + 1;
	} else {
		t = n / 2;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == a[t]) {
			sum++;
		}
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[t]) {
			m -= a[t] - a[i];
			sum++;
		} else {
			sum++;
		}
		if (m == 0) {
			break;
		}
	}
	cout << sum;
	return 0;
}