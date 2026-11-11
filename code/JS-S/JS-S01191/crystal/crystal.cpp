// JS-S01191
// crystal.cpp

#include<bits/stdc++.h>
using namespace std;
int n, ans = 0;
int m;
int cutline = 0;
int a[500005];
int dp[500005][2];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i){
		dp[i][0] = dp[i - 1][0] + 1;
		dp[i][1] = (a[i] - a[i - 1]) * dp[i - 1][0] + dp[i - 1][1];
		while (dp[i][1] > m){
			++cutline;
			dp[i][0]--;
			dp[i][1] -= a[i] - a[cutline];
		}
		ans = max(ans, dp[i][0]);
	}
	printf("%d", ans);
	return 0;
}
