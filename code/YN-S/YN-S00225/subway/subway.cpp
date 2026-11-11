#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;











int c, n, m, d, q, w[500100] = {0}, rs[510][500100] = {0}, cnt = 0, head[500100] = {0}, F;
long long L = 0, mi;



struct node {
	int n, t, s;
} e[500100];




void add(int u, int v, int s) {
	cnt++;
	e[cnt].n = head[u];
	e[cnt].t = v;
	e[cnt].s = s;
	head[cnt] = u;
}





void dfs(int u, int fa, int V) {
	if (u == V) {
		if (mi > L) {
			mi = L;
		}
	}
	for (int i = head[u]; i; i = e[i].n) {
		int v = e[i].t;
		if (e[i].s != e[fa].s) {
			L += rs[e[fa].s][e[i].t] + rs[e[v].s][e[i].t];
			F = 1;
		}
		dfs(v, u, V);
		if (F) {
			L -= rs[e[fa].s][e[i].t] + rs[e[v].s][e[i].t];
		}
	}
}





int main(void) {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 0; i < m; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		int u, v, k;
		scanf("%d", &k);
		scanf("%d%d", &u, &rs[i][u]);
		for (int j = 1; j < k; j++) {
			scanf("%d%d", &v, &rs[i][v]);
			add(u, v, i);
			add(v, u, i);
		}
	}
	e[0].s = -1;
	for (int i = 0; i < q; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		L = w[u] + w[i];
		mi = 0xfffffffffffffff;
		dfs(u, 0, v);
		printf("%d\n", mi);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}







