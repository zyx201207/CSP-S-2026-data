#include <bits/stdc++.h>

using namespace std;


const int N = 1e4;


int n, m;
int a[N];
int dp[N][N];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dp[1][1] = a[1];
	for (int i = 1; i <= n; i++)
		dp[i][0] = -1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] & a[i]);
		}
	}
	cout << dp[n][m];
	return 0;
} 
