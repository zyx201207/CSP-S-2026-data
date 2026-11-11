#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;

struct Edge {
	int v, w, nxt;
} e[N];
int f[N], cnt, z[N], vis[N], dis[N], ans;
int w[N];
int t[505][25];
int c, n, m, d, p;
int mp[505][505];

void insert(int u, int v) {
	e[++cnt] = {v, 1, f[u]};
	f[u] = cnt;
}

void spfa(int x, int y) {
	memset(z, 0, sizeof z);
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	dis[x] = 0;
	vis[x] = 1;
	queue<int> q;
	q.push(x);
	z[x] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (vis[u] == 0)
			continue;
		vis[u] = 0;
		for (int j = f[u]; j; j = e[j].nxt) {
			int v = e[j].v, w = e[j].w;
			if (dis[u] + w < dis[v] and mp[z[u]][v] != 0) {
				dis[v] = dis[u] + w;
				vis[v] = 1;
				q.push(v);
				z[v] = u;
			} else if (mp[z[u]][v] == 0) {
				if (dis[u] + t[mp[z[u]][u]][u] + t[mp[u][v]][u] < dis[v]) {
					dis[v] = dis[u] + t[mp[z[u]][u]][u] + t[mp[u][v]][u];
					vis[v] = 1;
					q.push(v);
					z[v] = u;
				}
			}
		}
	}
	int sum = 0, tmp = y, jl1 = 0, jl2 = 0;
	for (int i = z[y]; i; i = z[i]) {
		if (mp[z[i]][tmp] == 0) {
			sum += (t[mp[z[i]][i]][i] + t[mp[i][tmp]][i]);
		}
		if (i == x)
			jl1 = mp[i][tmp];
		if (i == z[y])
			jl2 = mp[z[y]][y];
		tmp = i;
	}
	sum += (w[x] + t[jl1][x] + t[jl2][y] + w[y]);
	ans = min(ans, sum);
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k, cd[d + 10] = {0}, R;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> R;
			cin >> t[i][R];
			if (j != 1) {
				for (int gg = 0; gg < j; gg++)
					insert(cd[gg], R);

			}
			for (int gg = 0; gg < j; gg++)
				mp[cd[gg]][R] = i;
			cd[j] = R;
		}
	}
	for (int bb = 1; bb <= p; bb++) {
		int x, y;
		ans = INT_MAX;
		cin >> x >> y;
		spfa(x, y);
		cout << ans << '\n';
	}
	return 0;
}