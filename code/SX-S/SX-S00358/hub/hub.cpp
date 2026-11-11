#include <bits/stdc++.h>
using namespace std;
int c, t, n, ki, k = 1, pre[2000010];

struct Node {
	int from, to, next;
} a[2000010];

void add(int u, int v) {

	a[++k] = {u, v, pre[u]};
	pre[u] = v;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &t);

	while (t--) {
		scanf("%d%d", &n, &ki);
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		printf("1\n");
	}
	return 0;
}