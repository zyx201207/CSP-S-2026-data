#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
long long a[N];
long long dp[2000][2000];
bool b[2000][2000];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			} else if (dp[i - 1][j - 1] == 0) {
				dp[i][j] = max(dp[i - 1][j], a[i]);
				b[i][j] = 1;
			} else if (b[i - 1][j] == 1) {
				dp[i][j] = (dp[i - 1][j - 1] & a[i]);
			} else {
				dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - 1] & a[i]));
			}
		}
	}
	cout << dp[n][m];
	return 0;
}