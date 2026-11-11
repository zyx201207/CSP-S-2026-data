#include <bits/stdc++.h>
using namespace std;

void fileIO(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

using i64 = long long;
using pii = pair<int, int>;
const int N = 510, M = 5e5 + 10;

int testCase, n, m, dd, q;
int w[M];

vector<pii> g[M];

i64 d[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	fileIO("subway");
	
	cin >> testCase >> n >> m >> dd >> q;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(i != j) d[i][j] = 1e18;
	
	for(int i = 1; i <= m; i ++)
		cin >> w[i];

	for(int i = 1, k; i <= n; i ++) {
		cin >> k;
		for(int a, t; k; k --) {
			cin >> a >> t;
			g[a].emplace_back(i, t);
		}
	}
	
	for(int i = 1; i <= m; i ++) {
		for(int j = 0; j < g[i].size(); j ++)
			for(int k = j + 1; k < g[i].size(); k ++) {
				int u = g[i][j].first, v = g[i][k].first, w = g[i][j].second + g[i][k].second;
				d[u][v] = d[v][u] = min(d[u][v], (i64)w);
			}
	}
	
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				
	for(int s, t; q; q --) {
		cin >> s >> t;
		i64 ans = 1e18;
		for(int i = 0; i < g[s].size(); i ++)
			for(int j = 0; j < g[t].size(); j ++)
				ans = min(ans, d[g[s][i].first][g[t][j].first] + g[s][i].second + g[t][j].second);
		cout << ans + w[s] + w[t] << "\n"; 
	}
}
