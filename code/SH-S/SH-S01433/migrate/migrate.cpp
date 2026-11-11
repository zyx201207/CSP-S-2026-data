#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2e6+6;
int c, t, n, d, land[MAXN];

int head[MAXN], tot;
struct Edge{
	int to, nxt;
}edges[MAXN];
void add_edge(int u, int v) {
	edges[++tot].nxt = head[u];
	edges[tot].to = v;
	head[u] = tot;
} 

bool vis[MAXN], mind[MAXN], minnum[MAXN];
int ans = 0;
void dfs (int u, int fa, int w) {
	printf("%d to %d weigh %d, compare with %d\n", fa, u, w, mind[u]);
	if (mind[u] > w) {
		mind[u] = w, minnum[u] = 1;
	} else if (mind[u] == w){
		minnum[u]++;		
	}
	for (int i = head[u]; i; i = edges[i].nxt) {
		int v = edges[i].to;
		if (!vis[v]) {
			vis[v] = 1;
			dfs(v, u, w + 1);
		}
	}
} 

void init() {
	n = d = tot = ans = 0;
	memset(land, 0, sizeof(land));
	memset(edges, 0, sizeof(edges));
	memset(head, 0, sizeof(head));
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &c, &t);
	while(t--) {
		init();
		scanf("%lld %lld", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &land[i]);
		}
		for (int i = 1; i <= n; i++) {
			auto l = lower_bound(land + 1, land + n + 1, land[i] - d) - land, r = upper_bound(land + 1, land + n + 1, land[i] + d) - land - 1;
//			printf("island %d where x=%d can reach from %d to %d\n", i, land[i], l, r);
			for (int j = l; j <= r; j++) {
				add_edge(i, j);
			}
		}
		for (int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof(vis));
			memset(minnum, 0, sizeof(minnum));
			memset(mind, 0x7f, sizeof(mind));
			vis[i] = 1;
			dfs(i, 0, 0);
			vis[i] = 0;
			for (int j = 1; j <= n; j++) {
				if (minnum[j] == 2) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
