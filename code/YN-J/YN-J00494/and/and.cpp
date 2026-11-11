#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[200005];
long long dp[7005][7005];

bool aaa(long long A, long long B) {
	return A > B;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + 1 + n, aaa);

	if (m == 1) {
		cout << a[1];
		return 0;
	}

	if (m == n) {
		long long z = a[1];

		for (long long i = 2; i <= n; i++) {

			z = z & a[i];
		}

		cout << z;
		return 0;
	}

	for (long long i = 1; i <= n; i++) {

		dp[i][1] = a[i];

		for (long long j = 2; j <= i && j <= m; j++) {

			dp[i][j] = dp[i - 1][j - 1] & a[i];
		}
	}

	long long z = 0;

	for (long long i = m; i <= n; i++) {

		z = max(z, dp[i][m]);
	}

	cout << z;
	return 0;
}
