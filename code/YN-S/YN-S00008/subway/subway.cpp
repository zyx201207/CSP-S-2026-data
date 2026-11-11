#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

inline ll read() {
	ll num = 0, sign = 1;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		sign = ch == '-' ? -1 : 1, ch = getchar();
	while ('0' <= ch && ch <= '9')
		num = (num << 1) + (num << 3) + ch - '0', ch = getchar();
	return sign < 0 ? -num : num;
}
const int MAXM = 5e5 + 8;
const int MAXN = 5e2 + 8;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q;
ll val[MAXM], dis[MAXN][MAXN];
vector<pair<int, ll> > u2path[MAXM];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++) {
		val[i] = read();
	}
	for (int i = 1, k; i <= n; i++) {
		k = read();
		for (int j = 1, a, t; j <= k; j++) {
			a = read(), t = read();
			u2path[a].push_back({i, t});
		}
	}
	memset(dis, INF, sizeof(dis));
	for (int id = 1; id <= n; id++)
		dis[id][id] = 0;
	for (int u = 1; u <= m; u++) {
		for (auto [uid, wt1] : u2path[u]) {
			for (auto [vid, wt2] : u2path[u]) {
				if (uid == vid)
					continue;
				dis[uid][vid] = min(dis[uid][vid], wt1 + wt2);
			}
		}
	}
	for (int kid = 1; kid <= n; kid++)
		for (int uid = 1; uid <= n; uid++)
			for (int vid = 1; vid <= n; vid++) {
				dis[uid][vid] = min(dis[uid][vid], dis[uid][kid] + dis[kid][vid]);
			}

	while (q--) {
		int x, y;
		x = read(), y = read();
		ll ans = INF;
		for (auto [uid, uwt] : u2path[x]) {
			for (auto [vid, vwt] : u2path[y]) {
				ans = min(ans, uwt + dis[uid][vid] + vwt);
			}

		}
		cout << ans + val[x] + val[y] << "\n";
	}
	return 0;
}