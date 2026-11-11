#include <bits/stdc++.h>
using namespace std;
long long x[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n, d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		cout << d / 2 << endl;
	}
	return 0;

}
