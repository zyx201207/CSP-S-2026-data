#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505, MAXM = 5e5 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q;

struct Station {
	int w; // gate -> station
	vector<pair<int, long long> > t; // {line, dist}
};
Station stations[MAXM];

vector<pair<int, int> > linegraph(MAXN);

void task() {
	int x, y;
	cin >> x >> y;
	
	// common solution: bfs from virtual line 0
	vector<long long> distance(n + 1, INF);
	vector<bool> vis(m + 1, false);
	priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<int, int> > > pq;
	// {distance, line} 
	for (auto u : stations[x].t) {
		int line = u.first; long long dist = u.second;
		pq.push({dist, line});
		distance[line] = 0;
		vis[line] = true;
	}
	
	vector<bool> finalLines(n + 1, false);
	for (auto u : stations[y].t) {
		int line = u.first; finalLines[line] = true;
	}
	
	while (!pq.empty()) {
		auto u = pq.top();
		pq.pop();
		
		int line = u.first; long long dist = u.second;
		
		
		
		if (finalLines[line]) {
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) { // i: station
		cin >> stations[i].w;
	}
	for (int i = 1; i <= n; ++i) { // i: line number
		int k, a, time; cin >> k; // a: station number
		vector<int> as;
		for (int j = 1; j <= k; ++j) {
			cin >> a >> time;
			as.push_back(a);
			stations[a].t.push_back({i, time});
		}
	}
	
	while (q--) {
		task();
	}
	
	return 0;
}
