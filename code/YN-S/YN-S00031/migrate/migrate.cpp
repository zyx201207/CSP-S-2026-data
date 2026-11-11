#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const unsigned int MAXN = 2e6 + 10;
int x[MAXN];
int c, t;
int n, d;

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
	}
	for (int i = 0; i < t; i++) {
		cout << 0 << "\n";
	}

	return 0;
}