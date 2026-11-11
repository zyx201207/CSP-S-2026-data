#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, ans = 0;
long long a[2000009];
map<pair<int, int>, int>mp;

void dfs(int x, int chu, int num) {
	for (int i = x + 1; i <= n; i++) {
		if (num + a[i] - a[x] <= d) {
			if (!mp[ {chu, i}]) mp[ {chu, i}] = INT_MAX;
			if (mp[ {chu, i}] == num + 1) {
				ans++;
				continue;
			}
			int num2 = mp[ {chu, i}];
			mp[ {chu, i}] = min(num2, num + 1);
			dfs(i, chu, num + 1);
		} else
			return;
	}
	return ;
}

int main() {
	//freopen("migrate.in", "r", stdin);
	//freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		mp.clear();
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			dfs(i, i, 0);
		}
		cout << ans << "\n";
	}
	return 0;
}
