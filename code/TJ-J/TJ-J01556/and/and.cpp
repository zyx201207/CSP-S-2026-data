#include <bits/stdc++.h>
using namespace std;
int n, m, wy;
int a[600005], v[300005], ans;

void dfs(int w, int wz) {
	if (wz > m) {
		wy = v[1];
		for (int i = 2; i <= m; i++) {
			wy = wy & v[i];
		}
		ans = max(ans, wy);
		return ;
	}
	for (int i = w; i <= n - (m - wz) + 1; i++) {
		v[wz] = a[i];
		dfs(i + 1, wz + 1);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 1);
	cout << ans;
	return 0;
}