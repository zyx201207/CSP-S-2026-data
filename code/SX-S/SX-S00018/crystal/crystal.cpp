#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005], a1[500005];
int ans = 0, n, m;

void dfs(int x, int step) {
	a1[step] = a[x];
	int y = (a1[1] + a1[step]) / 2;
	int z = 0;
	for (int i = 1; i <= step; i++) {
		if (y > a1[i])
			z += y - a1[i];
		else
			z += a[i] - y;
	}
	if (z > m) {
		if (step > ans)
			ans = step - 1;
		return;
	}
	for (int i = x; i <= n; i++) {
		dfs(i + 1, step + 1);
		a1[step] = 0;
	}
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 1);
	cout << ans;
	return 0;
}