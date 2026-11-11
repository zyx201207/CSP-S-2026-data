#include <bits/stdc++.h>
using namespace std;
long long a[200005], dp[10000][10000];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	long long Max1 = -1, Max2 = -1;
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (long long i = 1; i <= n; i++)

		dp[i][i] = a[i];

	for (long long i = 1; i <= n; i++) {

		for (long long len = 1; i + len <= n; len++) {

			long long j = len + i;

			for (int k = i + 1; k < j; k++) {

				Max1 = max(dp[i][k] & dp[k + 1][j], Max1);
			}

			dp[i][j] = Max1;
			Max2 = max(dp[i][j], Max2);
		}
	}
	cout << Max2 << endl;
	return 0;
}