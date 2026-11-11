#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 10;

int c, t, n, k, x, y;
vector<int> G[maxn];
bool vis[maxn];
int dis[maxn];

void Solve();
void DFS_1(int x, int fa);
void DFS_2(int x, int fa);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		Solve();
	}

	return 0;
}

void Solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int U = (1 << n) - 1;
	int ans = 1e9;
	for (int S = 0; S <= U; S++) {
		memset(vis, 0, sizeof vis);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += S & (1 << (i - 1));
		}
		if (cnt != k) continue;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (S & (1 << (i - 1))) {
				if (vis[i]) {
					DFS_1(i, 0);
					cnt++;
				}
			}
		}
		if (cnt > 2) continue;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (S & (1 << (i - 1)))continue;
			memset(dis, 0, sizeof dis);
			DFS_2(i, 0);
			int now = 1e9;
			for (int i = 1; i <= n; i++) {
				if (S & (1 << (i - 1))) {
					now = min(now, dis[i]);
				}
			}
			res = max(res, now);
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
}

void DFS(int x, int fa) {
	vis[x] = true;
	for (const int& y : G[x]) {
		if (y == fa) continue;
		DFS_1(y, x);
	}
}

void DFS_2(int x, int fa) {
	dis[x] = dis[fa] + 1;
	for (const int& y : G[x]) {
		if (y == fa) continue;
		DFS_2(y, x);
	}
}