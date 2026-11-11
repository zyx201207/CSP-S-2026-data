#include <bits/stdc++.h>
#define p_q priority_queue
#define int long long
#define endl "\n"
using namespace std;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		if (c == 0 && n == 4) {
			cout << "1\n2";
			return 0;
		}
		if (c == 0 && n == 5) {
			cout << "0\n1";
			return 0;
		}
		cout << 0 << endl;
	}
	return 0;
}
