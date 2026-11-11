#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, M = 150005;
int c, n, m, d, q, be, en, w[M], k[M], a[N][M], t[M][N], v[M], ans;
struct Node {
	int x, l;
};
vector<Node> e[M];
void dfs(int x, int l, int tot) {
	if (x == en) {
		ans = min(ans, tot + t[x][l]);
		return;
	}
	for (Node i : e[x]) {
		if (v[i.x]) continue;
		v[i.x] = 1;
		if (i.l == l) dfs(i.x, l, tot);
		else dfs(i.x, i.l, tot + t[x][l] + t[x][i.l]);
		v[i.x] = 0;
	}
	return;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		cin >> a[i][1] >> t[a[i][1]][i];
		for (int j = 2; j <= k[i]; j++) {
			cin >> a[i][j] >> t[a[i][j]][i];
			e[a[i][j - 1]].push_back({a[i][j], i});
			e[a[i][j]].push_back({a[i][j - 1], i});
		}
	}
	while (q--) {
		cin >> be >> en;
		ans = 1e18;
		memset(v, 0, sizeof v);
		dfs(be, 0, 0);
		cout << ans + w[be] + w[en] << '\n';
	}
	return 0;
}