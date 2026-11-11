#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, dp[12000] = {0}, d[100000] = {0}, m = 0;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> d[i];
		for (int j = b; j >= 1; j--) {
			if (j == 1) {
				dp[j] = max(dp[j], d[i]);
			} else {
				dp[j] = max(dp[j], dp[j - 1] & d[i]);
			}
			if (j == b) {
				m = max(dp[j], m);
			}

		}
	}

	cout << m;
	return 0;
}

