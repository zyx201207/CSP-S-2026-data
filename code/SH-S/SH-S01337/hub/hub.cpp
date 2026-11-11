#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c , t , n , k , u[N] , v[N] , f[N][10] , a[N] , dep[N] , d[N];
vector <int> g[N];
bool xuan[N];
void dfs (int x) {
	dep[x] = dep[f[x][0]] + 1;
	for (int i = 0; i < g[x].size (); i++) {
		if (g[x][i] == f[x][0]) continue;
		f[g[x][i]][0] = x;
		dfs (g[x][i]);
	}
}
int lca (int x , int y) {
	if (dep[x] < dep[y]) swap (x , y);
	for (int i = 4; i >= 0; i--) {
		if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	}
	if (x == y) return x;
	for (int i = 4; i >= 0; i--) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
		return f[x][0];
	}
}
int main () {
	freopen ("hub.in" , "r" , stdin);
	freopen ("hub.out" , "w" , stdout);
	ios::sync_with_stdio (false) , cin.tie (0) , cout.tie (0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) g[i].clear ();
		for (int i = 1; i < n; i++) {
			cin >> u[i] >> v[i];
			g[u[i]].push_back (v[i]);
			g[v[i]].push_back (u[i]);
		}		
		dfs (1);
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= n; j++) {
				f[j][i] = f[f[j][i - 1]][i - 1];
			}
		}
		int ans = 10;
		for (int i = 0; i < (1 << n); i++) {
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (i & (1 << (j - 1))) {
					xuan[j] = 1;
					a[++cnt] = j;
				} else {
					xuan[j] = 0;
				}
			}
				if (cnt != k) continue;
				for (int j = 1; j < n; j++) {
					if (xuan[u[j]] && xuan[v[j]]) cnt--;
				}
				if (cnt <= 2) {
					int mx = 0;
					for (int j = 1; j <= n; j++) {
						if (xuan[j]) {
							d[j] = 0;
							continue;
						}
						d[j] = 10;
						for (int l = 1; l <= k; l++) {
							d[j] = min (d[j] , dep[j] + dep[a[l]] - 2 * dep[lca (j , a[l])]);
						}
						mx = max (mx , d[j]);
					}
					ans = min (ans , mx);
				}				
 		}
 		cout << ans << "\n";
	}
	return 0;
}
