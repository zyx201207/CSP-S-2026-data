#include <bits/stdc++.h>
using namespace std;
int n, m, ans = INT_MIN;
int a[200010];

void dfs(int idx, int num, int da) {
	if (num == m) {
		ans = max(ans, da);
		return;
	}
	for (int i = idx; i <= n; i++) {
		dfs(i + 1, num + 1, da & a[i]);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, INT_MAX);
	cout << ans;
	return 0;
}