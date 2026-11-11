#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], A = 1, t[300005], s[300005], dp[3005][3005], ans[300005];
int dfs(int x, int y){
	if (dp[x][y] != -1) return dp[x][y]; 
	if (x == a[n]) return dp[x][y] = y == a[n];
	else return dp[x][y] = dfs(a[s[x] + 1], y) || y == x;
}signed main(){
	freopen("card.in", "r", stdin); 
	freopen("card.ans", "w", stdout);
	cin >> n >> m, memset(dp, -1, sizeof dp);
	for (int i = 1; i <= n; i++){
		cin >> a[i], t[a[i]]++, s[a[i]] = i;
		if (i != 1 && a[i] < a[i - 1]) A = 0;
	}if (A){
		for (int i = 1; i <= m; i++) cout << s[i] << ' ';
		return 0;
	}
	for (int i = m; i; i--) for (int j = 1; j <= m; j++)
		ans[j] += dfs(i, j) * t[i]; 
	for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
	return 0;
}
