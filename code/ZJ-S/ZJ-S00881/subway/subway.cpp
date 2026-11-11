#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll c, n, m, d, q, w[501000], len[501000], f[510][510], ans;
vector<pair<int, int> > lin[501000];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1, k; i <= n; i ++) {
		cin >> k;
		for (int j = 1, a, t; j <= k; j ++) {
			cin >> a >> t;
			lin[a].push_back(make_pair(i, t));
		}
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i ++) f[i][i] = 0;
	for (int i = 1; i <= m; i ++) {
		len[i] = lin[i].size();
		for (int j = 0; j < len[i]; j ++)
			for (int k = j + 1; k < len[i]; k ++)
				f[lin[i][j].fi][lin[i][k].fi] = min(f[lin[i][j].fi][lin[i][k].fi], 1ll * lin[i][j].se + lin[i][k].se);
	}
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++) {
			ll v = min(f[i][j], f[j][i]);
			f[i][j] = f[j][i] = v;
		}
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				if (f[i][k] + f[k][j] < f[i][j])
					f[i][j] = f[i][k] + f[k][j];
	for (int i = 1, x, y; i <= q; i ++) {
		cin >> x >> y;
		ans = 1e18;
		for (int j = 0; j < len[x]; j ++)
			for (int k = 0; k < len[y]; k ++)
				ans = min(ans, lin[x][j].se + lin[y][k].se + f[lin[x][j].fi][lin[y][k].fi]);
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
