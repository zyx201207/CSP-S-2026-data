#include <bits/stdc++.h>
using namespace std;

int a[2000000], ans[2000000] = {0}, z[2000000], d, n;

void dfs(int k, int dep) {
	if (k > n) {
		return;
	}
	for (int i = k + 1; i <= n; i++) {
		int data = a[i] - a[k];
		if (data <= d) {
			if ((dep + 1) == z[i])
				ans[i] += ans[k];
			if ((dep + 1) < z[i]) {
				ans[i] = ans[k];
				z[i] = dep + 1;
			}
			dfs(i, dep + 1);
		} else {
			return ;
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			ans[i] = 0;
			z[i] = 0x3f3f3f;
		}
		ans[1] = 1;
		dfs(1, 0);
		long long sun = 0;
		for (int i = 1; i <= n; i++) {
			if (ans[i] == 2) {
				int l = 1;
				for (int h = i; h <= n; h++) {
					l *= 2;
				}
				sun += l / 2;
			}
		}
		cout << sun << endl;
	}
	return 0;
}