#include <bits/stdc++.h>
using namespace std;

typedef long long llong;
const int N = 2000005;
int c, T, n, r[N];
llong d, a[N], tot;
void dfs(int x, int t, int ma, int s) {
	if (tot > 2)
		return;
	if (s == ma) {
		tot++;
		return;
	}
	if (s + 1 == ma) {
		if (x + r[x] < t)
			return;
		dfs(t, t, ma, s + 1);
	}
	else
		for (int i = 1; i <= r[x]; i++) {
			if (tot > 2)
				return; 
			dfs(x + i, t, ma, s + 1);
		}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while (T--) {
		scanf("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		int p = 1;
		for (int i = 1; i <= n; i++) {
			while (p < n && a[p + 1] - a[i] <= d)
				p++;
			r[i] = p - i;
		}
		llong ans = 0;
		for (int i = 1; i <= n; i++) {
			int sum = 0, p = i;
			for (int j = i + 1; j <= n; j++) {
				if (r[p] <= 0) break;
				tot = 0;
				dfs(i, j, sum + 1, 0);
				if (tot == 2)
					ans++;
				if (j - p == r[p]) {
					p += r[p];
					sum++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
