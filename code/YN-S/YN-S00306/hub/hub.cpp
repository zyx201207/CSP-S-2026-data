#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k, c, T, vis[15], dis[15][15], ans, p[15];
vector<int>e[N];

void dfs(int x, int f, int sta) {
	vis[x] = 1;
	for (int i = 0; i < e[x].size(); i++) {
		int v = e[x][i];
		if (v == f)
			continue;
		if (sta & (1 << (v - 1)))
			dfs(v, x, sta);
	}
}

void dfs2(int s, int x, int f) {
	dis[s][x] = dis[s][f] + 1;
	for (int i = 0; i < e[x].size(); i++) {
		int v = e[x][i];
		if (v == f)
			continue;
		dfs2(s, v, x);
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--) {
		cin >> n >> k;
		ans = 1e9;
		for (int i = 1; i <= n; i++)
			e[i].clear();
		for (int i = 1, x, y; i < n; i++)
			cin >> x >> y, e[x].push_back(y), e[y].push_back(x);
		if (n <= 10) {
			for (int i = 0; i < (1 << n); i++) {
				if (__builtin_popcount(i) != k)
					continue;
				for (int j = 1; j <= n; j++)
					vis[j] = 0;
				int cnt = 0;
				for (int j = 1; j <= n; j++) {
					if ((i & (1 << (j - 1))) && !vis[j])
						dfs(j, 0, i), cnt++;
				}
				if (cnt <= 2) {
					for (int j = 1; j <= n; j++)
						for (int t = 1; t <= n; t++)
							dis[j][t] = 0;
					for (int j = 1; j <= n; j++)
						dis[j][0] = -1, dfs2(j, j, 0), p[j] = 1e9;
					int res = 0;
					for (int j = 1; j <= n; j++) {
						for (int t = 1; t <= n; t++) {
							if (i & (1 << (t - 1)))
								p[j] = min(p[j], dis[j][t]);
						}
					}
					for (int j = 1; j <= n; j++)
						res = max(res, p[j]);
					ans = min(ans, res);
				}
			}
			cout << ans << "\n";
		} else {
			if (n == k) {
				cout << 0 << "\n";
				continue;
			}
			int p = n / 2;
			p -= k;
			if (p <= 0) {
				cout << 1 << "\n";
				continue;
			}
			if (p % 4 == 0)
				cout << p / 4 + 1 << "\n";
			else
				cout << p / 4 + 2 << "\n";
		}
	}
	return 0;
}