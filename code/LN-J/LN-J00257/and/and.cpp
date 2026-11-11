#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> a;
vector<vector<int> > dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	a.resize(n+1);
	dp.resize(n+1, vector<int>(m+1, 0));
	dp[0][0]=-1;
	for(int i=1; i<=n; i++){
		dp[i][0]=-1;
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] & a[i]);
		}
	}
	cout << dp[n][m];
	return 0;
}
