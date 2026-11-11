#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7, hs = 5e6;

struct op {
	int v, w, nxt;
} a[maxn];
int len, c, n, m, d, q, head[maxn];
bool vis[maxn];
ll dis[maxn];

void init(int u, int v, int w) {
	a[++len] = {v, w, head[u]};
	head[u] = len;
}

void dj(int s) {
	priority_queue<pair<ll, int>> q;
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		int num = q.top().second;
		ll est = q.top().first;
		q.pop();
		if (vis[num])
			continue;
		for (int i = head[num]; i; i = a[i].nxt) {
			int v = a[i].v;
			if (!vis[v] && dis[v] > v + est) {
				dis[v] = v + est;
				q.push({-dis[v], v});
			}
		}
	}
}

void read() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		int w;
		scanf("%d", &w);
		init(i, i + 1, w);
		init(i + 1, i, w);
	}
	for (int i = 1; i <= n; i++) {
		int k, num, t, fr;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%d %d", &num, &t);
			init(i + hs, num, t);
			init(num, i + hs, t);
			if (fr) {
				init(fr, num, 0);
				init(num, fr, 0);
			}
			fr = num;
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		dj(2 * x);
		printf("%d", dis[2 * y]);
	}
}


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read();




	return 0;
}