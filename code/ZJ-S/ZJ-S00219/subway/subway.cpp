#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 5e2 + 10;
const int M = 5e5 + 10;
const int Q = 1e5 + 10;
ll c, n, m, d, q;
ll w[M], k[N], a[N][N], t[N][N];
ll x, y;
struct Node {
	int dis;
	int pos;
	bool operator <(const Node &x) const{
		return x.dis < dis;
	}
};
struct node {
	int to;
	int w;
	int nxt;
} e[N];
ll dis[M];
ll head[M];
ll tot = 0;
ll vis[M];
void add(int u, int v, int w) {
	e[++tot].nxt = head[u];
	e[tot].to = v;
	e[tot].w = w;
	head[u] = tot;
}
void dijkstra(int x){
	priority_queue<Node> q;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[x] = 0;
	q.push((Node){x, 0});
	while (!q.empty()) {
		Node t = q.top();
		q.pop();
		int u = t.dis;
		int w = t.pos;
		if (vis[u] == 1) continue;
		vis[u] = 1;
		for (int i = head[u]; i != -1; i = e[i].nxt) {
			int v = e[i].to;
			if (dis[v] > e[i].w + w) {
				dis[v] = e[i].w + w;
				if (vis[v] == 0) q.push((Node){v, dis[v]});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(head, -1, sizeof(head));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][j];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k[i]; j++)
			for (int o = 1; o <= k[i]; o++) {
				if (o == j) continue;
//				cout << a[i][j] << " " << a[i][o] << " " << t[i][j] + t[i][o] << '\n';
				add(a[i][j], a[i][o], t[i][j] + t[i][o]);
				add(a[i][o], a[i][j], t[i][j] + t[i][o]);
			}
	while (q--) {
		cin >> x >> y;
		dijkstra(x);
		cout << dis[y] + w[x] + w[y] << '\n';
	}
	return 0;
}

