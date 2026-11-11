#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000026;
long long dao[MAXN], d, n, t, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> dao[MAXN];
		}
		long long cha = dao[1] - dao[0];
		if (d >= 2 * cha && d < 3 * cha) {
			cout << n - 3;
		} else {
			cout << 0;
		}
		cout << endl;
	}
	return 0;
}
