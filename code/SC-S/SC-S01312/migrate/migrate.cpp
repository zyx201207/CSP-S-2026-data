#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, T, n, d;
bool vis[5005];
int a[5005];
int g[5005][5005], flag;
vector<int> _g[5005]; 
void floyd () {  
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = min (g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}
void dfs (int u, int gd, int cnt, int val) {
	//cout << u << ' ';
	if (flag > 2) return;
	if (u == gd and cnt == val) {
		flag++;
		return;
	}
	for (int i = 0; i < _g[u].size (); i++) {
		if (vis[_g[u][i]]) continue;
		vis[_g[u][i]] = 1;
		dfs (_g[u][i], gd, cnt + 1, val);
		vis[_g[u][i]] = 0;
	}
}
signed main() {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		memset (vis, 0, sizeof vis);
		memset (g, 0x3f, sizeof g);
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int l = 1, r = 2;
		while (l < r and r <= n) {
			if (a[r] - a[l] <= d) {
				g[l][r] = 1;
				_g[l].push_back (r); 
				if (r != n and a[r + 1] - a[l] <= d) r++;
				else l++;
			}
			else { 
				l++;
			}
		}  
		floyd ();
		/*
		for (int i = 1; i <= n; i++) {
			cout << i << ':';
			for (int j = 0; j < _g[i].size (); j++) {
				cout << _g[i][j] << ' ';
			} 
			cout << '\n';
		}*/
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (g[i][j] == 1 or g[i][j] == 0x3f3f3f3f3f3f3f3f) continue;
				vis[i] = 1;
				dfs (i, j, 0, g[i][j]);
				vis[i] = 0;
				if (flag == 2) ++ans;
				flag = 0;
			}
		}
		cout << ans << '\n';
		ans = 0;
		for (int i = 1; i <= n; i++) {
			_g[i].clear ();
		}
	}
	return 0;
}