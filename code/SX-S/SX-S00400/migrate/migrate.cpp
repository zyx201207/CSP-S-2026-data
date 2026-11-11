#include <bits/stdc++.h>
using namespace std;
int c, t, n;
long long x[2000001], cnt, d;

void dfs(int a, int b, int wz) {
	if (wz == b) {
		cnt++;
	}
	for (int i = a; i <= n; i++) {
		if (x[i] - x[wz] <= d) {
			dfs(a, b, i);
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
		long long tot = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i < n; i++) {
			cnt = 0;
			for (int j = i + 1; j <= n; j++) {
				dfs(i, j, i);
				if (cnt == 2) {
					tot++;
				}
			}
		}
		cout << tot << '\n';
	}
	return 0;
}
