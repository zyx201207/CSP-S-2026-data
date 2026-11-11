#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q;
int w[500005];
int g[1505][1505];
map<int, int> mp;
int tot;
void floyd () {
	for (int k = 1; k <= tot; k++) {
		for (int i = 1; i <= tot; i++) {
			for (int j = 1; j <= tot; j++) {
				g[i][j] = min (g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}
signed main() {
	memset (g, 0x3f, sizeof g);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		if (!mp[i]) mp[i] = ++tot;
		int k;cin >> k;
		int a, t;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			a *= (500005);
			if (!mp[a]) mp[a] = ++tot;
			g[mp[i]][mp[a]] = g[mp[a]][mp[i]] = t;
		} 
	}
	floyd ();
	/*
	for (int i = 1; i <= n; i++) {
		cout << mp[i] << ' ';
	}
	for (int i = 1; i <= tot; i++) {
		for (int j = 1; j <= tot; j++) {
			cout << g[i][j] << ' ';
		}
		cout << '\n';
	}*/
	while (q--) {
		int x, y;cin >> x >> y;
		cout << g[mp[x * 500005]][mp[y * 500005]] + w[x] + w[y] << '\n';
	}
	return 0;
}