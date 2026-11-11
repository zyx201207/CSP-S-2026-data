#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

std::ifstream fin("subway.in");
std::ofstream fout("subway.out");
int c, n, m, d, q;
int w[500005];
int t[505][505];
int a[505][505];
std::vector<std::pair<int, int>> adj[500005]; //相邻的地铁站，线路 
bool visited[500005] = {0}; 

struct node {
	int station, steps, from;
}; 

int main() {
	fin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) { 
		fin >> w[i];
	}
	for (int i = 1; i <= n; ++i) { //第i条铁路 
		int k;
		fin >> k;
		for (int j = 1; j <= k; j++) { 
			fin >> t[i][j] >> a[i][t[i][j]];
			if (j > 1) {
				adj[t[i][j]].push_back({t[i][j - 1], i});
				adj[t[i][j - 1]].push_back({t[i][j], i});
			} 
		}
	}
	while (q--) {
		for (int i = 0; i < n; ++i) visited[i] = 0;
		int x, y;
		fin >> x >> y;
		int ans = 0x3f3f3f3f;
		std::queue<node> q;
		q.push({x, w[x], 0});
		visited[x] = 1;
		while (!q.empty()) {
			node cur = q.front();
			if (cur.station == y) {
				int steps = cur.steps;
				steps += a[cur.from][cur.station];
				steps += w[cur.station];
				ans = std::min(steps, ans);
			}
			for (int i = 0; i < adj[cur.station].size(); ++i) {
				auto next = adj[cur.station][i];
				if (!visited[next.first]) {
					int next_steps = cur.steps;
					if (cur.from != next.second) {
						next_steps += a[next.second][cur.station];
					}
					q.push({next.first, next_steps, next.second});
					visited[next.first] = 1;
				}
			}
			q.pop();
		}
		fout << ans << "\n";
	}
}
