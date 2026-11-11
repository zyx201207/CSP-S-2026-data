#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

struct node {
	int v, e;
	bool operator<(const node& other) const {
		return e > other.e;
	}
};

int n, d, a[N], dis[N], c[N];
vector<int> g[N];
bitset<N> vis;

void dijstra(int start) {
	priority_queue<node> q;
	vis.reset();
	memset(dis, 0x3f, sizeof(dis));
	memset(c, 0, sizeof(c));
	dis[start] = 0;
	c[start] = 1;
	q.push({start, 0});
	while (!q.empty()) {
		node t = q.top(); q.pop();
		if (vis[t.v]) continue;
		vis[t.v] = true;
		for (auto z : g[t.v]) {
			if (!vis[z] && dis[z] > t.e + 1) {
				dis[z] = t.e + 1;
				c[z] = c[t.v];
				q.push({z, t.e + 1});
			} else if (dis[z] == t.e + 1) {
				c[z] += c[t.v];
			}
		}
	}
}

void slove() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		g[i].clear();
		for (int j = i - 1; j >= 1; j--) {
			if (a[i] - a[j] <= d) {
				g[i].push_back({j});
				g[j].push_back({i});
			} else break;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		dijstra(i);
		for (int j = 1; j <= n; j++) {
			if (c[j] == 2) {
				cnt++;
			}
		}
	}
	printf("%d\n", cnt >> 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) slove();
	return 0;
}
