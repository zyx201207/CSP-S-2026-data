#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long a[n + 3] = {0}, b[n + 3], dp[n + 3];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1] = 0;
	b[1] = 0;
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
		dp[i] = b[i] * (i - 1);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		m -= dp[i];
		if (m >= 0) {
			sum++;
		} else {
			break;
		}

	}
	cout << sum;
	return 0;
}
