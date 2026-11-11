#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int c, n, m, d, q, w[N], k[N], a[N][N], t[N][N], dist[N];

vector <pair <int, int>> edges[N];

map <int, int> mp[N];


int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			mp[i][a[i][j]] = j;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++)
			for (int kk = j + 1; kk <= k[i]; kk++)
				edges[j].push_back ({kk, 0}),
				edges[kk].push_back ({j, 0});
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			for (int kk = 1; kk <= n; kk++)
				if (mp[i][a[j][kk]])
					edges[j].push_back({a[j][mp[i][a[j][kk]]], t[j][mp[i][a[j][kk]]] + t[j][kk]});
		}
	}


	while(q--) {
		int s, t;
		cin >> s >> t;
		memset(dist, 127, sizeof(dist));
		dist[s] = 0;
		set <pair <int, int>> sp;
		for (int i = 1; i <= m; i++)
			sp.insert({dist[i], i});
		while (!sp.empty()) {
			int x = sp.begin()->second;
			if (dist[x] > 1 << 30)
				break;
			sp.erase(sp.begin());
			for (auto y : edges[x]) {
				if (dist[x] + y.second < dist[y.first]) {
					sp.erase({dist[y.first], y.first});
					dist[y.first] = dist[x] + y.second;
					sp.insert({dist[y.first], y.first});
				}
			}
		}
		cout << w[s] + w[t] + dist[t] << "\n";
	}
}
