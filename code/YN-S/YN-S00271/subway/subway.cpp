#include <bits/stdc++.h>
using namespace std;

const int maxn = 510, maxm = 5e5 + 10 + maxn, inf = 1e9;
int c, n, m, d, q;
long long w[maxm];
struct Edge {
	int to;
	long long weight;
	int next;
} e[maxm];
int len, head[maxm];

void Insert(int u, int v, long long w) {
	len++;
	e[len] = {v, w, head[u]};
	head[u] = len;
}

long long dis[maxn];
stack<int> st;
bool vis[maxn];
void Dijkstra(int s) {
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	dis[s] = 0;
	st.push(s);
	vis[s] = 1;
	while (!st.empty()) {
		int u = st.top();
		st.pop();
		for (int i = head[u]; i; i = e[i].next) {
			int v = e[i].to, w = e[i].weight;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (vis[v] == 0) {
					vis[v] == 1;
					st.push(v);
				}
			}
		}
	}
}

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		int u = m + i;
		for (int j = 1; j <= k; j++) {
			int v;
			long long w;
			scanf("%d %lld", &v, &w);
			Insert(u, v, w);
			Insert(v, u, w);
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		Dijkstra(x);
		//danshiwozhendewangji"duoyuanzuiduanlu"zenmexiele
		printf("%lld", dis[y] + w[x] + w[y]);
	}

	return 0;
}