#include <bits/stdc++.h>
using namespace std;

int c, t;
int f[105][105];
vector<int> e[1000005];

bitset<1000005> ch;
bitset<1000005> vis;

void bfs(int s) {
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		for (int v : e[u]) {
			if (ch[v]) {
				q.push(v);
			}
		}
	}
}

int main() {
	fropen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			e[i].clear();
			f[i][i] = 0;
			for (int j = i + 1; j <= n; j++) {
				f[i][j] = f[j][i] = 1e9;
			}
		}
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
			f[u][v] = f[v][u] = 1;
		}
		int ans = 1e9;
		for (int i = 1; i < (1 << n); i++) {
			if (__builtin_popcount(i) != k) {
				continue;
			}
			for (int j = 1; j <= n; j++) {
				vis[i] = false;
				ch[i] = false;
			}
			vector<int> p;
			for (int j = 1; j <= n; j++) {
				if ((i >> (j - 1)) & 1) {
					p.emplace_back(j);
					ch[j] = true;
				}
			}
			int cnt = 0;
			bool fl = true;
			for (int nd : p) {
				if (!vis[nd]) {
					bfs(nd);
					if (++cnt > 2) {
						fl = false;
						break;
					}
				}
			}
			if (!fl) {
				continue;
			}
			int f1[105][105];
			memcpy(f1, f, sizeof (f));
			for (int z = 1; z <= n; z++) {
				for (int x = 1; x <= n; x++) {
					for (int y = 1; y <= n; y++) {
						f1[x][y] = min(f1[x][y], f1[x][z] + f1[z][y]);
					}
				}
			}
			bitset<105> inp;
			for (int x : p) {
				inp[x] = true;
			}
			int mx = 0;
			for (int x = 1; x <= n; x++) {
				if (!inp[x]) {
					int tmp = 1e9;
					for (int y : p) {
						tmp = min(tmp, f1[x][y]);
					}
					mx = max(mx, tmp);
				}
			}
			ans = min(ans, mx);
		}
		cout << ans << '\n';
	}
	return 0;
}