#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, dp[2000005], c, T, m, a[2000005], ans, minn, sum;
void dfs (int now, int deep, int md){
	if (now >= md){
		if (deep == minn)  sum++;
		else if (deep < minn){
			minn = deep;
			sum = 1;
		}
		return ;
	}
	for (int i = now + 1; i <= md && a[i] - a[now] <= m; i++)
		dfs (i, deep + 1, md);
}
signed main(){
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++)  cin >> a[i];
		sort (a + 1, a + n + 1);
		ans = 0;
		for (int i = 1; i <= n; i++){
			minn = 1e18, sum = 0;
			dfs (1, 0, i);
			if (sum == 2)  ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
