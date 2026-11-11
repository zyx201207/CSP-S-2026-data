#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e5 + 10;
long long dp[MAXN];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	long long v[MAXN];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		dp[0] = v[i];
		for (int j = m; j >= 1; j--) {
			dp[j] = max(dp[j], dp[j - 1] & v[i]);
		}
	}
	cout << dp[m];
}