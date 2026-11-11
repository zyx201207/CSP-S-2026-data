#include <bits/stdc++.h>
using namespace std;

int w[100005];
int lj[100005][100005];
int kk[100005];

int cha(int x, int y, int sum) {
	for (int i = 0; i < kk[x] ; i++) {
		int v = lj[x][i];
		if (v == y)
			return sum;
		cha(lj[x][i], y, sum + 1);
	}
	return sum;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, p;
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &p);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	int k;
	bool b = 1;
	int t[100005] = {0};
	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		scanf("%d%d", &a, &t[1]);
		kk[a] = k;
		int y;
		for (int j = 2; j <= k * 2; j++) {
			scanf("%d%d", &y, &t[j]);
			lj[a][j - 1] = y;
			if (t[j] != t[j - 1])
				b = 0;
		}
	}
	int x, y;
	for (int i = 1; i <= p; i++) {
		scanf("%d%d", &x, &y);
		if (b == 1) {
			printf("%d", t[1] * 2 * cha(x, y, 1) + w[x] + w[y]);
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}