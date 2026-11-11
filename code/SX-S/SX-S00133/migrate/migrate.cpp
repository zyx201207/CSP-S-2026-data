#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long c, t, xx;
long long x[500010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n, d;
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> x[i];
		}
		xx = x[2] - x[1];
		if (xx > d)
			cout << 0 << endl;
		else
			cout << n - 3 << endl;
	}
	return 0;
}
