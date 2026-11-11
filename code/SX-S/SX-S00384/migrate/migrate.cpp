#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;

struct Edge {
	int v, w, nxt;
} e[N];
int c, T, n, m;
int a[N];
int f[N];
int cnt;

void insert(int u, int v, int w) {
	e[++cnt] = {v, w, f[u]};
	f[u] = cnt
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
	}
}//–¥≤ªÕÍ¡À
//we don't have enough time to complain it
//i offer a bad message disappointedly
//i can't find the hope which can help us success