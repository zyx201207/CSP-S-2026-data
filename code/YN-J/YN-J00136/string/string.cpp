#include <bits/stdc++.h>
using namespace std;
long long dp[5005][5005];
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	s += '0';
	cin >> n;

	for (int i = 1; i <= n; i++) {

		int x;
		char c;
		cin >> x >> c;

		for (int i = 0; i < x; i++) {

			s += c;
		}
	}

	long long l = s.size() - 1;

	for (long long i = 1; i < l; i++) {

		if (s[i] != s[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}

	for (long long len = 3; len <= l; len++) {

		for (long long i = 1; i + len - 1 <= l; i++) {

			long long j = i + len - 1;

			if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1];
			} else {
				dp[i][j] = dp[i + 1][j - 1] + 1;
			}
		}
	}

	cout << dp[1][l];
	return 0;
}