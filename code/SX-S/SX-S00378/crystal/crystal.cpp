#include <bits/stdc++.h>
using namespace std;
long long  n, m, a[500005], ans, sum, f;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int i;
	if (n % 2 == 0) {
		ans = a[n / 2];
		i = n / 2 - 1;
	} else {
		ans = a[n / 2 + 1];
		i = n / 2;
	}

	while (m > 0 && i >= 1) {
		m = m - (ans - a[i]);
		if (m < 0)
			f = 0 - m;
		a[i] += abs(ans - a[i]) - f;
		i--;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[n / 2 + 1]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}