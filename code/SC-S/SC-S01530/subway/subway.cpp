#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	int n; 
	int m;
	cin >> n >> m;
	int a[500010];
	int dp[100][100];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a , a + n);
	int ans = -1;
	for (int i = 2; i <= n; i++) {
		long long sum[i];
		for (int j = 1; j < i; j++) {
			sum[j] = a[i] - a[j];
		}
		for (int j = 1; j <= i - 1; j++) {
			for (long long w = 0; w <= m; w++) {
				if(sum[j] <= w){
					dp[j][w] = max(dp[j - 1][w] , dp[j - 1][w - sum[j]] + 1);
				} else {
					dp[j][w] = dp[j - 1][w];
				}
			}
		}
		ans = max(dp[i - 1][m] , ans);
	}
	cout << ans + 1;
	return 0;
}