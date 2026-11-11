#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef __int128 i128;

int n, k;
ll ans, dis[5005][5005];
vector <int> to[1000005];

int ddd(int x) {
	int cnt = 0;
	while (x) {
		cnt ++;
		x -= (x & -x);
	}
	return cnt;
}
bool liantong(int mask) {
	for (int i = 1; i <= n; i ++) {
		if ((mask >> i - 1) & 1) {
			for (int j = 1; j <= n; j ++) {
				if ((mask >> j - 1) & 1) {
					if (dis[i][j] > 1) return 0;
				}
			}
		}
	}
	return 1;
}
void solve() {
	ans = 0x3f3f3f3f3f3f3f3f;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) to[i].clear();
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) dis[i][j] = (i != j) * 0x3f3f3f3f3f3f3f3f;
	for (int i = 1, u, v; i < n; i ++) {
		cin >> u >> v;
		to[u].emplace_back(v);
		to[v].emplace_back(u);
		dis[u][v] = dis[v][u] = min(dis[u][v], 1ll);
	}
	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	if (k == 1) {
		for (int i = 1; i <= n; i ++) {
			ll tmp = 0;
			for (int j = 1; j <= n; j ++) tmp = max(tmp, dis[i][j]);
			ans = min(ans, tmp);
		}
		cout << ans << '\n';
	} else if (k == 2) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				ll tmp = 0;
				for (int z = 1; z <= n; z ++) {
					tmp = max(tmp, min(dis[z][i], dis[z][j]));
				}
				ans = min(ans, tmp);
			}
		}
		cout << ans << '\n';
	} else {
		for (int i = 0; i < (1 << n); i ++) {
			if (ddd(i) > k || !liantong(i)) continue ;
			for (int j = 0; j < (1 << n); j ++) {
				if (ddd(j) > k - ddd(i) || !liantong(j) || (i & j) != 0) continue ;
				ll tmp = 0;
				for (int z = 1; z <= n; z ++) {
					ll ggg = 0x3f3f3f3f3f3f3f3f;
					for (int x = 1; x <= n; i ++) {
						if (((i >> x - 1) & 1) || ((j >> x - 1) & 1)) ggg = min(ggg, dis[x][z]);
					}
					tmp = max(tmp, ggg);
				}
				ans = min(ans, tmp);
				if (clock() >= 2.80/60/60/100) {
					cout << ans << '\n';
					exit(0);
				}
			}
		}
		cout << ans << '\n';
	}
	return ;
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T >> T;
	while (T --) solve();
	return 0;
}
