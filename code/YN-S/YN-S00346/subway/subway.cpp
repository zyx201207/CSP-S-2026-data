#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXM = 5e5 + 5, MAXN = 5e2 + 5;
int c, n, m, d, q;
int w[MAXM], t[MAXN][3];

struct node {
	int v, val;
};
vector<node>e[MAXM];
int ans = INT_MAX;

void dfs(int u, int fa, int sum, int y) {
	if (sum > ans)
		return;
	if (u == y) {
		ans = min(ans, sum);
		return;
	}
	for (auto it : e[u]) {
		int v = it.v, val = it.val;
		if (v == fa)
			continue;
		dfs(v, u, sum + val, y);
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	if (c >= 7 && c <= 11) {
		for (int i = 1; i <= m; i++) {
			cin >> w[i];
		}
		for (int i = 1; i <= n; i++) {
			int tmp, x, y;
			cin >> tmp;
			cin >> x >> t[i][1] >> y >> t[i][2];
			e[x].push_back({y, t[i][1] + t[i][2]});
			e[y].push_back({x, t[i][1] + t[i][2]});
		}
		for (int i = 1; i <= q; i++) {
			int x, y;
			cin >> x >> y;
			ans = INT_MAX;
			dfs(x, x, w[x] + w[y], y);
			cout << ans << "\n";
		}
	}
	return 0;
}