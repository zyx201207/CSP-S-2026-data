#include <bits/stdc++.h>
using namespace std;
long long bh, n, m, d, q, x, y, maxx = LLONG_MIN, sum;
const int N = 5e5+10;
int w[N], k[510], a[510][510], t[510][510];

void dfs(int kk, int s, int e, int u) {
	if (kk == y) {
		s = s + t[e][u] + w[kk];
		maxx = max(maxx, 1ll * s);
		return;
	}
	dfs(a[e][u + 1], s, e, u + 1);
	if (u == 2) {
		for (int i = 1; i <= n; i++) {
			if (a[i][1] == kk) {
				dfs(kk, s + t[e][u] + t[i][1], i, 1);
			}
		}
	}

}

void dfs2(int kk, int s, int e, int u) {
	if (kk == y) {
		s = s + t[e][u] + w[kk];
		maxx = max(maxx, 1ll * s);
		return;
	}
	dfs(a[e][u + 1], s, e, u + 1);
	for (int i = 1; i <= n; i++) {
		if (a[2][i] == kk) {
			dfs(kk, s + t[e][u] + t[i][1], i, 1);
		}
	}
}

void dfs3(int kk, int s, int e, int u) {
	if (kk == y) {
		s = s + t[e][u] + w[kk];
		maxx = max(maxx, 1ll * s);
		return;
	}
	dfs(a[e][u + 1], s, e, u + 1);
	for (int i = 1; i <= n; i++) {
		if (a[1][i] == kk) {
			dfs(kk, s + t[e][u] + t[i][1], i, 1);
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> bh >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	while (q--) {
		maxx = LLONG_MIN;
		cin >> x >> y;
		if (n == 2) {
			for (int i = 1; i <= k[1]; i++) {
				if (a[1][i] == x) {
					dfs2(x, w[x] + t[1][i], 1, i);
				}
			}
			for (int i = 1; i <= k[2]; i++) {
				{
					if (a[2][i] == x) {
						dfs3(x, w[x] + t[2][i], 2, i);
					}
				}

			}
			cout << maxx << endl;
			continue;
		}
		for (int i = 1; i <= n; i++) {
			if (a[i][1] == x) {
				dfs(x, w[x] + t[i][1], i, 1);
			}
		}
		cout << maxx << endl;
	}
	return 0;
}