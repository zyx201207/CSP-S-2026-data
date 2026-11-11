#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
int c, n, m, d, q;
int gates[500001];
int lines[500001];
int tr[500001][41];
int cross[500001][41];
int father[500001];
int hp = 2;
int tot, head[1000001], nxt[1000001], to[1000001], weight[1000001];
int dis[5000001];
bool vis[5000001];
void add_edge(int u, int v, int w) {
	tot++;
	nxt[tot] = head[u];
	if (tot == head[u]) std::cout << u << " " << v << " " << tot << " " << head[u] << "\n";
	to[tot] = v;
	head[u] = tot;
	weight[tot] = w;
}
struct node {
public:
	int dis, u;
	bool operator < (const node& a) const {
		return dis < a.dis;
	}
	bool operator > (const node& a) const {
		return dis > a.dis;
	}
};
bool dijkstra(int st) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	dis[st] = 0; 
	std::priority_queue <node, std::vector <node>, std::greater <node>> q;
	q.push((node){ 0, st });
	while (!q.empty()) {
		int u = q.top().u, v, w;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = head[u]; i; i = nxt[i]) {
			v = to[i];
			w = weight[i];
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push((node){ dis[v], v });
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		std::cin >> gates[i];
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> lines[i];
		int lst, ltr;
		std::cin >> lst >> ltr;
		for (int j = 1; j < lines[i]; j++) {
			
			int x;
			std::cin >> x;
			
			hp++;
			cross[lst][0]++;
			cross[lst][cross[lst][0]] = hp;
			cross[x][0]++;
			cross[x][cross[x][0]] = hp;
			father[hp] = i;
			
			int ntr;
			std::cin >> ntr;
			
			tr[lst][cross[lst][0]] = ltr;
			tr[x][cross[x][0]] = ntr;
			
			hp++;
			cross[lst][0]++;
			cross[lst][cross[lst][0]] = hp;
			cross[x][0]++;
			cross[x][cross[x][0]] = hp;
			father[hp] = i;
			
			tr[lst][cross[lst][0]] = ltr;
			tr[x][cross[x][0]] = ntr;
			
			lst = x;
			ltr = ntr;
			
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= cross[i][0]; j++) {
			for (int k = 1; k <= cross[i][0]; k++) {
				if (father[cross[i][j]] == father[cross[i][k]]) {
					if (j != k) {
						add_edge(cross[i][j], cross[i][k], 0);
						add_edge(cross[i][k], cross[i][k], 0);
					}
					continue;
				}
				add_edge(cross[i][j], cross[i][k], tr[i][j] + tr[i][k]);
				add_edge(cross[i][k], cross[i][j], tr[i][k] + tr[i][j]);
			}
		}
	}
	int cot = tot;
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		tot = cot;
		head[1] = 0;
		head[2] = 0;
		for (int i = 1; i <= cross[x][0]; i++) {
			add_edge(1, cross[x][i], gates[x] + tr[x][i]);
		}
		std::queue <int> q;
		for (int i = 1; i <= cross[y][0]; i++) {
			q.push(i);
		}
		dijkstra(1);
		int ans = 0x3f3f3f3f; 
		while (!q.empty()) {
			ans = std::min(ans, dis[cross[y][q.front()]] + gates[y] + tr[y][q.front()]);
			q.pop();
		}
		std::cout << ans << "\n";
	}
	return 0;
}
