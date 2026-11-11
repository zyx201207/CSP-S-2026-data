#include <bits/stdc++.h>

using namespace std;

int vis[200005];
//int f[200005];
int ans = 0;
int n, m;

void dfs(int x, vector<int> v, int cur) {
	if (x == m) {
		ans = max(ans, cur);
		return;
	}
	
//	if (cur >= f[x]) return;
//	cout << f[x] << ' ' << cur << endl;
	
//	f[x] = cur;
	
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		vis[i] = 1;
		dfs(x + 1, v, cur & v[i]);
		vis[i] = 0;
	}
	
	return;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	vector<int> v(n), dp(m + 1, 0);
	
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	
//	memset(f, 0x3f, sizeof(f));
//	f[0] = 0x40000000;
	dfs(0, v, 0x3fffffff);
	
//	dp[0] = ~(1 << 31);
//
//	cout << dp[1] << "-----\n";
//  
//	for (int i = 1; i <= m; ++i) {
//		for (int j = 0; j < n; ++j) {
//			dp[i] = max(dp[i], dp[i - 1] & v[j]);
//			cout << "     " << (dp[i - 1] & v[j]) << endl;
//		}
//		cout << i << ' ' << dp[i] << endl;
//	}
	
	cout << ans << endl;
	
	return 0;
}