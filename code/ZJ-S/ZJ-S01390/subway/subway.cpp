#include <bits/stdc++.h>

using namespace std;

int c, n, m, d, q;
int w[500005];
int a[505][500005];
int t[505][500005];
bool vis[500005];
vector<pair<int, int> > zd[500005];
long long ans = 0;
long long mn = 1e9;
void dfs(int st, int ed, int xl, int bh) {
	vis[a[xl][bh]] = 1;
	if (a[xl][bh] == ed) {
		ans += w[ed];
		mn = min(mn, ans);
		return;
	}
	for (auto &c : zd[a[xl][bh]]) {
		int xln = c.first;
		int bhn = c.second;
		if (xln != xl && bhn != bh) {
			ans += t[xl][bh] + t[xln][bhn];
			dfs(st, ed, xln, bhn);
		}
	}
	for (int i = 1; i <= m; i++) {
		if (!vis[a[xl][i]] && zd[a[xl][i]].size() != 1) {
			vis[a[xl][i]] = 1;
			dfs(st, ed, xl, i);
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int g, h;
			cin >> g >> h;
			a[i][j] = g, t[i][j] = h;
			zd[g].push_back({i, j});
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		ans = 0, mn = 1e9;
		for (int j = 1; j <= n; i++) {
			for (int k = 1; k <= m; k++) {
				if (a[j][k] == x) {
					ans += w[x];
					dfs(x, y, j, k);
				}
			}
		}
		cout << mn << "\n";
	}
	return 0;
}
