#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <iomanip>
#define pii pair<int, int>
using namespace std;
int c, n, m, d, q;
const int N = 505, M = 5e5 + 10;
vector<pii> g[M];
int v[N], w[N];

inline int lobby(int x) {
	return m + x;
}

inline int entrance(int x) {
	return x;
}

inline int stage(int k, int x) {
	return (k + 1) * m + x;
}

int dis[5005][5005];

void dijk(int s) {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	dis[s][s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		for (auto p : g[u]) {
			int v = p.first, w = p.second;
			if (dis[s][v] > dis[s][u] + w) {
				dis[s][v] = dis[s][u] + w;
				q.push({dis[s][v], v});
			}
			//cout << v << endl;
		}
	}
}

int main() {
	memset(dis, 0x3f, sizeof dis);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		int w;
		cin >> w;
		g[entrance(i)].push_back({lobby(i), w});
		g[lobby(i)].push_back({entrance(i), w});
	}
	for (int i = 1; i <= n * 2; i++) {
		int k;
		cin >> k;
		int lst;
		for (int j = 1; j <= k; j++) {
			int v[j], w[j];
			cin >> v[j] >> w[j];
			if (j == 1) {
				lst = stage(i, v[j]);
			} else {
				g[lst].push_back({stage(i, v[j]), 0});
				//cout << "! " << lst << " " << stage(i, v[j]) << endl;
				lst = stage(i, v[j]);
			}
			g[lobby(v[j])].push_back({stage(i, v[j]), w[j]});
			g[stage(i, v[j])].push_back({lobby(v[j]), w[j]});
		}
		i++;
		for (int j = k; j >= 1; j--) {
			if (j == k) {
				lst = stage(i, v[j]);
			} else {
				g[lst].push_back({stage(i, v[j]), 0});
				//cout << "! " << lst << " " << stage(i, v[j]) << endl;
				lst = stage(i, v[j]);
			}
			g[lobby(v[j])].push_back({stage(i, v[j]), w[j]});
			g[stage(i, v[j])].push_back({lobby(v[j]), w[j]});
		}
	}
	for (int i = 1; i <= stage(n * 2, m); i++) {
		dijk(entrance(i));
	}
//	for (int u = 1; u <= stage(n * 2, m); u++) {
//		cout << "\n\n" << u << endl;
//		for (auto to : g[u]) {
//			int v = to.first;
//			cout << v << " ";
//		}
//	}
	while(q--) {
		int s, t;
		cin >> s >> t;
		cout << dis[s][t] << endl;
	}
	return 0;
}
