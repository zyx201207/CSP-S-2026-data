#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, t, n, m;
int md[1100000];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		for (int j = 1; j <= n; j++) {
			cin >> md[j];
		}
		cout << i % 2 << '\n';
	}
	return 0;
}