#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * f;
}
const int maxn = 2e6 + 10;
int c, t, n, d, x[maxn];
int ans, cnt;

void dfs(int xb, int dis, int l, int r) {
	if (xb == r) {
		if (dis == ans) {
			cnt ++;
		}
		if (dis < ans) {
			cnt = 1;
			ans = dis;
		}
		return ;
	}
	for (int i = xb + 1; i <= r; i ++) {
		if (x[i] - x[xb] <= d) {
			dfs(i, dis + 1, l, r);
		}
	}
}

void solve1() {
	while (t --) {
		n = (int)read();
		d = (int)read();
		for (int i = 1; i <= n; i ++) {
			x[i] = (int)read();
		}
		int res = 0;
		for (int l = 1; l <= n; l ++) {
			for (int r = l + 1; r <= n; r ++) {
				ans = 1e9;
				cnt = 0;
				dfs(l, 0, l, r);
				if (cnt == 2) res ++;
			}
		}
		printf("%d\n", res);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = (int)read();
	t = (int)read();
	if (c <= 2) {
		solve1();
	}
}
