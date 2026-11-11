#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Pii pair<int, int>
#define fst first
#define snd second
const int N = 510, M = 5e5 + 10;
int c, n, m, d, q, u, v, t, minn;
int w[M], dis[N][N], k[N];
vector<Pii> e[M];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++ i)
		cin >> w[i];
	memset(dis, 0xf, sizeof(dis));
	for (int i = 1; i <= n; ++ i) dis[i][i] = 0;
	for (int i = 1; i <= n; ++ i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++ j) {
			cin >> v >> t;
			for (auto k : e[v]) dis[i][k.snd] = dis[k.snd][i] = min(dis[i][k.snd], t + k.fst);
			e[v].push_back({t, i});
		}
	}
	for (int k = 1; k <= n; ++ k) for (int i = 1; i <= n; ++ i) for (int j = i + 1; j <= n; ++ j) dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
	
	while (q --) {
		cin >> u >> v;
		minn = 0x3f3f3f3f3f3f3f3f;
		for (auto i : e[u]) {
			for (auto j : e[v]) {
				minn = min(minn, i.fst + j.fst + dis[i.snd][j.snd]);
			}
		}
		cout << minn + w[u] + w[v] << '\n';
	}
	return 0;
}

