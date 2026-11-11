#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e5 + 505;

struct node {
	int v, w;
};
int dis[MAXN];

struct nodep {
	int dis, u;
	friend bool operator<(nodep a, nodep b) {
		return a.dis > b.dis;
	}
};
int w[MAXN];
vector<node>g[MAXN];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			g[i + m].push_back({a, t});
			g[a].push_back({i + m, t});
		}
	}
	while (q--) {
		int s, e;
		cin >> s >> e;
		priority_queue<nodep>q;
		memset(dis, 0x3f, sizeof dis);
		q.push({0, s});
		dis[s] = 0;
		while (!q.empty()) {
			int u = q.top().u;
			int d = q.top().dis;
			q.pop();
//			cout << u << ' ';
			for (auto &it : g[u]) {
				int v = it.v;
				int w = it.w;

				if (d + w < dis[v]) {
					dis[v] = d + w;
					q.push({dis[v], v});
				}
			}
		}
//		for (int i = 1; i <= m; i++)
//			cout << dis[i] << ' ';
//		cout << '\n';
		cout << dis[e] + w[s] + w[e] << '\n';
	}
	return 0;
}