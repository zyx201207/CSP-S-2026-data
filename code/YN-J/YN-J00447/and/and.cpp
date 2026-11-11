#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 2e5 + 10;
int a[N];
int dp[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n ; i++) {
		for (int j = m; j >= 1; j--) {
			dp[j] = max(( dp[i - 1] & a[j]), a[i] );
		}
	}
	cout << dp[m];

	return 0;
}
