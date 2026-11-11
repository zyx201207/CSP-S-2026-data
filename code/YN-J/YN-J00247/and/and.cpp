#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m;
int f[N], a[N];
map<int, int>v;
int ans;

void dfs(int x, int y) {
	if (x == n + 1) {
		int res = f[1];
		for (int i = 2; i <= m; i++)
			res = (res & f[i]);
		ans = max(ans, res);
		return ;
	}
	for (int i = y + 1; i <= n; i++) {
		if (!v[i]) {
			f[x] = a[i];
			v[i] = 1;
			dfs(x + 1, y);
			v[i] = 0;
		}
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1) {
		sort(a + 1, a + n + 1);
		cout << a[n];
		return 0;
	}
	if (m == 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j)
					ans = max(ans, (a[i] & a[j]));
			}
		}
		cout << ans;
		return 0;
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}
