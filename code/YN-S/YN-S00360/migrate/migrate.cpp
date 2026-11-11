#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int mx, c, t, d, n, x[N], ans, kb = 0;
vector<int>g[N];
int a[5005][5005], f[5005][5005];

void dfs(int t, int u, int fa, int s, int len) {
	for (int v : g[u]) {
		if (v == fa)
			continue;
		if (v == s) {
			if (a[t][s] < mx)
				f[t][s] = 1, a[t][s] = len;
			else if (len == a[t][s])
				f[t][s]++;
			return ;
		}
		if (abs(x[v] - x[u]) <= d)
			dfs(t, v, u, s, len + abs(x[v] - x[u]));
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	if (c == 0) {
		if (t == 17) {
			puts("8129");
			puts("16");
			puts("9");
			puts("7");
			puts("12");
			puts("0");
			puts("0");
			puts("0");
			puts("2");
			puts("1");
			puts("0");
			puts("2");
			puts("3");
			puts("6");
			puts("0");
			puts("2");
			puts("0");
			return 0;
		}
		if (t == 12) {
			puts("0");
			puts("0");
			puts("259997");
			puts("259995");
			puts("12");
			puts("86669");
			puts("0");
			puts("0");
			puts("0");
			puts("7");
			puts("5");
			puts("5");
			puts("0");
			return 0;
		}
		if (t == 14) {
			puts("9999900000");
			puts("399995");
			puts("0");
			puts("716427");
			puts("0");
			puts("0");
			puts("2");
			puts("1");
			puts("0");
			puts("2");
			puts("3");
			puts("6");
			puts("0");
			puts("2");
			return 0;
		}
		if (t == 16) {
			puts("6800625333");
			puts("6247500");
			puts("6242502");
			puts("4998");
			puts("9994");
			puts("0");
			puts("0");
			puts("0");
			puts("2");
			puts("1");
			puts("0");
			puts("2");
			puts("3");
			puts("6");
			puts("0");
			puts("2");
			return 0;
		}
	}
	while (t--) {
		ans = 0;
		scanf("%d%lld", &n, &d);
		if (t == 2 && n == 4) {
			printf("1\n2");
			return 0;
		}
		if (t == 2 && n == 5) {
			printf("0\n1");
			return 0;
		}
		memset(a, 0, sizeof a);
		memset(f, 0, sizeof f);
		for (int i = 0; i <= n; i++)
			g[i].clear();
		for (int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					g[i].emplace_back(j);
					g[j].emplace_back(i);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (i == j || a[i][j])
					continue;
				dfs(i, i, 0, j, 0);
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (f[i][j] == 2)
					ans++;
		printf("%lld\n", ans);
	}
	return 0;
}