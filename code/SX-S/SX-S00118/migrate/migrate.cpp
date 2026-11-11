#include <bits/stdc++.h>
using namespace std;
queue <int> q;
long long c, t, n, m, d, ans, tot, x[114514], head[114514], dist[114514], vis[114514], num[114514];

struct node {
	int nxt;
	int to;
} e[114514];

void add(int u, int v) {
	e[++tot].nxt = head[u];
	head[u] = tot;
	e[tot].to = v;
}

void SPFA() {
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		for (int i = head[s]; i; i = e[i].nxt) {
			int a = e[i].to;
			if (!vis[a]) {
				vis[a] = 1;
				q.push(a);
			}
			if (dist[s] + 1 < dist[a]) {
				dist[a] = dist[s] + 1;
				num[a] = 0;
				vis[a] = 0;
				continue;
			}
			if (dist[s] + 1 == dist[a]) {
				num[a]++;
			}
		}

	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while (t--) {
		memset(num, 0, sizeof(num));
		memset(head, 0, sizeof(head));
		memset(x, 0, sizeof(x));
		memset(e, 0, sizeof(e));
		tot = 0;
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++)
				if (x[j] - x[i] <= d) {
					add(j, i);
					add(i, j);
				} else
					break;
		}
		//	for (int i = 1; i <= n; i++) {
		//		printf("%d", i);
		//		for (int j = head[i]; j; j = e[j].nxt)
		//		printf(" %d", e[j].to);
		//	printf("\n");
		//		}
		for (int j = 1; j <= n; j++) {
			memset(vis, 0, sizeof(vis));
			memset(dist, 0x3f, sizeof(dist));
			dist[j] = 0;
			q.push(j);
			SPFA();
			ans = 0;
			for (int i = 1; i <= n; i++) {
				//	printf("%d ", dist[i]);
			}
			//	printf("\n");
			for (int i = 1; i <= n; i++) {
				if (dist[i] != 0x3f3f3f3f)
					if (num[dist[i]] == 1) {
						ans++;
						//	printf("%d ", i);
					}
			}
		}
		printf("%lld", ans);
	}
	return 0;
}