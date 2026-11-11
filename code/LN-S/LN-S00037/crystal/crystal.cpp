#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 1;
vector<int> a;
vector<vector<long long> > dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	a.resize(n);
	dp.resize(n, vector<long long>(n, -1LL));
	for(int i=0; i<n; i++){
		cin >> a[i];
		dp[i][i]=0;
	}
	sort(a.begin(), a.end());
	{
		for(int i=1; i<n; i++){
			dp[0][i] = i * (a[i] - a[i-1]) + dp[0][i-1];
			if(dp[0][i]<=m) {
				ans = max(ans, i+1);
			}
		}
	}
	for(int i=1; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			dp[i][j] = dp[i-1][j] - (a[i] - a[j-1]);
			if(dp[i][j]<=m){
				ans = max(ans, j-i+1);
			}
		}
	}
	cout << ans;
	return 0;
}
