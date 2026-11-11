#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int> >> G(500010);
int w[500010], t[500][500010];
int dis[500010];

void dij(int s) {
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({0, s});
	dis[s] = 0;
	while (!pq.empty()) {
		auto NEW = pq.top();
		int time = NEW.first, u = NEW.second;
		pq.pop();
		for (auto v : G[u]) {
			if (v.first + time < dis[v.second]) {
				dis[v.second] = v.first + time;
				pq.push({dis[v.second], v.second});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c, n, m, d, p;
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i ++) {
		cin >> w[i];
		//G[i].emplace_back({w[i], i})
	}

	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		vector<int> v(k);
		for (int j = 1; j <= k; j ++) {
			cin >> v[j] >> t[i][v[j]];
		}

		for (int j = 2; j <= k; j ++) {
			G[v[j]].push_back({t[i][v[j]] + t[i][v[j - 1]], v[j - 1]});
			G[v[j - 1]].push_back({t[i][v[j]] + t[i][v[j - 1]], v[j]});
		}
		G[v[1]].push_back({t[i][v[1]] + t[i][v[k]], v[k]});
		G[v[k]].push_back({t[i][v[1]] + t[i][v[k]], v[1]});

//		for (int x = 1; x <= n; x ++) {
//			for (int j = 1; j <= k; j ++) {
//				cout << t[x][j] << ' ';
//			}
//			cout << '\n';
//		}
//		cout << '\n';

	}

//	cout << '\n';
//
//	for (int i = 1; i <= m; i ++) {
//		for (auto edge : G[i]) {
//			cout << i << ' ' << edge.second << ' ' << edge.first << '\n';
//		}
//	}
//	cout << '\n';

	while (p --) {
		int s, e;
		cin >> s >> e;
		dij(s);
		cout << dis[e] + w[s] + w[e] << '\n';
	}

	return 0;
}
