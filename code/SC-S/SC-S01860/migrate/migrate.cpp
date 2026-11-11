#include <bits/stdc++.h>

#define ll long long
#define str string
#define db double

using namespace std;

constexpr ll MAXN = 5005;

ll c, t, n, d, ans, start_, end_, pos[MAXN], dis[MAXN][MAXN];
vector<ll> grh[MAXN];

int dfs(ll now, ll Dis) {
	if (Dis + dis[now][end_] > dis[start_][end_]) return 0;
	if (now == end_ && Dis == dis[start_][end_])
		return 1;
	
	ll ret = 0;

	for (const auto& v : grh[now])
		ret += dfs(v, Dis + 1);

	return ret;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> c >> t;
	while (t--) {
		memset(dis, 0x3f, sizeof dis);
		ans = 0;
		fill(grh, grh + MAXN, vector<ll>());

		cin >> n >> d;
		for (int i = 1; i <= n; ++i) {
			cin >> pos[i];
			for (ll j = i - 1; j >= 1; j--)
				if (pos[i] - pos[j] <= d) {
					grh[i].emplace_back(j);
					grh[j].emplace_back(i);
					dis[j][i] = dis[i][j] = 1;
				} else
					break;
			dis[i][i] = 0;
		}

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);

		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j) {
				start_ = i, end_ = j;
				if (dis[i][j] > 1e18) continue;
				if (dfs(i, 0) == 2) {
					ans++;
				}
			}
		
		cout << ans << '\n';
	}

	return 0;
}