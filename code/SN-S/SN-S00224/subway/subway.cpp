#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int l, m;
}a[500005][25];
int w[500005], cnt[500005];
int f[505][505];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		if (i != j) f[i][j] = 1e18 + 7;
	}
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k, x, y; cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> x >> y;
			for (int s = 1; s <= cnt[x]; s++) {
				f[i][a[x][s].l] = min(f[i][a[x][s].l], a[x][s].m + y);
				f[a[x][s].l][i] = min(f[a[x][s].l][i], a[x][s].m + y);
			}
			a[x][++cnt[x]] = {i, y};
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y, ans = 1e18 + 7;
		cin >> x >> y;
		for (int i = 1; i <= cnt[x]; i++) {
			for (int j = 1; j <= cnt[y]; j++) {
				ans = min(ans, f[a[x][i].l][a[y][j].l] + w[x] + w[y] + a[x][i].m + a[y][j].m);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
