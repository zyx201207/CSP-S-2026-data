#include <bits/stdc++.h>

#define fi first
#define se second
#define int long long

using namespace std;
using pii = pair<int, int>;

const int kMaxN = 6e5 + 5;

int c, n, m, d, q, w[kMaxN], dis[505][505];
vector<pii> line[kMaxN];

signed main() {
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> c >> n >> m >> d >> q;
  for (int i = 1; i <= m; i++) cin >> w[i];
	memset(dis, 0x3f, sizeof(dis));
  for (int i = 1, k; i <= n; i++) {
		dis[i][i] = 0;
		cin >> k;
		for (int j = 1, a, t; j <= k; j++) {
			cin >> a >> t;
			line[a].push_back({i, t});
		}
  }
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < (int)line[i].size(); j++)
			for (int k = 0; k < j; k++) {
				pii x = line[i][j], y = line[i][k];
				dis[x.fi][y.fi] = min(dis[x.fi][y.fi], x.se + y.se);
				dis[y.fi][x.fi] = min(dis[y.fi][x.fi], x.se + y.se);
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int x, y; q; q--) {
		cin >> x >> y;
		int ans = 1e18;
		for (pii i : line[x])
			for (pii j : line[y])
				ans = min(ans, w[x] + w[y] + i.se + j.se + dis[i.fi][j.fi]);
		cout << ans << '\n';
	}
  return 0;
}
// cutecutezrr