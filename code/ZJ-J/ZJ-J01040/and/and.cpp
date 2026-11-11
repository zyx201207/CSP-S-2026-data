#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	vector<int> a;
	a.push_back(0);
	
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	
	vector<int> dp(k + 1, 0);
	
	for (int i = 1; i <= n; ++i) {
		dp[k] = a[i];
		for (int j = k; j >= 1; --j) {
			dp[j] = max(dp[j], dp[j + 1] & a[i]);
		}
	}
	cout << dp[k];
	
	return 0;
}