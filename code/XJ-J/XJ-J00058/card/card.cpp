#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;
int n, m;
int nums[N];
vector<int> dp[N];
int result[M];
int last[M]; 

void solve() {
	for (int i = n - 1; i >= 0; --i) {
		int idx = last[nums[i]];
		if (idx != 0x3f3f3f3f) {
			dp[i] = dp[n - idx - 1];
		} else {
			dp[i].push_back(nums[i]);
			for (int k = 0; k < dp[i + 1].size(); ++k) {
				dp[i].push_back(dp[i + 1][k]);
			}
		}
		last[nums[i]] = min(n - i - 1, last[nums[i]]);
		
		for (int j = 0; j < dp[i].size(); j++) {
			result[dp[i][j]]++;
		}
	}
//	
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < dp[i].size(); ++j) {
//			cout << dp[i][j] << ' ';
//		}
//		cout << endl;
//	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	
	memset(last, 0x3f, sizeof last);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	
	solve();
	for (int i = 1; i <= m; ++i) {
		cout << result[i] << ' ';
	}
	cout << '\n';
	return 0;
}
