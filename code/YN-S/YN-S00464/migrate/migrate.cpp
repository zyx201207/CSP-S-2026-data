#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int a[N], diff[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, T;
	string s, s1, s2;
	cin >> c >> T;
	if (c == 0) {
		while (T--) {
			int n, m;
			cin >> n >> m;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
				diff[i] = a[i] - a[i - 1];
			}
			if (n == 1) {
				cout << 0 << "\n";
			} else if (diff[2] > m) {
				cout << 0 << "\n";
			} else {
				int cj = m * 2;
				int sl = ceil(n * 1.0 / cj);
				cout << sl << "\n";
			}
		}
	}
	return 0;
}