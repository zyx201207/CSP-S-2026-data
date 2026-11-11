#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int v, w;
};

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	
	cin >> c >> n >> m >> d >> q;
	
	vector<int> w(m + 1);
	
	for (int i = 1; i <= m; i++) cin >> w[i];
	
	vector< vector<Edge> > g(m + 1);
	while (n--) {
		int k;
		cin >> k;
		
		
		vector<int> a(k), t(k);
		for (int i = 0; i < k; i++) {
			cin >> a[i] >> t[i];
		}
		
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
			    if (i != j) {
			    	g[a[i]].push_back({j + 1, t[i]});
				}
		    }
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << i << ":";
        	for (int j = 0; j < static_cast<int>(g[i].size()); j++) {
				Edge e = g[i][j];
			}
    }
	
	while (q--) {
		int s, v;
		cin >> s >> v;
		
		int INF = 0xAC6666;
		vector<int> dist(m, INF);
		dist[s] = 0;
		
		priority_queue<
		    pair<int, int>,
		    vector< pair<int, int> >,
		    greater< pair<int, int> >
		> pq;
		
		pq.push({0, s});
		
		
		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			
			int d = p.first;
			int u = p.second;
			
			if (d != dist[u]) continue;
			
			for (int i = 0; i < static_cast<int>(g[u].size()); i++) {
				Edge e = g[u][i];
				int newDist = d + e.w + w[u] + w[e.v];
				if (newDist < dist[e.v]) {
					dist[e.v] = newDist;
					pq.push({newDist, e.v});
				}
			}
		}
		
		cout << dist[v] << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}