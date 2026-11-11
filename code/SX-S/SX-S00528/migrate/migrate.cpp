#include <bits/stdc++.h>
using namespace std;
#define MAXN 310
bool flag[MAXN][MAXN], vis[MAXN][MAXN], ard[MAXN];
int c, t, n, top;
long long  x[MAXN], f[MAXN][MAXN], d, ans;



void init() {
	ans = 0;
	memset(flag, 0, sizeof(flag));
	memset(vis, 0, sizeof(vis));
	memset(x, 0, sizeof(x));
	memset(f, 0, sizeof(f));
	memset(ard, 0, sizeof(ard));
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x[i]);
	}
//	printf("Init_OK\n");
}

void dfs(int k) {
	ard[k] == true;
//	printf("dfs%d\n", k);
	for (int i = k + 1; x[i] - x[k] <= d && i <= n; i++) {
		top = max(top, i);
		vis[k][i] = true;
		if (!ard[i])
			dfs(i);
	}
	return;
}

long long dp(int u, int v) {
//	printf("dp %d %d\n", u, v);
	if (flag[u][v])
		return f[u][v];


	flag[u][v] = true;

	if (vis[u][v])
		return f[u][v] = 1;

	for (int k = u + 1; k < v && x[k] - x[u] <= d; k++) {
		if (dp(u, k) > 2 && dp(u, k) > 0 || dp(k, v) > 2 && dp(u, k) > 0 || f[u][v] > 2) {
			f[u][v] = 3;
//			printf("Over %d %d\n", u, v);
		} else {
			f[u][v] += dp(u, k) * dp(k, v);
		}
	}
//	printf("f%d %d  %lld\n", u, v, f[u][v]);
	if (f[u][v] == 2)
		ans++;
	return f[u][v];
}


int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	if (c > 10)
		return 0;
	while (t--) {
		init();
		top = 0;
		while (++top <= n) {
			dfs(top);
			for (int i = 1; i <= top; i++)
				for (int j = i + 1; j <= top; j++) {
					dp(i, j);
				}
		}

//		printf("%d ", flag[1][4]);
		printf("%lld\n", ans);
	}
	return 0;
}
