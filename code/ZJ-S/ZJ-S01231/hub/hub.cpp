#include <iostream>
#include <queue>

struct Edge {
	int to;
	int next;
} edge[4000000];

int cnt = 0;
int head[2000001] = {};
int n = 0;
int k = 0;
bool chose[2000001] = {};
int dist[2000001] = {};
int ans = 0;

void add_edge(int x, int y) {
	edge[++cnt].to = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
}

void cover(int p) {
	dist[p] = 1;
	
	for (int i = head[p]; i; i = edge[i].next) {
		int u = edge[i].to;
		
		if (!dist[u] && chose[u]) {
			cover(u);
		}
	}
}

int bfs() {
	std::queue<int> que;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (chose[i]) {
			que.emplace(i);
		}
	}
	
	while (!que.empty()) {
		int pt = que.front();
		que.pop();
		
		for (int i = head[pt]; i; i = edge[i].next) {
			int u = edge[i].to;
			
			if (!dist[u]) {
				dist[u] = dist[pt] + 1;
				res = std::max(res, dist[pt]);
				que.emplace(u);
			}
		}
	}
	
	return res;
}

void dfs(int idx, int cnt) {
	if (idx > n) {
		int tot = 0;
		for (int i = 1; i <= n; ++i) {
			if (chose[i] && !dist[i]) {
				cover(i);
				++tot;
			}
		}
		
		if (tot <= 2) {
			ans = std::min(ans, bfs());
		}
		for (int i = 1; i <= n; ++i) {
			dist[i] = 0;
		}
		
		return ;
	}
	
	if (n - idx >= k - cnt) {
		dfs(idx + 1, cnt);
	}
	if (cnt < k) {
		chose[idx] = true;
		dfs(idx + 1, cnt + 1);
		chose[idx] = false;
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int test = 0;
	int t = 0;
	std::cin >> test >> t;
	
	while (t--) {
		std::cin >> n >> k;
		
		ans = 1e9;
		cnt = 0;
		for (int i = 1; i <= n; ++i) {
			head[i] = 0;
		}
		for (int i = 1; i < n; ++i) {
			int x = 0;
			int y = 0;
			std::cin >> x >> y;
			add_edge(x, y);
			add_edge(y, x);
		}
		
		dfs(1, 0);
		
		std::cout << ans << '\n';
	}
	
	return 0;
}