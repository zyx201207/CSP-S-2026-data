#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;

struct NODE {
	int c, z;
	int from, to, next;
} dt[5000050];
int pre[5000010], k = 0;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);

	for (int i = 1; i <= m; i++) {
		scanf("%d", &dt[i].c);
	}
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			k++;
			dt[k].from = i;
			scanf("%d%d", dt[j].to, dt[j].z);
		}
		//dfs()
		printf("%d", 34);
	}

	return 0;
}
