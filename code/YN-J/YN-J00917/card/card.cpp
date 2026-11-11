// Yang Mofei
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int> vec;
vector<vector<int>> dp;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	vec.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
	}

	dp.resize(n + 1, vector<int>(m + 1, 0));
	dp[n][vec[n]] = 1;

	vector<int> last(m + 1, -1);
	last[vec[n]] = n;

	for (int i = n - 1; i >= 0; i--) {
		if (last[vec[i]] != -1) {
			dp[i] = dp[last[vec[i]]];
		} else {
			dp[i] = dp[i + 1];
			dp[i][vec[i]]++;
		}
		last[vec[i]] = i;
	}
	for (int i = 1; i <= m; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += dp[j][i];
		}
		cout << sum << " ";
	}
	cout << endl;
//	cout << endl;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	return 0;
}