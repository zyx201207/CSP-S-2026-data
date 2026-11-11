#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
#define int long long
int a[N];
bool vis[N];
int n, m, b[N];
int ans;

void dfs(int x) {
	if (x == m + 1) {
		int c = b[1];
		for (int i = 2; i <= m; i++) {
			c &= b[i];
		}
		ans = max(ans, c);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		vis[i] = 1;
		b[x] = a[i];
		dfs(x + 1);
		vis[i] = 0;
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	if (n <= 20) {
		dfs(1);
		cout << ans;
	} else
		cout << maxx;

	return 0;
}