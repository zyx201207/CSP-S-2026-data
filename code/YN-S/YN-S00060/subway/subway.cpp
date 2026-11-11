#include <bits/stdc++.h>
using namespace std;
const int N = 6E5;
int c, n, m, d, q;
int w[N];

struct node {
	int k;
	int a[N], t[N];
} x[N];
int xy[200][200];
int p[4], ans;
bool ux[4];

void calc(int id, int xx, int yx) {
	if (id == 0 && xy[xx][yx]) {
		int ux = 0, uy = 0;
		ans = min(ans, w[xx] + w[yx] + x[xx].t[xy[xx][yx]][xx]);
		//
	}
	if (id > 3)
		return;
	for (int i = 1; i <= m; i++) {
		if (ux[i])
			continue;
		ux[i] = 1;
		p[id] = i;
		calc(id + 1, xx, yx);
		ux[i] = 0;
	}
}

void solve() {
	int xx, yx;
	scanf("%d%d", &xx, &yx);
	ans = (1 << 30);
	calc(1, xx, yx);
	printf("%d\n", ans);
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	memset(xy, 255, sizeof(xy));
	memset(ux, 0, sizeof(ux));
	for (int i = 1; i <= m; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i].k);
		for (int j = 1; j <= x[i].k; j++)
			scanf("%d%d", &x[i].a[j], &x[i].t[j]);
		for (int j = 1; j <= x[i].k; j++)
			for (int l = 1; l <= x[i].k; l++) {
				xy[x[i].a[j]][x[i].a[l]] = i;
				xy[x[i].a[l]][x[i].a[j]] = i;
			}
	}
	for (int i = 1; i <= q; i++)
		solve();
	return 0;
}