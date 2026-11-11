#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[50005];
int t[505][50005];
int h[505][50005];
int k[505][50005];
int s[50005];
int ss[505];
int jpss[505];

struct node {
	int x;
	int y;
	int e;
};

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int kk;
		cin >> kk;
		ss[i] = kk;
		for (int j = 1; j <= kk; j++) {
			int a;
			cin >> a >> t[i][j];
			h[i][j] = a;
			k[a][s[a] + 1] = i;
			s[a]++;
		}
	}
	for (int i = 1; i <= q; i++) {
		int xx, yy;
		cin >> xx >> yy;
		queue < node > p;
		p.push({xx, 0, 1});
		int g = INT_MAX;
		memset(jpss, 0, sizeof(jpss));
		while (!p.empty()) {
			auto r = p.front();
			p.pop();
			if (r.e == 1) {
				for (int j = 1; j <= s[r.x]; j++) {
					p.push({k[r.x][j], r.y + t[k[r.x][j]][r.x], 2});
				}
			} else {
				for (int j = 1; j <= ss[r.x]; j++) {
					if (h[r.x][j] == yy) {
						g = min(g, r.y + t[r.x][h[r.x][j]]);
					}
					if (jpss[h[r.x][j]] == 0) {
						p.push({h[r.x][j], r.y + t[r.x][h[r.x][j]], 1});
						jpss[h[r.x][j]] = 1;
					}
				}
			}
		}
		g += w[xx];
		g += w[yy];
		cout << g << endl;
	}
	return 0;
}