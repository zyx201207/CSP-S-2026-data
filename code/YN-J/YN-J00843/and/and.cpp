#include <bits/stdc++.h>
using namespace std;

imt n, m, re[200005], st[200005], c[200005], ans[200005], maxn;
void dfs(int x, int y) {
	if (x > m) {
		while (i >= m) {
			int a = 0;

			for (int i = 1; i <= m; i++) {

				ans[a] += c[i];
			}

			a++;

			for (int i = 1; i <= a; i++) {

				maxn = max(maxn, ans[i];
			}
		}

		return;
	}

	for (int i = y; i <= n; i++) {

		if (st[i] == 0) {
			st[i] = 1;
			c[x] = re[i];
			dfs(x +, y + 1);
			st[i] = 0;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m

	for (int i = 1; i <= n; i++) {

		cin >> re[i];
	}

	dfs(1, 1)
	cout << maxn;
	return 0;
}