#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[1000001];

int dp[1001][1001] = {0};

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1] & a[i], dp[i][j - 1] & a[j]);
		}
	}
	cout << dp[n][n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}


