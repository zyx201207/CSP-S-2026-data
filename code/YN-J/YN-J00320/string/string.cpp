#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	long long n, dp[510][510], ans = 0;
	string a1, a2;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long a;
		char b;
		cin >> a >> b;
		for (int j = 1; j <= a; j++) {
			a1 += b;
			a2 = b + a2;
		}
		ans += a;
	}
	for (int i = 0; i < ans; i++) {
		if (a1[i] != a2[i]) {
			if (i == 0) {
				dp[i][i] = 1;
			} else {
				dp[i][i] = dp[i - 1][i - 1] + 1;
			}
		} else {
			if (i == 0) {
				dp[i][i] = 0;
			} else {
				dp[i][i] = dp[i - 1][i - 1];
			}
		}
	}
	cout << dp[ans - 1][ans - 1] / 2;
	return 0;
}