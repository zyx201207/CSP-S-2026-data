#include <bits/stdc++.h>
using namespace std;
#define int long long
bool vis[505];
int c, t, n, k, res;
int ans[505], f[505][505];
void floyd() {
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				if(f[i][j] > f[i][k] + f[k][j])
					f[i][j] = f[i][k] + f[k][j];
	return ;
}
void check() {
	int sum = 0, cnt = 0;
	for(int i = 1; i <= k; i ++) {
		for(int j = 1; j <= n; j ++)
			if(vis[j] == 1 && f[i][j] == 1)
				cnt ++;
	}
	if(cnt < 2 * k - 4)	return ;
	for(int i = 1; i <= n; i ++) {
		if(vis[i])	continue;
		int dis = 1e18;
		for(int j = 1; j <= k; j ++)
			dis = min(dis, f[i][ans[j]]);
		sum = max(sum, dis);
	}
	res = min(res, sum);
	return ;
}
void dfs(int cur) {
	if(cur == k + 1) {
		check();
		return ;
	}
	for(int i = ans[cur - 1] + 1; i <= n; i ++) {
		ans[cur] = i, vis[i] = true;
		dfs(cur + 1);
		vis[i] = false;
	}
	return ;
}
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t --) {
		cin >> n >> k;
		res = 1e9;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				f[i][j] = 1e18;
		for(int i = 1; i < n; i ++) {
			int x, y;
			cin >> x >> y;
			f[x][y] = f[y][x] = 1;
		}
		floyd();
		dfs(1);
		cout << res << "\n";
	}
	return 0;
}
