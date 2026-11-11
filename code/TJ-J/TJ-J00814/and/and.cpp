#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 2;
int n, m, a[maxn], ans = -1;
vector<vector<int> > dp;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	scanf("%d %d", &n, &m);
	dp.resize(n + 2, vector<int>(m + 2, -1));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		dp[i][1] = a[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			for (int k = 2; k <= m; ++k) {
				if (dp[j][k - 1] == -1) continue;
				dp[i][k] = max(dp[i][k], dp[j][k - 1] & a[i]);
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) ans = max(ans, dp[i][m]);
	
	printf("%d", ans);
	
	return 0;
} 
