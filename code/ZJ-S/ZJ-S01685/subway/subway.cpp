#include <bits/stdc++.h>
using namespace std;

const int N = 500+5, M = 5e5+5, D = 20+5;

int c, n, m, d, q;
int w[M];
int k[N];
int l[M][D];
int l_size[M];
int a[N][D];
int t[M][D];
int min_time;
int x, y;
bool vis[M];

void dfs(int idx, int time) {
//	cout << idx << " " << time << " " << endl;
	
	if (idx == y) {
		min_time = min(min_time, time+w[idx]);
	}
	for (int i = 1; i <= l_size[idx]; i++) {
		int line = l[idx][i];
		for (int j = 1; j <= k[line]; j++) {
			int u = a[line][j];
			if (u == idx) continue;
			if (vis[u]) continue;
			vis[u] = 1;
			dfs(u, t[idx][line]+t[u][line]+time);
			vis[u] = 0;
		}	
	}
	
}

signed main () {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int tt;	
			cin >> a[i][j] >> tt;
			int u = a[i][j];
			l[u][++l_size[u]] = i;
			t[u][i] = tt;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
		min_time = 1e9;
		memset(vis, 0, sizeof(vis));
		vis[x] = 1;
		dfs(x, w[x]);
		cout << min_time << endl;
	}
	
	return 0;
}
