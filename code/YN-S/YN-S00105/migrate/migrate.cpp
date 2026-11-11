#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e6 + 15;
int c, T, n, d;
int a[maxn];
int cnt = 0, ans = 2e9;
int ansd =  0;
bool vis[maxn];

void dfs (int x, int step, int y) {
	if (x == y) {
		if (step < ans)
			cnt = 0, ans = step;
		if (step == ans)
			cnt ++;
		return;
	}
	for (int i = x + 1; i <= n; i++) {
		if (a[i] - a[x] <= d) {
			dfs (i, step + 1, y);
		}
	}
}

signed main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T --) {
		ansd = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			scanf ("%lld", &a[i]);
		if (n >= 1e5) {
			if (a[2] - a[1] > d)
				cout << 0;
			else {
				cout << n * (n - 1) / 2;
			}
			continue;
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <= n; j ++) {
				cnt = 0;
				ans = 2e9;
				dfs (i, 0, j);
				ansd += (cnt == 2);
			}
		}
		printf ("%lld\n", ansd);
	}
	return 0;
}