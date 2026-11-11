#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	char c;
	string s = "$";
	int n, m, k;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> m >> c;

		for (int i = 1; i <= m; i++) {

			s += c;
		}
	}

	long long l = s.length() - 1;
	long long dp[l + 1][l + 1];

	for (long long i = 0; i <= l; i++) {

		for (long long j = 0; j <= l; j++) {

			dp[i][j] = 0;
		}

	}

	for (long long i = 1; i <= l; i++) {

		for (long long j = i + 1; j <= l; j++) {

			if (j - i == 1) {
				if (s[i] == s[j])
					dp[i][j] = 0;
				else
					dp[i][j] = 1;
			} else {
				if (s[i] == s[j])
					dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
				else
					dp[i][j] = min(dp[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2) ;
			}
		}
	}

	cout << dp[1][l];
	return 0;
}
