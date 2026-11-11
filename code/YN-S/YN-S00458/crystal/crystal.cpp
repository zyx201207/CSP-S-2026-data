#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long a[500001] = {};
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long d = abs(a[2] - a[1]);
	if (m / d == 0) {
		cout << 1;
		return 0;
	} else {
		long long  x = m / d;
		long long sum = 1;
		long long c = 1;
		while (x > 0 && x >= c) {
			x -= c;
			sum++;
			c++;
		}
		cout << sum;
	}
	return 0;
}