#include <bits/stdc++.h>
using namespace std;
const int M = 5e5+10;
int c, n, m, d, q;
int w[M], k[510], a[510][M / 10], t[510][M / 10];
int v[M];
int num_edge = 0, head[M];

struct str {
	int from, to, dis;
	int next;
} tu[1000010];

void add_edge(int x, int y, int di) {
	num_edge++;
	tu[num_edge].from = x;
	tu[num_edge].to = y;
	tu[num_edge].dis = di;
	tu[num_edge].next = head[x];
	head[x] = num_edge;
}



long long ans, mina = LLONG_MAX;

void dfs(int x, int y) {
	if (x == y) {
		mina = min(mina, ans);
		return;
	}
	for (int i = head[x]; i != 0; i = tu[i].next) {
		if (v[tu[i].to])
			continue;
		ans += tu[i].dis;
		v[tu[i].to] = 1;
		dfs(tu[i].to, y);
		v[tu[i].to] = 0;
		ans -= tu[i].dis;
	}
}

void slo1() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			for (int kk = j + 1; kk <= k[i]; kk++) {
				add_edge(a[i][j], a[i][kk], t[i][j] + t[i][kk]);
				add_edge(a[i][kk], a[i][j], t[i][j] + t[i][kk]);
			}
		}
	}
//	sort(tu + 1, tu + num_edge + 1, comp);
	int x, y;
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &x, &y);
		ans = w[x] + w[y];
		mina = LLONG_MAX;
		dfs(x, y);
		printf("%lld\n", mina);
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++)
			scanf("%d%d", &a[i][j], &t[i][j]);
	}
	slo1();
	return 0;
}//16.58 44->??
//差点多测不清空了