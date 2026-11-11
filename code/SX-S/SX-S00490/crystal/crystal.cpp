#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long weight[N];
long long dp[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m;
	cin >> n >> m;
	long long mind = 1e12;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		weight[i] = m - a;
		mind = min(mind, weight[i]);
	}
	dp[mind] = 1;
	for (int i = 0; i < n; i++) {
		for (long long j = m; j >= weight[i]; j--) {
			if (dp[j] < dp[j - weight[i]] + 1) {
				dp[j] = dp[j - weight[i]] + 1;
			}
		}
	}
	cout << dp[m] + 1;
	return 0;
}