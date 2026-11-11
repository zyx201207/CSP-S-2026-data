#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <climits>

// Wo Bu Hui Xie Floyd 55555555555~ TAT
// CCF! WHY U SET MAXN = 500! I ONLY LEARNED Dijkstra! T^T

using ll = long long;
constexpr ll MAXN = 500 + 114, MAXM = 5e5 + 114, MAXD = 20 + 114, MAXQ = 1e5 + 114;

struct Edge {
	ll dist = 0; ///< distance before it has been pushed into pq
	ll tgt; ///< Target Node
	ll l; ///< Edge length
	bool operator<(const Edge &other) const {
		return dist > other.dist;
	}
};

std::vector<std::vector<Edge>> graph(MAXN * 2); ///< graph[i][j] = j th subnode's index of Node i
ll dist[MAXN][MAXN]; ///< dist[i][j] = Min distance from i to j

int c, n, m, d, q;

bool visited[MAXN];

void dijkstra(ll s) {
	memset(visited, 0, sizeof(visited)); ///< reset visited = {0}
	std::priority_queue<Edge> pq;
	dist[s][s] = 0;
	Edge start;
	start.dist = 0;
	start.tgt = s;
	start.l = 0;
	pq.push(start);
	while(!pq.empty()) {
		Edge cur = pq.top();
		pq.pop();
		if(visited[cur.tgt]) {
			continue;
		}
		visited[cur.tgt] = true;
		for(const Edge &sub_node : graph[cur.tgt]) {
			if(visited[sub_node.tgt]) {
				continue;
			}
			dist[s][sub_node.tgt] = std::min(dist[s][sub_node.tgt], dist[s][cur.tgt] + sub_node.l);
			Edge pushed;
			pushed.dist = dist[s][sub_node.tgt];
			pushed.tgt = sub_node.tgt;
			pushed.l = sub_node.l;
			pq.push(pushed);
		}
	}
}

int w[MAXM];
std::vector<std::vector<ll>> sites(MAXM); ///< sites[i][j]: Site i's j th line
std::vector<std::vector<ll>> times(MAXM, std::vector<ll>(MAXN)); ///< times[i][j]: Site i's hub to the line j's time

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	for(int i = 0; i < MAXN; ++i) {
		for(int j = 0; j < MAXN; ++j) {
			dist[i][j] = LONG_MAX;
		}
	}
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w+", stdout);
	std::cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) {
		std::cin >> w[i];
	}
	for(int i = 1; i <= n; ++i) {
		int site_count;
		std::cin >> site_count;
		for(int j = 1; j <= site_count; ++j) {
			int a, t;
			std::cin >> a >> t;
			sites[a].push_back(i);
			times[a][i] = t;
		}
	}
	// Make Graph
	for(int i = 1; i <= m; ++i) {
		for(const ll &line_A : sites[i]) {
			for(const ll &line_B : sites[i]) {
				Edge edge;
				edge.tgt = line_B;
				edge.l = times[i][line_A] + times[i][line_B];
				graph[line_A].push_back(edge);
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		dijkstra(i);
	}
	for(int i = 1; i <= q; ++i) {
		int x, y;
		std::cin >> x >> y;
		int result = INT_MAX;
		for(const ll &x_line : sites[x]) {
			for(const ll &y_line : sites[y]) {
				result = std::min((ll)result, dist[x_line][y_line] + w[x_line] + w[y_line]);
			}
		}
		std::cout << result << std::endl;
	}
	return 0;
}
