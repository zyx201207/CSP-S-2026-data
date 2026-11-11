#include <bits/stdc++.h>
using namespace std;
int c, n, m, dd, q, ki, w[500010], ans, pre[510], k = 1, d[500010];
bool f[500010];

struct Node {
	int from, to, next, len;
} a[510];

void add(int u, int v, int len) {
	a[++k] = {u, v, pre[u], len};
	pre[u] = v;
}

void dijstra(int x) {
	memset(f, false, sizeof(f));
	memset(d, 0x3f, sizeof(d));
	d[x] = 0;
	f[x] = true;
	int mi = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (f[j] == false && d[j] < d[mi]) {
				mi = j;
			}
		}
		f[mi] = true;
		for (int j = pre[mi]; j != 0; j = a[j].next) {
			if (f[j] == false && d[mi] + a[j].len < d[j]) {
				d[j] = d[mi] + a[j].len;
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &dd, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		int u, v, ui, vi;
		scanf("%d%d%d%d%d", &ki, &u, &ui, &v, &vi);
		add(u, v, ui);
		add(u, v, vi);
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		dijstra(x);
		printf("%d\n", d[y]);
	}
	return 0;
}
