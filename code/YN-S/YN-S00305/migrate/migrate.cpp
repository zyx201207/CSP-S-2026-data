#include <bits/stdc++.h>
using namespace std;
#define in cin
#define out cout
#define int long long
const int N = 5e5 + 5;
int test_c, n, d, x[N], dis[N], f[N], pos[N];
vector <int> e[N];
queue <int> q;
void solve() {
	in >> n >> d;
	for (int i = 1; i <= n; i++) e[i].clear();
	for (int i = 1; i <= n; i++) in >> x[i];
	for (int i = 1; i <= n; i++) {
		pos[i] = i; 
		for (int j = i + 1; j <= n; j++)
			if (x[j] - x[i] <= d) e[i].push_back(j), pos[i] = j;
			else break;
	}
	int ans = 0;
	for (int s = 1; s <= n; s++) {
		for (int i = s + 1; i <= n; i++) dis[i] = 1e18, f[i] = 0;
		dis[s] = 0, f[s] = 1, q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v = pos[u]; v > u; v--)
				if (dis[u] + 1 > dis[v]) break;
				else if (dis[u] + 1 < dis[v]) f[v] = f[u], dis[v] = dis[u] + 1, q.push(v);
				else if (dis[u] + 1 == dis[v]) f[v] += f[u];
		}
		for (int i = s + 1; i <= n; i++) ans += f[i] == 2;
	}
	out << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), in.tie(nullptr), out.tie(nullptr);
	int T; in >> test_c >> T;
	while (T--) solve();
	return 0;
}