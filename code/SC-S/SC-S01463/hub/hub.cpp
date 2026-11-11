#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int c, t, n, k;
struct Node {
	vector<int> b;
	int fa;
	int dist;
	bool operator < (const Node& other) const {
		return dist < other.dist;
	}
} node[1000005];
bool vis[1000005];
void init() {
	for (int i = 1; i <= n; i++) node[i].fa = i, node[i].dist = 0, node[i].b.clear();
}
int get(int x) {
	if (x == node[x].fa) return x;
	return node[x].fa = get(node[x].fa); 
}
void unite(int u, int v) {
	int a = get(u), b = get(v);
	if (a == b) {
		node[u].dist = node[v].dist = max(node[u].dist, node[v].dist);
	} else {
		node[a].fa = b;
		node[u].dist = node[v].dist = node[u].dist + node[v].dist + 1;
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		init();
		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			unite(u, v);
			node[u].b.push_back(v);
			node[v].b.push_back(u);
		}
		sort(node + 1, node + n + 1);
		int cnt = 0, s = 0, ans = 1;
		for (int i = 1; i <= n; i++) {
			if (cnt == k) break;
			if (s == 2) {
				bool f = 0;
				int sz = node[i].b.size();
				for (int j = 0; j < sz; j++) {
					if (vis[node[i].b[j]]) {
						f = 1;
						break;
					}
				}
				if (!f) continue;
			}
			cnt++;
			vis[i] = 1;
			ans = node[i].dist;
		}
		printf("%d\n", ans - 1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}