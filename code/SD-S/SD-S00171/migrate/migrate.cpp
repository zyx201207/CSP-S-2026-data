#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5011;
int T, n, D, a[N], d[N], w[N];
struct edge {
	int to, nxt;
} e[2 * N * N];
int hd[N], cnt;
void ade(int u, int v) {
	e[++cnt].to = v;
	e[cnt].nxt = hd[u];
	hd[u] = cnt;
}
struct node {
	int id, val;
};
queue<node> q;

signed main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf ("%lld%lld", &T, &T);
	while (T--) {
		scanf ("%lld%lld", &n, &D);
		cnt = 0;
		for (int i = 1; i <= n; i++)
			hd[i] = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%lld", &a[i]);
			for (int j = 1; j < i; j++)
				if (a[i] - a[j] <= D) {
					ade(i, j);
					ade(j, i);
				}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				d[j] = 1e18, w[j] = 0;
			d[i] = 0, w[i] = 1;
			while (!q.empty())
				q.pop();
			q.push({i, 0});
			while (!q.empty()) {
				node x = q.front();
				q.pop();
				if (x.val > d[x.id])
					continue;
				int u = x.id;
				for (int j = hd[u]; j; j = e[j].nxt) {
					int v = e[j].to;
					if (d[v] > d[u] + 1) {
						d[v] = d[u] + 1;
						w[v] = w[u];
						q.push({v, d[v]});
					}
					else if (d[v] == d[u] + 1)
						w[v] += w[u];
				}
			}
			for (int j = 1; j <= n; j++)
				if (w[j] == 2)
					ans++;
		}
		printf ("%lld\n", ans >> 1);
	}
	return 0;
}

