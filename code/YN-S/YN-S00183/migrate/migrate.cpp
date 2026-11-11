#include <bits/stdc++.h>
using namespace std;
long long c, t, n, m, a[1000005], ans;
int dis[1000005];

struct node {
	long long x, y;
};
vector<int>e[1000005];

void bfs(int y, int z) {
	int p = 0, mi = 1e9;
	memset(dis, 0x3f, sizeof(dis));
	dis[y] = 0;
	queue<node>q;
	q.push({y, 0});
	while (!q.empty()) {
		node u = q.front();
		q.pop();
		for (int v : e[u.x]) {
			int vy = u.y + 1;
			if (abs(a[v] - a[u.x]) > m) {
				continue;
			}
			if (dis[v] > dis[u.x] + 1) {
				dis[v] = dis[u.x] + 1;
			} else if (dis[v] < dis[u.x] + 1) {
				continue;
			}
			if (v == z) {
				if (vy < mi) {
					mi = vy;
					p = 1;
				} else if (vy == mi) {
					p++;
				}
				continue;
			}
			q.push({v, vy});
		}
	}
	if (p == 2) {
		ans++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ans = 0;
		cin >> n >> m;
		for (int i = 0; i <= n; i++) {
			e[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				bfs(i, j);
			}
		}
		cout << ans << endl;
	}
	return 0;
}