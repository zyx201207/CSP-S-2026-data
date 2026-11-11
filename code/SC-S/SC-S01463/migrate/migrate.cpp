#include <cstdio>

using namespace std;
int c, t, n;
long long d;
long long x[2000005];
long long ans;
int minl, s;
int dfs1(int p, int g, int l) {
	if (p == g) {
		return l;
	}
	for (int i = g; i >= p + 1; i--) {
		if (x[i] - x[p] <= d) {
			return dfs1(i, g, l + 1);
		}
	}
}
void dfs2(int p, int g, int l) {
	if (p == g) {
		if (l <= minl) {
			minl = l;
			s++;
		}
		return;
	}
	if (s > 2 || l >= minl) return;
	for (int i = g; i >= p + 1; i--) {
		if (x[i] - x[p] <= d) {
			dfs2(i, g, l + 1);
			if (s > 2) return;
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	if (c == 11 || c == 12) {
		while (t--) {
			scanf("%d%lld", &n, &d);
			for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
			if (n == 1) {
				printf("0\n");
				continue;
			}
			ans = n * (n - 1) / 2;
			long long y = d / (x[2] - x[1]);
			for (int i = 1; i < n; i++) {
				ans -= (n - i) / y;
			}
			printf("%lld\n", ans);
		}
		return 0;
	}
	while (t--) {
		scanf("%d%lld", &n, &d);
		ans = 0;
		for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				minl = dfs1(i, j, 0);
				//printf("%d\n", minl);
				s = 0;
				dfs2(i, j, 0);
				if (s == 2) ans++;
			}
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}