#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 11;
int n, m, Q, w[N], d[2011][2011];
bool vis[N];
struct edge {
	int to, nxt, val;
} e[N << 1];
int hd[N], cnt;
void ade(int u, int v, int val) {
	e[++cnt].to = v;
	e[cnt].val = val;
	e[cnt].nxt = hd[u];
	hd[u] = cnt;
}
struct node {
	int id, val;
};
priority_queue<node> q;
bool operator < (node x, node y) {
	return x.val > y.val;
}

signed main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf ("%lld%lld%lld%lld%lld", &n, &n, &m, &Q, &Q);
	for (int i = 1; i <= m; i++)
		scanf ("%lld", &w[i]);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		scanf ("%lld", &k);
		sum += k;
		while(k--) {
			int a, t;
			scanf ("%lld%lld", &a, &t);
			ade(m + i, a, t);
			ade(a, m + i, t);
		}
	}
	if (sum <= 1e3) {
		for (int i = 0; i <= 2e3; i++)
			for (int j = 0; j <= 2e3; j++)
				d[i][j] = 1e18;
		for (int i = 1; i <= m; i++) {
			d[i][i] = 0;
			q.push({i, 0});
			for (int j = 1; j <= m + n + 1; j++)
				vis[j] = 0;
			while (!q.empty()) {
				int x = q.top().id;
				q.pop();
				if (vis[x])
					continue;
				vis[x] = 1;
				for (int j = hd[x]; j; j = e[j].nxt) {
					int v = e[j].to;
					if (!vis[v] && d[i][v] > d[i][x] + e[j].val) {
						d[i][v] = d[i][x] + e[j].val;
						q.push({v, d[i][v]});
					}
				}
			}
		}
		while (Q--) {
			int u, v;
			scanf ("%lld%lld", &u, &v);
			printf ("%lld\n", w[u] + w[v] + d[u][v]);
		}
	}
	else {
		int T = e[1].val;
		queue<node> qq;
		while (Q--) {
			int u, v;
			scanf ("%lld%lld", &u, &v);
			for (int i = 1; i <= m + n + 1; i++)
				vis[i] = 0;
			while (!qq.empty())
				qq.pop();
			qq.push({u, 0});
			while (!qq.empty()) {
				node x = qq.front();
				if (x.id == v) {
					printf ("%lld\n", w[u] + w[v] + x.val * T);
					break;
				}
				qq.pop();
				if (vis[x.id])
					continue;
				vis[x.id] = 1;
				for (int j = hd[x.id]; j; j = e[j].nxt) {
					int v = e[j].to;
					if (!vis[v])
						qq.push({v, x.val + 1});
				}
			}
		}
	}
	return 0;
}
