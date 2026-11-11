#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 2e5 + 5;
int nums[N], dp[N];

int solve() {
	for (int i = 0; i < n; ++i) {
		for (int j = m; j >= 1; --j) {
			dp[j] = max(dp[j], dp[j - 1] & nums[i]);
		}
	}
	return dp[m];
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	
	cin >> n >> m;
	dp[0] = INT_MAX;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		nums[i] = x;
	}
	cout << solve() << endl;
	
	return 0;
}
