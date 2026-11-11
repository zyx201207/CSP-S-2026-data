#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+100;
long long c, n, m, d, q, k, l, r, ans = LLONG_MAX, f;
int w[N], v[1010][1010], a[1010], t[1010], vis[1010];

void dfs(int x, int y, long long s) {
	if (x == y) {
		ans = min(ans, s);
		return ;
	}
	for (int i = 1; i <= m; i++) {
		if (vis[i] == 0 && v[x][i] != 0) {
			vis[i] = 1;
			dfs(i, y, s + v[x][i]);
			vis[i] = 0;
		}

	}

}

void dfs1(int x, int y, long long s) {
	if (x == y) {
		ans = min(ans, s);
		return ;
	}
	vis[x] = 1;
	for (int i = 1; i <= m; i++) {
		if (vis[i] == 0 && v[x][i] != 0) {
			dfs1(i, y, s + v[x][i]);
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
	f = 1;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
		for (int j = 1; j <= k; j++) {
			for (int ij = j + 1; ij <= k; ij++) {
				if (v[a[j]][a[ij]] != 0) {
					v[a[j]][a[ij]] = min(v[a[j]][a[ij]], t[j] + t[ij]);
				}
				v[a[j]][a[ij]] = t[j] + t[ij];

				if (v[a[ij]][a[j]] != 0) {
					v[a[ij]][a[j]] = min(v[a[ij]][a[j]], t[j] + t[ij]);
				}
				v[a[ij]][a[j]] = t[j] + t[ij];
			}
		}
	}
	if (n <= 10) {
		for (int i = 1; i <= q; i++) {
			cin >> l >> r;
			ans = LLONG_MAX;
			memset(vis, 0, sizeof(vis));
			dfs(l, r, w[l] + w[r]);
			cout << ans << "\n";
		}
	} else {
		for (int i = 1; i <= q; i++) {
			cin >> l >> r;
			ans = LLONG_MAX;
			memset(vis, 0, sizeof(vis));
			dfs1(l, r, w[l] + w[r]);
			cout << ans << "\n";
		}

	}



	return 0;
}
