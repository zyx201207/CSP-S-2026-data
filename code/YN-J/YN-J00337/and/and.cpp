#include <bits/stdc++.h>
using namespace std;
int a[1000050], a2 = -10000, n, m;

void dfs(int point, int cnt, long long ans) {
	if (ans == 0) {
		ans = a[point];
	}

	if (ans > a2) {
		if (cnt == m) {
			a2 = ans;
			return;
		}
	}

	if (point > n) {
		return;
	}

	if (cnt >= m) {
		return;
	}

	dfs(point + 1, cnt, ans);
	dfs(point + 1, cnt + 1, ans & a[point]);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	dfs(1, 0, 0);
	cout << a2;
	return 0;
}
