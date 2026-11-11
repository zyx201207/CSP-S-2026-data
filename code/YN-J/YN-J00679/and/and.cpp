#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, f[N], vis[N], maxx = 0;

void dfs(int wei, int an ) {
	if (wei > m) {
		maxx = max(maxx, an);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0 ) {
			vis[i] = 1;
			if (wei == 1) {
				dfs(2, f[i]);
			} else
				dfs(wei + 1, f[i]& an );
			vis[i] = 0;
		}
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	dfs(1, 0);
	cout << maxx;
	return 0;
}
