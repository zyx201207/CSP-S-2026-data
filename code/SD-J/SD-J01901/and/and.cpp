#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

//const int MAXN = ;

void solve() {
	int n, m; cin >> n >> m;
	
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		dp[i][1] = a[i];
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= min(i, m); j++) {
			int t_ans = INT_MIN;
			for (int k = 1; k < i; k++) {
				t_ans = max(t_ans, (dp[k][j - 1] & a[i]));
			}
			dp[i][j] = t_ans;
		}
	}
	
	int _max = INT_MIN;
	for (int i = m; i <= n; i++) {
		_max = max(_max, dp[i][m]);
	}
	
	cout << _max << endl;
	return ;
}

int main () {
	ios::sync_with_stdio();
	cin.tie(nullptr);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int T = 1; //cin >> T;
	while (T--) {
		solve();
	}
	
	return 0;
}

