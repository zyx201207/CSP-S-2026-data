#include <bits/stdc++.h>
#define int long long
using  namespace std;
int c, t;
int n, d;
const int N = 1e6;
int a[N];

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= d; i++) {
			cin >> a[i];
		}
		for (int i = LLONG_MIN; i <= LLONG_MAX; i++) {
			cout << i << '\n';
		}
	}
	return 0;
}
